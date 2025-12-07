# Ruby 0.49 Cosmopolitan Port

This directory contains Ruby 0.49 ported to build with [Cosmopolitan Libc](https://github.com/jart/cosmopolitan), producing a single Actually Portable Executable (APE) that runs on multiple platforms.

## Supported Platforms

The resulting `ruby.com` binary runs natively on:
- Linux x86_64
- Linux ARM64
- macOS x86_64
- macOS ARM64
- Windows x86_64
- FreeBSD x86_64

## Building

### Prerequisites

1. Download the Cosmopolitan toolchain:
```sh
mkdir -p ../toolchain && cd ../toolchain
curl -sLO https://cosmo.zip/pub/cosmocc/cosmocc.zip
unzip cosmocc.zip
cd ../cosmo
```

2. Install `bison` (for parsing parse.y):
```sh
# macOS
brew install bison

# Linux
sudo apt-get install bison
```

### Build

```sh
make -f Makefile.cosmo
```

This produces `ruby.com`, a ~1.6MB universal binary.

### Test

```sh
./ruby.com -v
# => ruby - version 0.49 (18 Jul 94)

echo '"Hello".print' | ./ruby.com
# => Hello
```

## Changes from `fixed/`

All Cosmopolitan-specific changes are guarded with `#ifdef __COSMOPOLITAN__` or similar preprocessor conditionals, marked with `__r49_cosmo` comments.

### `io.c`

**Issue:** Cosmopolitan uses an opaque `FILE` type; internal fields like `_cnt`, `_r`, `_IO_read_ptr` are not accessible.

**Fix:** Added Cosmopolitan case for `READ_PENDING` macro that conservatively returns 0 (no pending data). This disables the buffered-data optimization in `select()` but doesn't affect correctness.

```c
#ifdef __COSMOPOLITAN__
#   define READ_PENDING(fp) (0)
#elif defined(__linux__)
   // ... existing code
```

### `process.c`

**Issue:** Uses BSD signal functions (`sigblock`, `sigsetmask`, `sigmask`) which aren't available in Cosmopolitan's POSIX-focused libc.

**Fix:** Added inline compatibility shims that implement these functions using POSIX `sigprocmask()`:

```c
#ifdef __COSMOPOLITAN__
#define sigmask(sig) (1 << ((sig) - 1))
static inline int sigblock(int mask) { /* ... uses sigprocmask */ }
static inline int sigsetmask(int mask) { /* ... uses sigprocmask */ }
#endif
```

### `socket.c`

**Issue:** Unused `FILE f` variable declaration fails because `FILE` is opaque (incomplete type) in Cosmopolitan.

**Fix:** Conditionally exclude the unused variable:

```c
#ifndef __COSMOPOLITAN__
    FILE f;
#endif
```

### `dir.c`

**Issue:** Uses deprecated `getwd()` function which isn't available in Cosmopolitan.

**Fix:** Use `getcwd()` instead under Cosmopolitan:

```c
#ifdef __COSMOPOLITAN__
#include <errno.h>
// ... later in Fdir_getwd():
    if (getcwd(path, MAXPATHLEN) == NULL) {
        Fail(strerror(errno));
    }
#else
    // ... original getwd() code
#endif
```

### `dln.c`

**Issue:** `extern int errno;` declaration conflicts with Cosmopolitan where `errno` is defined as a macro.

**Fix:** Conditionally exclude the declaration:

```c
#ifndef __COSMOPOLITAN__
extern int errno;
#endif
```

### `Makefile.cosmo`

New Makefile that:
- Uses `cosmocc` compiler from the toolchain
- Defines `__COSMOPOLITAN__` for conditional compilation
- Disables DBM (`-UHAVE_NDBM_H`) and DLN (`-UUSE_DLN`) features
- Includes `dln.c` for `dln_find_file()` but excludes dynamic loading code

## Disabled Features

The following features are disabled in the Cosmopolitan build:

| Feature | Reason |
|---------|--------|
| DBM class | Requires `ndbm.h` which isn't portable |
| Dynamic loading (USE_DLN) | Requires `a.out.h` and platform-specific code |

## APE Loader

On modern systems (macOS 11+, Linux 5.4+, Windows 10+), the APE binary runs directly without any loader.

On older systems, you may need the APE loader:
```sh
# Install system-wide (Linux)
sudo sh -c "curl -s https://cosmo.zip/pub/cosmos/bin/ape-$(uname -m).elf > /usr/local/bin/ape"
sudo chmod +x /usr/local/bin/ape

# Run with explicit loader
./ape ./ruby.com -v
```

## File Size

| Build | Size |
|-------|------|
| Native (`fixed/ruby`) | ~200KB |
| Cosmopolitan (`ruby.com`) | ~1.6MB |

The larger size is due to Cosmopolitan bundling its portable libc and multi-platform support code.
