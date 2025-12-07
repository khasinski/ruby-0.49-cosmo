# AncientRuby

Run Ruby 0.49 (from 1994!) code from modern Ruby applications.

This gem bundles Ruby 0.49, the oldest extant version of Ruby, as a universal [Cosmopolitan](https://github.com/jart/cosmopolitan) binary that runs on Linux, macOS, Windows, and FreeBSD.

## Installation

Add this line to your application's Gemfile:

```ruby
gem 'ancient_ruby'
```

Or install it directly:

```bash
gem install ancient_ruby
```

## Usage

### From Ruby

```ruby
require 'ancient_ruby'

# Evaluate a string of Ruby 0.49 code
output = AncientRuby.eval('"Hello from 1994!".print')
puts output  # => Hello from 1994!

# Evaluate a file
output = AncientRuby.eval_file("path/to/script.rb")

# Pass arguments to a script
output = AncientRuby.eval_file("fizzbuzz.rb", "20")

# Get Ruby 0.49 version
puts AncientRuby.ruby049_version
# => ruby - version 0.49 (18 Jul 94)

# Get path to the binary
puts AncientRuby.binary_path
```

### From Command Line

The gem installs a `ruby-0.49` executable:

```bash
# Run a script
ruby-0.49 script.rb

# Check version
ruby-0.49 -v

# Interactive (reads from stdin)
echo '"Hello".print' | ruby-0.49
```

## Ruby 0.49 Syntax

Ruby 0.49 has some interesting differences from modern Ruby:

```ruby
# Constants use % instead of uppercase
%MAX = 100

# .print on any object
"Hello".print
42.print

# for loops (no .each yet!)
for i in 1..10
  i.print
end

# end tags
if condition then
  # ...
end if

# $ARGV instead of ARGV
$ARGV[0].print
```

## Supported Platforms

The bundled `ruby049` binary is an Actually Portable Executable (APE) that runs on:

- Linux x86_64 / ARM64
- macOS x86_64 / ARM64
- Windows x86_64
- FreeBSD x86_64

## License

MIT License. See [LICENSE.txt](LICENSE.txt).

The original Ruby 0.49 source code is Copyright (C) 1994 Yukihiro Matsumoto.
