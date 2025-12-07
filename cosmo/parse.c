/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     CLASS = 258,
     MODULE = 259,
     DEF = 260,
     FUNC = 261,
     UNDEF = 262,
     INCLUDE = 263,
     IF = 264,
     THEN = 265,
     ELSIF = 266,
     ELSE = 267,
     CASE = 268,
     WHEN = 269,
     UNLESS = 270,
     UNTIL = 271,
     WHILE = 272,
     FOR = 273,
     IN = 274,
     DO = 275,
     USING = 276,
     PROTECT = 277,
     RESQUE = 278,
     ENSURE = 279,
     END = 280,
     REDO = 281,
     BREAK = 282,
     CONTINUE = 283,
     RETURN = 284,
     YIELD = 285,
     SUPER = 286,
     RETRY = 287,
     SELF = 288,
     NIL = 289,
     IDENTIFIER = 290,
     GVAR = 291,
     IVAR = 292,
     CONSTANT = 293,
     INTEGER = 294,
     FLOAT = 295,
     STRING = 296,
     REGEXP = 297,
     UPLUS = 298,
     UMINUS = 299,
     POW = 300,
     CMP = 301,
     EQ = 302,
     NEQ = 303,
     GEQ = 304,
     LEQ = 305,
     AND = 306,
     OR = 307,
     MATCH = 308,
     NMATCH = 309,
     DOT2 = 310,
     DOT3 = 311,
     AREF = 312,
     ASET = 313,
     LSHFT = 314,
     RSHFT = 315,
     COLON2 = 316,
     SELF_ASGN = 317,
     ASSOC = 318,
     LAST_TOKEN = 319
   };
#endif
/* Tokens.  */
#define CLASS 258
#define MODULE 259
#define DEF 260
#define FUNC 261
#define UNDEF 262
#define INCLUDE 263
#define IF 264
#define THEN 265
#define ELSIF 266
#define ELSE 267
#define CASE 268
#define WHEN 269
#define UNLESS 270
#define UNTIL 271
#define WHILE 272
#define FOR 273
#define IN 274
#define DO 275
#define USING 276
#define PROTECT 277
#define RESQUE 278
#define ENSURE 279
#define END 280
#define REDO 281
#define BREAK 282
#define CONTINUE 283
#define RETURN 284
#define YIELD 285
#define SUPER 286
#define RETRY 287
#define SELF 288
#define NIL 289
#define IDENTIFIER 290
#define GVAR 291
#define IVAR 292
#define CONSTANT 293
#define INTEGER 294
#define FLOAT 295
#define STRING 296
#define REGEXP 297
#define UPLUS 298
#define UMINUS 299
#define POW 300
#define CMP 301
#define EQ 302
#define NEQ 303
#define GEQ 304
#define LEQ 305
#define AND 306
#define OR 307
#define MATCH 308
#define NMATCH 309
#define DOT2 310
#define DOT3 311
#define AREF 312
#define ASET 313
#define LSHFT 314
#define RSHFT 315
#define COLON2 316
#define SELF_ASGN 317
#define ASSOC 318
#define LAST_TOKEN 319




/* Copy the first part of user declarations.  */
#line 13 "parse.y"


#define YYDEBUG 1
#include "ruby.h"
#include "env.h"
#include "node.h"
#include "st.h"

#include "ident.h"
#define is_id_nonop(id) ((id)>LAST_TOKEN)
#define is_local_id(id) (is_id_nonop(id)&&((id)&ID_SCOPE_MASK)==ID_LOCAL)
#define is_global_id(id) (is_id_nonop(id)&&((id)&ID_SCOPE_MASK)==ID_GLOBAL)
#define is_instance_id(id) (is_id_nonop(id)&&((id)&ID_SCOPE_MASK)==ID_INSTANCE)
#define is_variable_id(id) (is_id_nonop(id)&&((id)&ID_VARMASK))
#define is_attrset_id(id) (is_id_nonop(id)&&((id)&ID_SCOPE_MASK)==ID_ATTRSET)
#define is_const_id(id) (is_id_nonop(id)&&((id)&ID_SCOPE_MASK)==ID_CONST)

struct op_tbl {
    ID tok;
    char *name;
};

NODE *eval_tree = Qnil;
static int in_regexp;

enum {
    KEEP_STATE = 0,             /* don't change lex_state. */
    EXPR_BEG,			/* ignore newline, +/- is a sign. */
    EXPR_MID,			/* newline significant, +/- is a sign. */
    EXPR_END,			/* +/- is a operator. newline significant */
};

static int lex_state;

static ID cur_class = Qnil, cur_mid = Qnil;
static int in_module, in_single;

static void value_expr();
static NODE *cond();
static NODE *cond2();

static NODE *block_append();
static NODE *list_append();
static NODE *list_concat();
static NODE *list_copy();
static NODE *call_op();

static NODE *asignable();
static NODE *aryset();
static NODE *attrset();

static void push_local();
static void pop_local();
static int local_cnt();
static int local_id();
static ID *local_tbl();

struct global_entry* rb_global_entry();

static void init_top_local();
static void setup_top_local();


/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 76 "parse.y"
{
    struct node *node;
    VALUE val;
    ID id;
}
/* Line 193 of yacc.c.  */
#line 293 "parse.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 306 "parse.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1334

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  91
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  56
/* YYNRULES -- Number of rules.  */
#define YYNRULES  220
/* YYNRULES -- Number of states.  */
#define YYNSTATES  388

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   319

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      86,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    75,     2,     2,     2,    74,    67,     2,
      83,    87,    72,    70,    90,    71,    78,    73,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    80,    85,
      69,    64,    68,     2,    81,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    79,    84,    82,    66,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    88,    65,    89,    76,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    77
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     4,     7,    10,    11,    13,    17,    21,
      22,    30,    31,    38,    39,    47,    48,    57,    58,    68,
      71,    75,    78,    82,    84,    86,    89,    92,    98,   103,
     105,   109,   111,   116,   120,   121,   124,   126,   130,   132,
     136,   138,   140,   142,   145,   147,   149,   151,   153,   155,
     157,   159,   161,   163,   165,   167,   169,   171,   173,   175,
     177,   179,   181,   183,   185,   187,   189,   191,   193,   195,
     198,   201,   204,   207,   210,   214,   218,   220,   221,   223,
     227,   229,   232,   234,   236,   240,   243,   245,   249,   257,
     265,   272,   279,   286,   295,   302,   309,   311,   313,   315,
     317,   320,   322,   326,   333,   339,   343,   350,   356,   359,
     363,   367,   371,   375,   379,   383,   387,   391,   394,   397,
     401,   405,   409,   413,   417,   421,   425,   429,   433,   437,
     441,   445,   448,   451,   455,   459,   463,   467,   471,   473,
     475,   477,   480,   482,   488,   489,   492,   494,   499,   501,
     507,   508,   511,   512,   515,   516,   518,   521,   526,   527,
     529,   531,   535,   537,   541,   543,   548,   550,   554,   558,
     565,   569,   574,   579,   584,   586,   588,   591,   592,   596,
     598,   600,   602,   604,   606,   608,   610,   612,   614,   616,
     618,   620,   622,   623,   625,   627,   631,   635,   637,   639,
     641,   643,   645,   647,   649,   651,   653,   655,   657,   659,
     660,   661,   663,   665,   667,   669,   671,   673,   675,   677,
     679
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
      92,     0,    -1,    -1,    93,    94,    -1,    95,   138,    -1,
      -1,    96,    -1,    95,   139,    96,    -1,    95,     1,    96,
      -1,    -1,     3,    35,   106,    97,    94,    25,   137,    -1,
      -1,     4,    35,    98,    94,    25,   137,    -1,    -1,     5,
     108,    99,   111,    94,    25,   137,    -1,    -1,     5,     6,
     108,   100,   111,    94,    25,   137,    -1,    -1,     5,   115,
      78,   108,   101,   111,    94,    25,   137,    -1,     7,   108,
      -1,     5,   108,   108,    -1,     8,   107,    -1,   102,    64,
     126,    -1,   116,    -1,   103,    -1,   103,   104,    -1,   132,
     146,    -1,   127,    79,   126,   143,   146,    -1,   127,    78,
      35,   146,    -1,   105,    -1,   104,   146,   105,    -1,   132,
      -1,   127,    79,   126,   143,    -1,   127,    78,    35,    -1,
      -1,    80,    35,    -1,    35,    -1,   107,   146,    35,    -1,
       1,    -1,   107,   146,     1,    -1,   109,    -1,    37,    -1,
      35,    -1,    35,    64,    -1,   110,    -1,    61,    -1,    55,
      -1,    65,    -1,    66,    -1,    67,    -1,    46,    -1,    47,
      -1,    48,    -1,    53,    -1,    54,    -1,    68,    -1,    49,
      -1,    69,    -1,    50,    -1,    59,    -1,    60,    -1,    70,
      -1,    71,    -1,    72,    -1,    73,    -1,    74,    -1,    45,
      -1,    75,    -1,    76,    -1,    75,    81,    -1,    76,    81,
      -1,    71,    81,    -1,    70,    81,    -1,    79,    82,    -1,
      79,    82,    64,    -1,    83,   112,   142,    -1,   139,    -1,
      -1,   113,    -1,   113,   146,   114,    -1,   114,    -1,   113,
       1,    -1,     1,    -1,    35,    -1,   113,   146,    35,    -1,
      72,    35,    -1,   133,    -1,    83,    94,   142,    -1,     9,
     116,   117,    94,   118,    25,   137,    -1,    15,   116,   117,
      94,   119,    25,   137,    -1,    13,   116,   138,   121,    25,
     137,    -1,    17,   116,   139,    94,    25,   137,    -1,    16,
     116,   139,    94,    25,   137,    -1,    18,   105,    19,   116,
     139,    94,    25,   137,    -1,    20,   116,   120,    94,    25,
     137,    -1,    22,    94,   122,   123,    25,   137,    -1,    26,
      -1,    27,    -1,    28,    -1,    32,    -1,    29,   116,    -1,
      29,    -1,   132,    64,   116,    -1,   127,    79,   126,   143,
      64,   116,    -1,   127,    78,    35,    64,   116,    -1,   132,
      62,   116,    -1,   127,    79,   126,   143,    62,   116,    -1,
     127,    78,    35,    62,   116,    -1,    30,   116,    -1,   116,
      55,   116,    -1,   116,    56,   116,    -1,   116,    70,   116,
      -1,   116,    71,   116,    -1,   116,    72,   116,    -1,   116,
      73,   116,    -1,   116,    74,   116,    -1,   116,    45,   116,
      -1,    70,   116,    -1,    71,   116,    -1,   116,    65,   116,
      -1,   116,    66,   116,    -1,   116,    67,   116,    -1,   116,
      46,   116,    -1,   116,    68,   116,    -1,   116,    49,   116,
      -1,   116,    69,   116,    -1,   116,    50,   116,    -1,   116,
      47,   116,    -1,   116,    48,   116,    -1,   116,    53,   116,
      -1,   116,    54,   116,    -1,    75,   116,    -1,    76,   116,
      -1,   116,    59,   116,    -1,   116,    60,   116,    -1,   116,
      61,   116,    -1,   116,    51,   116,    -1,   116,    52,   116,
      -1,   127,    -1,   139,    -1,    10,    -1,   139,    10,    -1,
     119,    -1,    11,   116,   117,    94,   118,    -1,    -1,    12,
      94,    -1,   139,    -1,   138,    21,   105,   139,    -1,   119,
      -1,    14,   126,   139,    94,   121,    -1,    -1,    23,    94,
      -1,    -1,    24,    94,    -1,    -1,   126,    -1,    72,    95,
      -1,   126,   146,    72,    95,    -1,    -1,   126,    -1,   116,
      -1,   126,   146,   116,    -1,   133,    -1,    83,    94,   142,
      -1,    41,    -1,   127,    79,   126,   143,    -1,   128,    -1,
      79,   125,   143,    -1,   144,   134,   145,    -1,   127,    78,
      35,    83,   124,   142,    -1,   127,    78,    35,    -1,    35,
      83,   124,   142,    -1,    37,    83,   124,   142,    -1,    31,
      83,   124,   142,    -1,    31,    -1,   131,    -1,    84,   130,
      -1,    -1,    73,   129,    42,    -1,   109,    -1,    37,    -1,
      36,    -1,    38,    -1,    39,    -1,    40,    -1,    35,    -1,
      37,    -1,    36,    -1,    38,    -1,    34,    -1,    33,    -1,
     132,    -1,    -1,   135,    -1,   136,    -1,   135,   146,   136,
      -1,   116,    63,   116,    -1,     3,    -1,     4,    -1,     5,
      -1,     6,    -1,     9,    -1,    15,    -1,    13,    -1,    17,
      -1,    16,    -1,    18,    -1,    20,    -1,    22,    -1,    -1,
      -1,   139,    -1,   140,    -1,   141,    -1,    85,    -1,    86,
      -1,    87,    -1,    82,    -1,    88,    -1,    89,    -1,    90,
      -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   168,   168,   168,   178,   181,   184,   185,   189,   196,
     195,   213,   212,   232,   231,   249,   248,   266,   265,   282,
     286,   290,   296,   310,   313,   314,   319,   323,   327,   332,
     336,   341,   345,   349,   355,   358,   363,   367,   371,   375,
     377,   378,   380,   381,   389,   391,   392,   393,   394,   395,
     396,   397,   398,   399,   400,   401,   402,   403,   404,   405,
     406,   407,   408,   409,   410,   411,   412,   413,   414,   415,
     416,   417,   418,   419,   420,   422,   426,   432,   435,   439,
     443,   447,   451,   456,   462,   469,   476,   490,   504,   514,
     526,   536,   543,   550,   560,   570,   587,   591,   595,   599,
     603,   610,   616,   621,   626,   631,   650,   662,   676,   681,
     685,   689,   693,   697,   701,   705,   709,   713,   719,   723,
     727,   731,   735,   739,   743,   747,   751,   755,   759,   763,
     767,   771,   775,   779,   783,   787,   791,   795,   799,   804,
     805,   806,   808,   809,   817,   820,   825,   829,   834,   835,
     843,   846,   855,   858,   864,   867,   868,   872,   878,   881,
     883,   888,   894,   895,   902,   907,   912,   917,   925,   929,
     934,   939,   943,   947,   953,   960,   961,   965,   965,   970,
     971,   972,   973,   975,   976,   978,   979,   980,   981,   982,
     986,   991,  1017,  1020,  1022,  1023,  1028,  1034,  1035,  1036,
    1037,  1038,  1039,  1040,  1041,  1042,  1043,  1044,  1045,  1046,
    1048,  1049,  1051,  1052,  1054,  1055,  1057,  1058,  1059,  1060,
    1061
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "CLASS", "MODULE", "DEF", "FUNC",
  "UNDEF", "INCLUDE", "IF", "THEN", "ELSIF", "ELSE", "CASE", "WHEN",
  "UNLESS", "UNTIL", "WHILE", "FOR", "IN", "DO", "USING", "PROTECT",
  "RESQUE", "ENSURE", "END", "REDO", "BREAK", "CONTINUE", "RETURN",
  "YIELD", "SUPER", "RETRY", "SELF", "NIL", "IDENTIFIER", "GVAR", "IVAR",
  "CONSTANT", "INTEGER", "FLOAT", "STRING", "REGEXP", "UPLUS", "UMINUS",
  "POW", "CMP", "EQ", "NEQ", "GEQ", "LEQ", "AND", "OR", "MATCH", "NMATCH",
  "DOT2", "DOT3", "AREF", "ASET", "LSHFT", "RSHFT", "COLON2", "SELF_ASGN",
  "ASSOC", "'='", "'|'", "'^'", "'&'", "'>'", "'<'", "'+'", "'-'", "'*'",
  "'/'", "'%'", "'!'", "'~'", "LAST_TOKEN", "'.'", "'['", "':'", "'@'",
  "']'", "'('", "'\\\\'", "';'", "'\\n'", "')'", "'{'", "'}'", "','",
  "$accept", "program", "@1", "compexpr", "exprs", "expr", "@2", "@3",
  "@4", "@5", "@6", "mlhs", "mlhs_head", "mlhs_tail", "lhs", "superclass",
  "inc_list", "fname", "fname0", "op", "f_arglist", "f_args", "f_arg",
  "rest_arg", "singleton", "expr2", "then", "if_tail", "opt_else",
  "opt_using", "cases", "resque", "ensure", "call_args", "opt_args",
  "args", "primary", "literal", "@7", "symbol", "numeric", "variable",
  "var_ref", "assoc_list", "assocs", "assoc", "end_mark", "opt_term",
  "term", "sc", "nl", "rparen", "rbracket", "lbrace", "rbrace", "comma", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,    61,   124,    94,    38,    62,    60,
      43,    45,    42,    47,    37,    33,   126,   319,    46,    91,
      58,    64,    93,    40,    92,    59,    10,    41,   123,   125,
      44
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    91,    93,    92,    94,    95,    95,    95,    95,    97,
      96,    98,    96,    99,    96,   100,    96,   101,    96,    96,
      96,    96,    96,    96,   102,   102,   103,   103,   103,   104,
     104,   105,   105,   105,   106,   106,   107,   107,   107,   107,
     108,   108,   109,   109,   109,   110,   110,   110,   110,   110,
     110,   110,   110,   110,   110,   110,   110,   110,   110,   110,
     110,   110,   110,   110,   110,   110,   110,   110,   110,   110,
     110,   110,   110,   110,   110,   111,   111,   112,   112,   112,
     112,   112,   112,   113,   113,   114,   115,   115,   116,   116,
     116,   116,   116,   116,   116,   116,   116,   116,   116,   116,
     116,   116,   116,   116,   116,   116,   116,   116,   116,   116,
     116,   116,   116,   116,   116,   116,   116,   116,   116,   116,
     116,   116,   116,   116,   116,   116,   116,   116,   116,   116,
     116,   116,   116,   116,   116,   116,   116,   116,   116,   117,
     117,   117,   118,   118,   119,   119,   120,   120,   121,   121,
     122,   122,   123,   123,   124,   124,   124,   124,   125,   125,
     126,   126,   127,   127,   127,   127,   127,   127,   127,   127,
     127,   127,   127,   127,   127,   128,   128,   129,   128,   130,
     130,   130,   130,   131,   131,   132,   132,   132,   132,   132,
     132,   133,   134,   134,   135,   135,   136,   137,   137,   137,
     137,   137,   137,   137,   137,   137,   137,   137,   137,   137,
     138,   138,   139,   139,   140,   141,   142,   143,   144,   145,
     146
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     2,     2,     0,     1,     3,     3,     0,
       7,     0,     6,     0,     7,     0,     8,     0,     9,     2,
       3,     2,     3,     1,     1,     2,     2,     5,     4,     1,
       3,     1,     4,     3,     0,     2,     1,     3,     1,     3,
       1,     1,     1,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     2,
       2,     2,     2,     2,     3,     3,     1,     0,     1,     3,
       1,     2,     1,     1,     3,     2,     1,     3,     7,     7,
       6,     6,     6,     8,     6,     6,     1,     1,     1,     1,
       2,     1,     3,     6,     5,     3,     6,     5,     2,     3,
       3,     3,     3,     3,     3,     3,     3,     2,     2,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     2,     2,     3,     3,     3,     3,     3,     1,     1,
       1,     2,     1,     5,     0,     2,     1,     4,     1,     5,
       0,     2,     0,     2,     0,     1,     2,     4,     0,     1,
       1,     3,     1,     3,     1,     4,     1,     3,     3,     6,
       3,     4,     4,     4,     1,     1,     2,     0,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     0,     1,     1,     3,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     0,
       0,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,     5,     1,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     5,    96,    97,    98,
     101,     0,   174,    99,   190,   189,   185,   187,   186,   188,
     183,   184,   164,     0,     0,   177,     0,     0,   158,     5,
       0,   218,     3,     0,     6,     0,    24,    23,   138,   166,
     175,   191,   162,   192,    34,    11,     0,    42,    41,    66,
      50,    51,    52,    56,    58,    53,    54,    46,    59,    60,
      45,    47,    48,    49,    55,    57,    61,    62,    63,    64,
      65,    67,    68,     0,     5,    13,    40,    44,     0,   191,
      86,    42,    41,    19,    38,    36,    21,     0,   138,   191,
     210,     0,     0,     0,     0,     0,    31,   210,   150,   100,
     108,   154,   154,   154,   117,   118,     0,   131,   132,   160,
       0,   159,     0,   181,   180,   182,   179,   176,     0,   214,
     215,     4,   211,   212,   213,     0,    25,    29,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   220,    26,     0,
       0,   193,   194,     0,     9,     5,    15,    43,    72,    71,
      69,    70,    73,     0,     0,    20,     0,     0,   140,     5,
     139,     0,     0,   144,   211,     5,     5,     5,     0,     0,
       0,     5,     0,   146,     5,   152,     5,     0,   155,     0,
       0,   178,   217,   167,     0,   216,   163,     8,     7,    22,
       0,   116,   122,   127,   128,   124,   126,   136,   137,   129,
     130,   109,   110,   133,   134,   135,   119,   120,   121,   123,
     125,   111,   112,   113,   114,   115,   170,     0,   105,   102,
       0,   219,   168,     0,    35,     5,     0,     0,    74,    87,
       0,     5,    76,    17,    39,    37,   144,   141,   170,     0,
       5,     0,   148,     0,   144,     0,     0,     0,    33,     0,
       0,     0,   151,     5,     0,     0,   173,     0,   171,   172,
     161,    30,     0,     0,   154,    28,   165,   196,   195,     0,
     209,     5,    82,    83,     0,     0,     0,    80,     0,     0,
       0,     0,   142,   165,   145,     0,   209,     0,   209,   209,
       5,    32,   209,     0,   153,   209,     0,     5,   107,   104,
       0,     0,     0,    27,   209,   197,   198,   199,   200,   201,
     203,   202,   205,   204,   206,   207,   208,    12,     0,    85,
      75,    81,     0,   209,     5,     0,   209,     5,    90,   209,
      92,    91,     0,    94,   147,    95,     0,   169,   106,   103,
      10,   209,    84,    79,    14,     0,     5,    88,   144,    89,
     209,    16,   209,   144,   149,    93,    18,   143
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,    42,    43,    44,   255,   175,   184,   257,
     309,    45,    46,   136,   104,   174,    96,    85,    86,    87,
     261,   305,   306,   307,    88,    47,   189,   311,   272,   201,
     273,   205,   284,   207,   120,   208,    98,    49,   116,   127,
      50,    99,    52,   170,   171,   172,   347,   131,   190,   133,
     134,   216,   213,    53,   252,   214
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -251
static const yytype_int16 yypact[] =
{
    -251,    36,   558,  -251,    -4,     7,   774,   973,    18,   718,
     718,   718,   718,   718,   876,   718,   558,  -251,  -251,  -251,
     718,   718,   -17,  -251,  -251,  -251,    -8,  -251,     2,  -251,
    -251,  -251,  -251,   718,   718,  -251,   718,   718,   718,   558,
     930,  -251,  -251,    67,  -251,    48,   876,  1080,   -19,  -251,
    -251,    -1,  -251,   718,    37,  -251,   973,   -29,    47,  -251,
    -251,  -251,  -251,  -251,  -251,  -251,  -251,  -251,  -251,  -251,
    -251,  -251,  -251,  -251,  -251,  -251,    54,    56,  -251,  -251,
    -251,    63,    66,    46,   558,   973,  -251,  -251,    71,  -251,
    -251,    87,  -251,  -251,  -251,  -251,    70,   815,     5,   -21,
    1008,   815,  1008,  1008,   150,    26,    53,  1008,   151,  1080,
    1080,   401,   401,   401,  -251,  -251,   143,  -251,  -251,  1080,
     104,    70,   105,  -251,  -251,  -251,  -251,  -251,   558,  -251,
    -251,  -251,   558,  -251,  -251,   718,    70,  -251,   718,   718,
     718,   718,   718,   718,   718,   718,   718,   718,   718,   718,
     718,   718,   718,   718,   718,   718,   718,   718,   718,   718,
     718,   718,   718,   162,   718,   718,   718,  -251,  -251,  1050,
     109,    70,  -251,   165,  -251,   558,  -251,  -251,  -251,  -251,
    -251,  -251,   137,   105,    11,  -251,   973,    22,  -251,   558,
     193,   172,   718,    62,  -251,   558,   558,   558,   718,   173,
     718,   558,   188,   189,   558,   187,   558,   105,    70,   105,
     105,  -251,  -251,  -251,   718,  -251,  -251,  -251,  -251,    70,
     876,   167,  1230,  1230,  1230,    28,    28,  1170,  1140,  1230,
    1230,  1110,  1110,    68,    68,  1080,  1200,  1200,  1260,    28,
      28,    50,    50,   167,   167,   167,    65,   -52,  1080,  1080,
     718,  -251,  -251,   718,  -251,   558,   190,    11,  -251,  -251,
      21,   558,  -251,  -251,  -251,  -251,   156,  -251,   -35,   -52,
     558,   718,  -251,   191,   201,   192,   196,  1008,    78,   -52,
     197,   876,  -251,   558,   198,    24,  -251,   642,  -251,  -251,
    1080,  -251,   718,   718,   401,  -251,    81,  1080,  -251,   199,
     440,   558,  -251,  -251,   179,   105,    16,  -251,   200,    11,
     718,   204,  -251,    52,  -251,    80,   440,   205,   440,   440,
     558,    99,   440,    94,  -251,   440,   558,   558,  1080,  1080,
     105,   718,   718,  -251,   440,  -251,  -251,  -251,  -251,  -251,
    -251,  -251,  -251,  -251,  -251,  -251,  -251,  -251,   206,  -251,
    -251,  -251,   -14,   440,   558,   815,   440,   558,  -251,   440,
    -251,  -251,   208,  -251,  -251,  -251,    33,  -251,  1080,  1080,
    -251,   440,  -251,  -251,  -251,   209,   558,  -251,    62,  -251,
     440,  -251,   440,   156,  -251,  -251,  -251,  -251
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -251,  -251,  -251,   -13,  -193,  -121,  -251,  -251,  -251,  -251,
    -251,  -251,  -251,  -251,   -31,  -251,  -251,    -5,   212,  -251,
    -237,  -251,  -251,  -116,  -251,   356,   -95,  -145,  -250,  -251,
    -138,  -251,  -251,  -104,  -251,   -28,    31,  -251,  -251,  -251,
    -251,    -2,   235,  -251,  -251,    -9,   574,   -68,   -38,  -251,
    -251,  -155,  -229,  -251,  -251,   -50
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -212
static const yytype_int16 yytable[] =
{
      51,   168,    93,   108,    89,   132,   195,   217,   209,   210,
     121,   218,   106,   285,    51,   137,   312,   351,   296,    94,
     301,   372,   302,   264,   317,   128,   122,   292,   259,   293,
     212,    54,   193,    48,   128,   177,     3,    51,   167,   202,
     313,   165,    55,   166,   106,   105,   187,    48,   294,  -185,
     321,   176,   286,    95,   288,   289,   303,   265,   304,   163,
     164,   165,   194,   166,   196,   197,   111,  -210,   128,   203,
      48,   183,   354,   138,   270,   112,   271,   105,  -210,  -210,
     185,  -210,    51,   191,   192,   113,   220,   150,   151,   167,
    -210,  -210,  -210,   304,   260,   138,   129,   130,   158,   159,
     160,   161,   162,   -78,   199,   200,   167,   219,   -77,   129,
     130,  -156,   135,   138,   331,    48,   332,   173,   129,   130,
    -157,   253,   160,   161,   162,  -186,    51,   292,   182,   293,
      51,  -191,  -191,   312,   366,   178,   247,   179,   158,   159,
     160,   161,   162,   331,   180,   332,   262,   181,   294,   186,
     350,   177,   129,   130,  -210,   167,  -170,  -170,   287,    48,
     167,   294,   256,    48,   269,   129,   130,   310,   270,   198,
     167,   167,   279,    51,   204,   367,   266,  -165,  -165,   129,
     130,   263,   274,   275,   276,   211,   212,    51,   280,   291,
     330,   282,   215,    51,    51,    51,   295,   246,   251,    51,
     254,   258,    51,   267,    51,   218,    48,   268,   278,   281,
    -211,   283,   138,   270,   349,   300,   316,   318,   106,   262,
      48,   319,   322,   325,   334,   353,    48,    48,    48,   356,
     359,   371,    48,   380,   382,    48,   373,    48,   387,   320,
     384,    90,   299,   315,   298,     0,   333,   326,   308,     0,
     323,   105,   126,    51,     0,     0,   352,   314,     0,    51,
     376,     0,     0,     0,     0,     0,     0,     0,    51,     0,
     324,   262,     0,     0,     0,     0,     0,   357,     0,   106,
       0,    51,     0,     0,     0,   364,    48,     0,   348,     0,
       0,     0,    48,     0,     0,     0,     0,     0,     0,    51,
       0,    48,     0,     0,     0,     0,     0,   362,     0,     0,
       0,     0,   105,     0,    48,     0,     0,     0,    51,     0,
       0,     0,     0,     0,    51,    51,     0,     0,   326,     0,
       0,     0,    48,     0,     0,     0,     0,     0,     0,     0,
       0,   375,     0,     0,   378,     0,     0,     0,     0,     0,
       0,    48,    51,     0,     0,    51,     0,    48,    48,     0,
       0,     0,     0,   383,     0,    97,   100,   101,   102,   103,
       0,   107,     0,     0,    51,     0,   109,   110,     0,     0,
       0,     0,     0,     0,     0,    48,     0,     0,    48,   114,
     115,     0,   117,   118,   119,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    48,     0,   169,
       9,     0,     0,     0,    10,     0,    11,    12,    13,    14,
       0,    15,     0,    16,     0,     0,     0,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,   335,   336,   337,   338,     0,     0,   339,
       0,     0,     0,   340,     0,   341,   342,   343,   344,     0,
     345,     0,   346,     0,     0,     0,     0,   119,   119,   119,
       0,    33,    34,   206,    35,     0,    36,    37,     0,     0,
      38,     0,     0,     0,    39,    40,     0,     0,     0,    41,
       0,   119,     0,     0,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,     0,
     119,   248,   249,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   119,     0,
       0,     0,     0,     0,   277,     0,   119,     0,     0,     0,
       0,     4,     5,     6,     0,     7,     8,     9,     0,     0,
     290,    10,     0,    11,    12,    13,    14,     0,    15,     0,
      16,     0,     0,     0,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
       0,     0,     0,     0,     0,     0,   297,     0,     0,   169,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   119,    33,    34,
       0,    35,     0,    36,    37,     0,     0,    38,     0,     0,
       0,    39,    40,   290,     0,     0,    41,     0,   328,   329,
     119,     9,     0,     0,     0,    10,     0,    11,    12,    13,
      14,     0,    15,     0,    16,     0,   355,     0,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,     0,     0,     0,   368,   369,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    33,    34,   327,    35,     0,    36,    37,     0,
       0,    38,     0,     0,     0,    39,    40,     9,     0,     0,
      41,    10,     0,    11,    12,    13,    14,     0,    15,     0,
      16,     0,     0,     0,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      56,     0,     0,     0,     0,     0,     0,     0,    33,    34,
       0,    35,     0,    36,    37,     0,     0,    38,     0,     0,
       0,    39,    40,     0,     0,     0,    41,    24,    25,    57,
      27,    58,    29,     0,     0,     0,     0,     0,     0,    59,
      60,    61,    62,    63,    64,   188,     0,    65,    66,    67,
       0,     0,     0,    68,    69,    70,     0,     0,     0,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,     0,     0,    83,     0,     0,     0,    84,     0,     0,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,     0,     0,   150,   151,   152,     0,     0,     0,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     358,     0,   360,   361,     0,     0,   363,     0,     0,   365,
     129,   130,     0,     0,     0,     0,     0,    22,   370,    24,
      25,    26,    27,    28,    29,    30,    31,    32,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   374,     0,     0,
     377,     0,     0,   379,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   381,     0,     0,     0,    35,
       0,     0,     0,     0,   385,    38,   386,     0,     0,    39,
      40,     0,     0,     0,    41,    91,   123,   124,   125,     0,
       0,     0,     0,     0,     0,    59,    60,    61,    62,    63,
      64,     0,     0,    65,    66,    67,     0,     0,     0,    68,
      69,    70,     0,     0,     0,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,     0,    91,    83,
      92,     0,     0,     0,     0,     0,     0,     0,    59,    60,
      61,    62,    63,    64,     0,     0,    65,    66,    67,     0,
       0,     0,    68,    69,    70,     0,     0,     0,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
       0,     0,    83,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,     0,     0,   150,   151,   152,
       0,     0,     0,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   129,   130,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,     0,     0,   150,
     151,   152,     0,   250,     0,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,     0,     0,   150,
     151,   152,     0,     0,     0,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,  -212,  -212,     0,     0,   150,
     151,     0,     0,     0,     0,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   138,   139,   140,   141,   142,
     143,   144,     0,   146,   147,     0,     0,     0,     0,   150,
     151,     0,     0,     0,     0,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   138,   139,   140,   141,   142,
     143,     0,     0,   146,   147,     0,     0,     0,     0,   150,
     151,     0,     0,     0,     0,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   138,   139,   140,   141,   142,
     143,     0,     0,   146,   147,     0,     0,     0,     0,   150,
     151,     0,     0,     0,     0,     0,     0,   155,   156,   157,
     158,   159,   160,   161,   162,   138,  -212,  -212,  -212,   142,
     143,     0,     0,  -212,  -212,     0,     0,     0,     0,   150,
     151,     0,     0,     0,     0,     0,     0,     0,   156,   157,
     158,   159,   160,   161,   162,   138,   139,   140,   141,   142,
     143,     0,     0,   146,   147,     0,     0,     0,     0,   150,
     151,     0,     0,     0,     0,     0,     0,     0,   156,   157,
     158,   159,   160,   161,   162
};

static const yytype_int16 yycheck[] =
{
       2,    51,     7,    16,     6,    43,   101,   128,   112,   113,
      38,   132,    14,   206,    16,    46,   266,     1,   247,     1,
     257,    35,     1,     1,   274,     1,    39,    62,   183,    64,
      82,    35,   100,     2,     1,    64,     0,    39,    90,   107,
     269,    62,    35,    64,    46,    14,    96,    16,    83,    78,
     279,    56,   207,    35,   209,   210,    35,    35,    72,    78,
      79,    62,   100,    64,   102,   103,    83,     0,     1,   107,
      39,    84,   309,    45,    12,    83,    14,    46,    11,    12,
      85,    14,    84,    78,    79,    83,   136,    59,    60,    90,
      23,    24,    25,    72,    83,    45,    85,    86,    70,    71,
      72,    73,    74,    87,    78,    79,    90,   135,    87,    85,
      86,    87,    64,    45,    62,    84,    64,    80,    85,    86,
      87,   171,    72,    73,    74,    78,   128,    62,    82,    64,
     132,    78,    79,   383,   327,    81,   164,    81,    70,    71,
      72,    73,    74,    62,    81,    64,   184,    81,    83,    78,
     305,    64,    85,    86,    87,    90,    78,    79,   208,   128,
      90,    83,   175,   132,   192,    85,    86,    11,    12,    19,
      90,    90,   200,   175,    23,   330,   189,    78,    79,    85,
      86,   186,   195,   196,   197,    42,    82,   189,   201,   220,
     294,   204,    87,   195,   196,   197,   246,    35,    89,   201,
      35,    64,   204,    10,   206,   326,   175,    35,    35,    21,
      21,    24,    45,    12,    35,    25,    25,    25,   220,   257,
     189,    25,    25,    25,    25,    25,   195,   196,   197,    25,
      25,    25,   201,    25,    25,   204,   352,   206,   383,   277,
     378,     6,   255,   271,   253,    -1,   296,   285,   261,    -1,
     281,   220,    40,   255,    -1,    -1,   306,   270,    -1,   261,
     355,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   270,    -1,
     283,   309,    -1,    -1,    -1,    -1,    -1,   315,    -1,   281,
      -1,   283,    -1,    -1,    -1,   323,   255,    -1,   301,    -1,
      -1,    -1,   261,    -1,    -1,    -1,    -1,    -1,    -1,   301,
      -1,   270,    -1,    -1,    -1,    -1,    -1,   320,    -1,    -1,
      -1,    -1,   281,    -1,   283,    -1,    -1,    -1,   320,    -1,
      -1,    -1,    -1,    -1,   326,   327,    -1,    -1,   366,    -1,
      -1,    -1,   301,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   354,    -1,    -1,   357,    -1,    -1,    -1,    -1,    -1,
      -1,   320,   354,    -1,    -1,   357,    -1,   326,   327,    -1,
      -1,    -1,    -1,   376,    -1,     9,    10,    11,    12,    13,
      -1,    15,    -1,    -1,   376,    -1,    20,    21,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   354,    -1,    -1,   357,    33,
      34,    -1,    36,    37,    38,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   376,    -1,    53,
       9,    -1,    -1,    -1,    13,    -1,    15,    16,    17,    18,
      -1,    20,    -1,    22,    -1,    -1,    -1,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,     3,     4,     5,     6,    -1,    -1,     9,
      -1,    -1,    -1,    13,    -1,    15,    16,    17,    18,    -1,
      20,    -1,    22,    -1,    -1,    -1,    -1,   111,   112,   113,
      -1,    70,    71,    72,    73,    -1,    75,    76,    -1,    -1,
      79,    -1,    -1,    -1,    83,    84,    -1,    -1,    -1,    88,
      -1,   135,    -1,    -1,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,    -1,
     164,   165,   166,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   192,    -1,
      -1,    -1,    -1,    -1,   198,    -1,   200,    -1,    -1,    -1,
      -1,     3,     4,     5,    -1,     7,     8,     9,    -1,    -1,
     214,    13,    -1,    15,    16,    17,    18,    -1,    20,    -1,
      22,    -1,    -1,    -1,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      -1,    -1,    -1,    -1,    -1,    -1,   250,    -1,    -1,   253,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   271,    70,    71,
      -1,    73,    -1,    75,    76,    -1,    -1,    79,    -1,    -1,
      -1,    83,    84,   287,    -1,    -1,    88,    -1,   292,   293,
     294,     9,    -1,    -1,    -1,    13,    -1,    15,    16,    17,
      18,    -1,    20,    -1,    22,    -1,   310,    -1,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    -1,    -1,    -1,   331,   332,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    70,    71,    72,    73,    -1,    75,    76,    -1,
      -1,    79,    -1,    -1,    -1,    83,    84,     9,    -1,    -1,
      88,    13,    -1,    15,    16,    17,    18,    -1,    20,    -1,
      22,    -1,    -1,    -1,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       6,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    70,    71,
      -1,    73,    -1,    75,    76,    -1,    -1,    79,    -1,    -1,
      -1,    83,    84,    -1,    -1,    -1,    88,    33,    34,    35,
      36,    37,    38,    -1,    -1,    -1,    -1,    -1,    -1,    45,
      46,    47,    48,    49,    50,    10,    -1,    53,    54,    55,
      -1,    -1,    -1,    59,    60,    61,    -1,    -1,    -1,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    -1,    -1,    79,    -1,    -1,    -1,    83,    -1,    -1,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    -1,    -1,    59,    60,    61,    -1,    -1,    -1,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
     316,    -1,   318,   319,    -1,    -1,   322,    -1,    -1,   325,
      85,    86,    -1,    -1,    -1,    -1,    -1,    31,   334,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   353,    -1,    -1,
     356,    -1,    -1,   359,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   371,    -1,    -1,    -1,    73,
      -1,    -1,    -1,    -1,   380,    79,   382,    -1,    -1,    83,
      84,    -1,    -1,    -1,    88,    35,    36,    37,    38,    -1,
      -1,    -1,    -1,    -1,    -1,    45,    46,    47,    48,    49,
      50,    -1,    -1,    53,    54,    55,    -1,    -1,    -1,    59,
      60,    61,    -1,    -1,    -1,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    -1,    35,    79,
      37,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    45,    46,
      47,    48,    49,    50,    -1,    -1,    53,    54,    55,    -1,
      -1,    -1,    59,    60,    61,    -1,    -1,    -1,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      -1,    -1,    79,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    -1,    -1,    59,    60,    61,
      -1,    -1,    -1,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    85,    86,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    -1,    -1,    59,
      60,    61,    -1,    63,    -1,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    -1,    -1,    59,
      60,    61,    -1,    -1,    -1,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    -1,    -1,    59,
      60,    -1,    -1,    -1,    -1,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    45,    46,    47,    48,    49,
      50,    51,    -1,    53,    54,    -1,    -1,    -1,    -1,    59,
      60,    -1,    -1,    -1,    -1,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    45,    46,    47,    48,    49,
      50,    -1,    -1,    53,    54,    -1,    -1,    -1,    -1,    59,
      60,    -1,    -1,    -1,    -1,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    45,    46,    47,    48,    49,
      50,    -1,    -1,    53,    54,    -1,    -1,    -1,    -1,    59,
      60,    -1,    -1,    -1,    -1,    -1,    -1,    67,    68,    69,
      70,    71,    72,    73,    74,    45,    46,    47,    48,    49,
      50,    -1,    -1,    53,    54,    -1,    -1,    -1,    -1,    59,
      60,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    68,    69,
      70,    71,    72,    73,    74,    45,    46,    47,    48,    49,
      50,    -1,    -1,    53,    54,    -1,    -1,    -1,    -1,    59,
      60,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    68,    69,
      70,    71,    72,    73,    74
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    92,    93,     0,     3,     4,     5,     7,     8,     9,
      13,    15,    16,    17,    18,    20,    22,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    70,    71,    73,    75,    76,    79,    83,
      84,    88,    94,    95,    96,   102,   103,   116,   127,   128,
     131,   132,   133,   144,    35,    35,     6,    35,    37,    45,
      46,    47,    48,    49,    50,    53,    54,    55,    59,    60,
      61,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    79,    83,   108,   109,   110,   115,   132,
     133,    35,    37,   108,     1,    35,   107,   116,   127,   132,
     116,   116,   116,   116,   105,   127,   132,   116,    94,   116,
     116,    83,    83,    83,   116,   116,   129,   116,   116,   116,
     125,   126,    94,    36,    37,    38,   109,   130,     1,    85,
      86,   138,   139,   140,   141,    64,   104,   105,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      59,    60,    61,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    78,    79,    62,    64,    90,   146,   116,
     134,   135,   136,    80,   106,    98,   108,    64,    81,    81,
      81,    81,    82,    94,    99,   108,    78,   146,    10,   117,
     139,    78,    79,   138,   139,   117,   139,   139,    19,    78,
      79,   120,   138,   139,    23,   122,    72,   124,   126,   124,
     124,    42,    82,   143,   146,    87,   142,    96,    96,   126,
     146,   116,   116,   116,   116,   116,   116,   116,   116,   116,
     116,   116,   116,   116,   116,   116,   116,   116,   116,   116,
     116,   116,   116,   116,   116,   116,    35,   126,   116,   116,
      63,    89,   145,   146,    35,    97,    94,   100,    64,   142,
      83,   111,   139,   108,     1,    35,    94,    10,    35,   126,
      12,    14,   119,   121,    94,    94,    94,   116,    35,   126,
      94,    21,    94,    24,   123,    95,   142,   146,   142,   142,
     116,   105,    62,    64,    83,   146,   143,   116,   136,    94,
      25,   111,     1,    35,    72,   112,   113,   114,    94,   101,
      11,   118,   119,   143,    94,   126,    25,   119,    25,    25,
     139,   143,    25,   105,    94,    25,   139,    72,   116,   116,
     124,    62,    64,   146,    25,     3,     4,     5,     6,     9,
      13,    15,    16,    17,    18,    20,    22,   137,    94,    35,
     142,     1,   146,    25,   111,   116,    25,   139,   137,    25,
     137,   137,    94,   137,   139,   137,    95,   142,   116,   116,
     137,    25,    35,   114,   137,    94,   117,   137,    94,   137,
      25,   137,    25,    94,   121,   137,   137,   118
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      fprintf (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
  
  int yystate;
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;


	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),

		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;


      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to look-ahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 168 "parse.y"
    {
			lex_state = EXPR_BEG;
                        init_top_local();
		    }
    break;

  case 3:
#line 173 "parse.y"
    {
			eval_tree = block_append(eval_tree, (yyvsp[(2) - (2)].node));
                        setup_top_local();
		    }
    break;

  case 5:
#line 181 "parse.y"
    {
			(yyval.node) = Qnil;
		    }
    break;

  case 7:
#line 186 "parse.y"
    {
			(yyval.node) = block_append((yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node));
		    }
    break;

  case 8:
#line 190 "parse.y"
    {
			yyerrok;
			(yyval.node) = (yyvsp[(1) - (3)].node);
		    }
    break;

  case 9:
#line 196 "parse.y"
    {
			if (cur_class || cur_mid || in_single)
			    Error("nested class definition");
			cur_class = (yyvsp[(2) - (3)].id);
			push_local();
		    }
    break;

  case 10:
#line 204 "parse.y"
    {
			if ((yyvsp[(7) - (7)].id) && (yyvsp[(7) - (7)].id) != CLASS) {
			    Error("unmatched end keyword(expected `class')");
			}
		        (yyval.node) = NEW_CLASS((yyvsp[(2) - (7)].id), (yyvsp[(5) - (7)].node), (yyvsp[(3) - (7)].id));
		        pop_local();
		        cur_class = Qnil;
		    }
    break;

  case 11:
#line 213 "parse.y"
    {
			if (cur_class != Qnil)
			    Error("nested module definition");
			cur_class = (yyvsp[(2) - (2)].id);
			in_module = 1;
			push_local();
		    }
    break;

  case 12:
#line 222 "parse.y"
    {
			if ((yyvsp[(6) - (6)].id) && (yyvsp[(6) - (6)].id) != MODULE) {
			    Error("unmatched end keyword(expected `module')");
			}
		        (yyval.node) = NEW_MODULE((yyvsp[(2) - (6)].id), (yyvsp[(4) - (6)].node));
		        pop_local();
		        cur_class = Qnil;
			in_module = 0;
		    }
    break;

  case 13:
#line 232 "parse.y"
    {
			if (cur_mid || in_single)
			    Error("nested method definition");
			cur_mid = (yyvsp[(2) - (2)].id);
			push_local();
		    }
    break;

  case 14:
#line 240 "parse.y"
    {
			if ((yyvsp[(7) - (7)].id) && (yyvsp[(7) - (7)].id) != DEF) {
			    Error("unmatched end keyword(expected `def')");
			}
			(yyval.node) = NEW_DEFN((yyvsp[(2) - (7)].id), NEW_RFUNC((yyvsp[(4) - (7)].node), (yyvsp[(5) - (7)].node)), MTH_METHOD);
		        pop_local();
			cur_mid = Qnil;
		    }
    break;

  case 15:
#line 249 "parse.y"
    {
			if (cur_mid || in_single)
			    Error("nested method definition");
			cur_mid = (yyvsp[(3) - (3)].id);
			push_local();
		    }
    break;

  case 16:
#line 257 "parse.y"
    {
			if ((yyvsp[(8) - (8)].id) && (yyvsp[(8) - (8)].id) != DEF) {
			    Error("unmatched end keyword(expected `def')");
			}
			(yyval.node) = NEW_DEFN((yyvsp[(3) - (8)].id), NEW_RFUNC((yyvsp[(5) - (8)].node), (yyvsp[(6) - (8)].node)), MTH_FUNC);
		        pop_local();
			cur_mid = Qnil;
		    }
    break;

  case 17:
#line 266 "parse.y"
    {
			value_expr((yyvsp[(2) - (4)].node));
			in_single++;
			push_local();
		    }
    break;

  case 18:
#line 274 "parse.y"
    {
			if ((yyvsp[(9) - (9)].id) && (yyvsp[(9) - (9)].id) != DEF) {
			    Error("unmatched end keyword(expected `def')");
			}
			(yyval.node) = NEW_DEFS((yyvsp[(2) - (9)].node), (yyvsp[(4) - (9)].id), NEW_RFUNC((yyvsp[(6) - (9)].node), (yyvsp[(7) - (9)].node)));
		        pop_local();
			in_single--;
		    }
    break;

  case 19:
#line 283 "parse.y"
    {
			(yyval.node) = NEW_UNDEF((yyvsp[(2) - (2)].id));
		    }
    break;

  case 20:
#line 287 "parse.y"
    {
			(yyval.node) = NEW_ALIAS((yyvsp[(2) - (3)].id), (yyvsp[(3) - (3)].id));
		    }
    break;

  case 21:
#line 291 "parse.y"
    {
			if (cur_mid || in_single)
			    Error("include appeared in method definition");
			(yyval.node) = (yyvsp[(2) - (2)].node);
		    }
    break;

  case 22:
#line 297 "parse.y"
    {
			NODE *rhs;

			if ((yyvsp[(3) - (3)].node)->nd_next == Qnil) {
			    rhs = (yyvsp[(3) - (3)].node)->nd_head;
			    free((yyvsp[(3) - (3)].node));
			}
			else {
			    rhs = (yyvsp[(3) - (3)].node);
			}

			(yyval.node) = NEW_MASGN((yyvsp[(1) - (3)].node), rhs);
		    }
    break;

  case 25:
#line 315 "parse.y"
    {
			(yyval.node) = list_concat((yyvsp[(1) - (2)].node), (yyvsp[(2) - (2)].node));
		    }
    break;

  case 26:
#line 320 "parse.y"
    {
			(yyval.node) = NEW_LIST(asignable((yyvsp[(1) - (2)].id), Qnil));
		    }
    break;

  case 27:
#line 324 "parse.y"
    {
			(yyval.node) = NEW_LIST(aryset((yyvsp[(1) - (5)].node), (yyvsp[(3) - (5)].node), Qnil));
		    }
    break;

  case 28:
#line 328 "parse.y"
    {
			(yyval.node) = NEW_LIST(attrset((yyvsp[(1) - (4)].node), (yyvsp[(3) - (4)].id), Qnil));
		    }
    break;

  case 29:
#line 333 "parse.y"
    {
			(yyval.node) = NEW_LIST((yyvsp[(1) - (1)].node));
		    }
    break;

  case 30:
#line 337 "parse.y"
    {
			(yyval.node) = list_append((yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node));
		    }
    break;

  case 31:
#line 342 "parse.y"
    {
			(yyval.node) = asignable((yyvsp[(1) - (1)].id), Qnil);
		    }
    break;

  case 32:
#line 346 "parse.y"
    {
			(yyval.node) = aryset((yyvsp[(1) - (4)].node), (yyvsp[(3) - (4)].node), Qnil);
		    }
    break;

  case 33:
#line 350 "parse.y"
    {
			(yyval.node) = attrset((yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].id), Qnil);
		    }
    break;

  case 34:
#line 355 "parse.y"
    {
			(yyval.id) = Qnil;
		    }
    break;

  case 35:
#line 359 "parse.y"
    {
			(yyval.id) = (yyvsp[(2) - (2)].id);
		    }
    break;

  case 36:
#line 364 "parse.y"
    {
			(yyval.node) = NEW_INC((yyvsp[(1) - (1)].id));
		    }
    break;

  case 37:
#line 368 "parse.y"
    {
			(yyval.node) = block_append((yyvsp[(1) - (3)].node), NEW_INC((yyvsp[(3) - (3)].id)));
		    }
    break;

  case 38:
#line 372 "parse.y"
    {
			(yyval.node) = Qnil;
		    }
    break;

  case 43:
#line 382 "parse.y"
    {
			ID id = (yyvsp[(1) - (2)].id);

			id &= ~ID_SCOPE_MASK;
			id |= ID_ATTRSET;
			(yyval.id) = id;
		    }
    break;

  case 45:
#line 391 "parse.y"
    { (yyval.id) = COLON2; }
    break;

  case 46:
#line 392 "parse.y"
    { (yyval.id) = DOT2; }
    break;

  case 47:
#line 393 "parse.y"
    { (yyval.id) = '|'; }
    break;

  case 48:
#line 394 "parse.y"
    { (yyval.id) = '^'; }
    break;

  case 49:
#line 395 "parse.y"
    { (yyval.id) = '&'; }
    break;

  case 50:
#line 396 "parse.y"
    { (yyval.id) = CMP; }
    break;

  case 51:
#line 397 "parse.y"
    { (yyval.id) = EQ; }
    break;

  case 52:
#line 398 "parse.y"
    { (yyval.id) = NEQ; }
    break;

  case 53:
#line 399 "parse.y"
    { (yyval.id) = MATCH; }
    break;

  case 54:
#line 400 "parse.y"
    { (yyval.id) = NMATCH; }
    break;

  case 55:
#line 401 "parse.y"
    { (yyval.id) = '>'; }
    break;

  case 56:
#line 402 "parse.y"
    { (yyval.id) = GEQ; }
    break;

  case 57:
#line 403 "parse.y"
    { (yyval.id) = '<'; }
    break;

  case 58:
#line 404 "parse.y"
    { (yyval.id) = LEQ; }
    break;

  case 59:
#line 405 "parse.y"
    { (yyval.id) = LSHFT; }
    break;

  case 60:
#line 406 "parse.y"
    { (yyval.id) = RSHFT; }
    break;

  case 61:
#line 407 "parse.y"
    { (yyval.id) = '+'; }
    break;

  case 62:
#line 408 "parse.y"
    { (yyval.id) = '-'; }
    break;

  case 63:
#line 409 "parse.y"
    { (yyval.id) = '*'; }
    break;

  case 64:
#line 410 "parse.y"
    { (yyval.id) = '/'; }
    break;

  case 65:
#line 411 "parse.y"
    { (yyval.id) = '%'; }
    break;

  case 66:
#line 412 "parse.y"
    { (yyval.id) = POW; }
    break;

  case 67:
#line 413 "parse.y"
    { (yyval.id) = '!'; }
    break;

  case 68:
#line 414 "parse.y"
    { (yyval.id) = '~'; }
    break;

  case 69:
#line 415 "parse.y"
    { (yyval.id) = '!'; }
    break;

  case 70:
#line 416 "parse.y"
    { (yyval.id) = '~'; }
    break;

  case 71:
#line 417 "parse.y"
    { (yyval.id) = UMINUS; }
    break;

  case 72:
#line 418 "parse.y"
    { (yyval.id) = UPLUS; }
    break;

  case 73:
#line 419 "parse.y"
    { (yyval.id) = AREF; }
    break;

  case 74:
#line 420 "parse.y"
    { (yyval.id) = ASET; }
    break;

  case 75:
#line 423 "parse.y"
    {
			(yyval.node) = (yyvsp[(2) - (3)].node);
		    }
    break;

  case 76:
#line 427 "parse.y"
    {
			(yyval.node) = Qnil;
		    }
    break;

  case 77:
#line 432 "parse.y"
    {
			(yyval.node) = Qnil;
		    }
    break;

  case 78:
#line 436 "parse.y"
    {
			(yyval.node) = NEW_ARGS((yyvsp[(1) - (1)].node), -1);
		    }
    break;

  case 79:
#line 440 "parse.y"
    {
			(yyval.node) = NEW_ARGS((yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].id));
		    }
    break;

  case 80:
#line 444 "parse.y"
    {
			(yyval.node) = NEW_ARGS(Qnil, (yyvsp[(1) - (1)].id));
		    }
    break;

  case 81:
#line 448 "parse.y"
    {
			(yyval.node) = NEW_ARGS((yyvsp[(1) - (2)].node), -1);
		    }
    break;

  case 82:
#line 452 "parse.y"
    {
			(yyval.node) = Qnil;
		    }
    break;

  case 83:
#line 457 "parse.y"
    {
			if (!is_local_id((yyvsp[(1) - (1)].id)))
			    Error("formal argument must be local variable");
			(yyval.node) = NEW_LIST(local_cnt((yyvsp[(1) - (1)].id)));
		    }
    break;

  case 84:
#line 463 "parse.y"
    {
			if (!is_local_id((yyvsp[(3) - (3)].id)))
			    Error("formal argument must be local variable");
			(yyval.node) = list_append((yyvsp[(1) - (3)].node), local_cnt((yyvsp[(3) - (3)].id)));
		    }
    break;

  case 85:
#line 470 "parse.y"
    {
			if (!is_local_id((yyvsp[(2) - (2)].id)))
			    Error("rest argument must be local variable");
			(yyval.id) = local_cnt((yyvsp[(2) - (2)].id));
		    }
    break;

  case 86:
#line 477 "parse.y"
    {
			if ((yyvsp[(1) - (1)].node)->type == NODE_SELF) {
			    (yyval.node) = NEW_SELF();
			}
			else if ((yyvsp[(1) - (1)].node)->type == NODE_NIL) {
			    Error("Can't define single method for nil.");
			    freenode((yyvsp[(1) - (1)].node));
			    (yyval.node) = Qnil;
			}
			else {
			    (yyval.node) = (yyvsp[(1) - (1)].node);
			}
		    }
    break;

  case 87:
#line 491 "parse.y"
    {
			switch ((yyvsp[(2) - (3)].node)->type) {
			  case NODE_STR:
			  case NODE_LIT:
			  case NODE_ARRAY:
			  case NODE_ZARRAY:
			    Error("Can't define single method for literals.");
			  default:
			    break;
			}
			(yyval.node) = (yyvsp[(2) - (3)].node);
		    }
    break;

  case 88:
#line 508 "parse.y"
    {
			if ((yyvsp[(7) - (7)].id) && (yyvsp[(7) - (7)].id) != IF) {
			    Error("unmatched end keyword(expected `if')");
			}
			(yyval.node) = NEW_IF(cond((yyvsp[(2) - (7)].node)), (yyvsp[(4) - (7)].node), (yyvsp[(5) - (7)].node));
		    }
    break;

  case 89:
#line 516 "parse.y"
    {
			if ((yyvsp[(7) - (7)].id) && (yyvsp[(7) - (7)].id) != UNLESS) {
#ifdef __r49_bugfix
			    Error("unmatched end keyword(expected `unless')");
#else
			    Error("unmatched end keyword(expected `if')");
#endif
			}
		        (yyval.node) = NEW_UNLESS(cond((yyvsp[(2) - (7)].node)), (yyvsp[(4) - (7)].node), (yyvsp[(5) - (7)].node));
		    }
    break;

  case 90:
#line 529 "parse.y"
    {
			if ((yyvsp[(6) - (6)].id) && (yyvsp[(6) - (6)].id) != CASE) {
			    Error("unmatched end keyword(expected `case')");
			}
			value_expr((yyvsp[(2) - (6)].node));
			(yyval.node) = NEW_CASE((yyvsp[(2) - (6)].node), (yyvsp[(4) - (6)].node));
		    }
    break;

  case 91:
#line 537 "parse.y"
    {
			if ((yyvsp[(6) - (6)].id) && (yyvsp[(6) - (6)].id) != WHILE) {
			    Error("unmatched end keyword(expected `while')");
			}
			(yyval.node) = NEW_WHILE(cond((yyvsp[(2) - (6)].node)), (yyvsp[(4) - (6)].node));
		    }
    break;

  case 92:
#line 544 "parse.y"
    {
			if ((yyvsp[(6) - (6)].id) && (yyvsp[(6) - (6)].id) != UNTIL) {
			    Error("unmatched end keyword(expected `until')");
			}
			(yyval.node) = NEW_UNTIL(cond((yyvsp[(2) - (6)].node)), (yyvsp[(4) - (6)].node));
		    }
    break;

  case 93:
#line 553 "parse.y"
    {
			if ((yyvsp[(8) - (8)].id) && (yyvsp[(8) - (8)].id) != FOR) {
			    Error("unmatched end keyword(expected `for')");
			}
			value_expr((yyvsp[(4) - (8)].node));
			(yyval.node) = NEW_FOR((yyvsp[(2) - (8)].node), (yyvsp[(4) - (8)].node), (yyvsp[(6) - (8)].node));
		    }
    break;

  case 94:
#line 563 "parse.y"
    {
			if ((yyvsp[(6) - (6)].id) && (yyvsp[(6) - (6)].id) != DO) {
			    Error("unmatched end keyword(expected `do')");
			}
			value_expr((yyvsp[(2) - (6)].node));
			(yyval.node) = NEW_DO((yyvsp[(3) - (6)].node), (yyvsp[(2) - (6)].node), (yyvsp[(4) - (6)].node));
		    }
    break;

  case 95:
#line 575 "parse.y"
    {
			if ((yyvsp[(6) - (6)].id) && (yyvsp[(6) - (6)].id) != PROTECT) {
			    Error("unmatched end keyword(expected `protect')");
			}
			if ((yyvsp[(3) - (6)].node) == Qnil && (yyvsp[(4) - (6)].node) == Qnil) {
			    Warning("useless protect clause");
			    (yyval.node) = (yyvsp[(2) - (6)].node);
			}
			else {
			    (yyval.node) = NEW_PROT((yyvsp[(2) - (6)].node), (yyvsp[(3) - (6)].node), (yyvsp[(4) - (6)].node));
			}
		    }
    break;

  case 96:
#line 588 "parse.y"
    {
			(yyval.node) = NEW_REDO();
		    }
    break;

  case 97:
#line 592 "parse.y"
    {
			(yyval.node) = NEW_BREAK();
		    }
    break;

  case 98:
#line 596 "parse.y"
    {
			(yyval.node) = NEW_CONT();
		    }
    break;

  case 99:
#line 600 "parse.y"
    {
			(yyval.node) = NEW_RETRY();
		    }
    break;

  case 100:
#line 604 "parse.y"
    {
			value_expr((yyvsp[(2) - (2)].node));
			if (!cur_mid && !in_single)
			    Error("return appeared outside of method");
			(yyval.node) = NEW_RET((yyvsp[(2) - (2)].node));
		    }
    break;

  case 101:
#line 611 "parse.y"
    {
			if (!cur_mid && !in_single)
			    Error("return appeared outside of method");
			(yyval.node) = NEW_RET(Qnil);
		    }
    break;

  case 102:
#line 617 "parse.y"
    {
			value_expr((yyvsp[(3) - (3)].node));
			(yyval.node) = asignable((yyvsp[(1) - (3)].id), (yyvsp[(3) - (3)].node));
		    }
    break;

  case 103:
#line 622 "parse.y"
    {
			value_expr((yyvsp[(6) - (6)].node));
			(yyval.node) = aryset((yyvsp[(1) - (6)].node), (yyvsp[(3) - (6)].node), (yyvsp[(6) - (6)].node));
		    }
    break;

  case 104:
#line 627 "parse.y"
    {
			value_expr((yyvsp[(5) - (5)].node));
			(yyval.node) = attrset((yyvsp[(1) - (5)].node), (yyvsp[(3) - (5)].id), (yyvsp[(5) - (5)].node));
		    }
    break;

  case 105:
#line 632 "parse.y"
    {
		  	NODE *val;

			value_expr((yyvsp[(3) - (3)].node));
			if (is_local_id((yyvsp[(1) - (3)].id))) {
			    val = NEW_LVAR((yyvsp[(1) - (3)].id));
			}
			else if (is_global_id((yyvsp[(1) - (3)].id))) {
			    val = NEW_GVAR((yyvsp[(1) - (3)].id));
			}
			else if (is_instance_id((yyvsp[(1) - (3)].id))) {
			    val = NEW_IVAR((yyvsp[(1) - (3)].id));
			}
			else {
			    val = NEW_CVAR((yyvsp[(1) - (3)].id));
			}
		  	(yyval.node) = asignable((yyvsp[(1) - (3)].id), call_op(val, (yyvsp[(2) - (3)].id), 1, (yyvsp[(3) - (3)].node)));
		    }
    break;

  case 106:
#line 651 "parse.y"
    {
			NODE *rval, *args;
			value_expr((yyvsp[(1) - (6)].node));
			value_expr((yyvsp[(6) - (6)].node));

			args = list_copy((yyvsp[(3) - (6)].node));
			rval = NEW_CALL2((yyvsp[(1) - (6)].node), AREF, args);

			args = list_append((yyvsp[(3) - (6)].node), call_op(rval, (yyvsp[(5) - (6)].id), 1, (yyvsp[(6) - (6)].node)));
			(yyval.node) = NEW_CALL((yyvsp[(1) - (6)].node), ASET, args);
		    }
    break;

  case 107:
#line 663 "parse.y"
    {
			ID id = (yyvsp[(3) - (5)].id);
			NODE *rval;

			value_expr((yyvsp[(1) - (5)].node));
			value_expr((yyvsp[(5) - (5)].node));

			id &= ~ID_SCOPE_MASK;
			id |= ID_ATTRSET;

			rval = call_op(NEW_CALL2((yyvsp[(1) - (5)].node), (yyvsp[(3) - (5)].id), Qnil), (yyvsp[(4) - (5)].id), 1, (yyvsp[(5) - (5)].node));
			(yyval.node) = NEW_CALL((yyvsp[(1) - (5)].node), id, NEW_LIST(rval));
		    }
    break;

  case 108:
#line 677 "parse.y"
    {
			value_expr((yyvsp[(2) - (2)].node));
			(yyval.node) = NEW_YIELD((yyvsp[(2) - (2)].node));
		    }
    break;

  case 109:
#line 682 "parse.y"
    {
			(yyval.node) = call_op((yyvsp[(1) - (3)].node), DOT2, 1, (yyvsp[(3) - (3)].node));
		    }
    break;

  case 110:
#line 686 "parse.y"
    {
			(yyval.node) = NEW_DOT3(cond2((yyvsp[(1) - (3)].node)), cond2((yyvsp[(3) - (3)].node)));
		    }
    break;

  case 111:
#line 690 "parse.y"
    {
		        (yyval.node) = call_op((yyvsp[(1) - (3)].node), '+', 1, (yyvsp[(3) - (3)].node));
		    }
    break;

  case 112:
#line 694 "parse.y"
    {
		        (yyval.node) = call_op((yyvsp[(1) - (3)].node), '-', 1, (yyvsp[(3) - (3)].node));
		    }
    break;

  case 113:
#line 698 "parse.y"
    {
		        (yyval.node) = call_op((yyvsp[(1) - (3)].node), '*', 1, (yyvsp[(3) - (3)].node));
		    }
    break;

  case 114:
#line 702 "parse.y"
    {
			(yyval.node) = call_op((yyvsp[(1) - (3)].node), '/', 1, (yyvsp[(3) - (3)].node));
		    }
    break;

  case 115:
#line 706 "parse.y"
    {
			(yyval.node) = call_op((yyvsp[(1) - (3)].node), '%', 1, (yyvsp[(3) - (3)].node));
		    }
    break;

  case 116:
#line 710 "parse.y"
    {
			(yyval.node) = call_op((yyvsp[(1) - (3)].node), POW, 1, (yyvsp[(3) - (3)].node));
		    }
    break;

  case 117:
#line 714 "parse.y"
    {
		    	// __r49: BUG: `print(+34 - 3000)`
			(yyval.node) = call_op((yyvsp[(2) - (2)].node), UPLUS, 0);

		    }
    break;

  case 118:
#line 720 "parse.y"
    {
		        (yyval.node) = call_op((yyvsp[(2) - (2)].node), UMINUS, 0);
		    }
    break;

  case 119:
#line 724 "parse.y"
    {
		        (yyval.node) = call_op((yyvsp[(1) - (3)].node), '|', 1, (yyvsp[(3) - (3)].node));
		    }
    break;

  case 120:
#line 728 "parse.y"
    {
			(yyval.node) = call_op((yyvsp[(1) - (3)].node), '^', 1, (yyvsp[(3) - (3)].node));
		    }
    break;

  case 121:
#line 732 "parse.y"
    {
			(yyval.node) = call_op((yyvsp[(1) - (3)].node), '&', 1, (yyvsp[(3) - (3)].node));
		    }
    break;

  case 122:
#line 736 "parse.y"
    {
			(yyval.node) = call_op((yyvsp[(1) - (3)].node), CMP, 1, (yyvsp[(3) - (3)].node));
		    }
    break;

  case 123:
#line 740 "parse.y"
    {
			(yyval.node) = call_op((yyvsp[(1) - (3)].node), '>', 1, (yyvsp[(3) - (3)].node));
		    }
    break;

  case 124:
#line 744 "parse.y"
    {
			(yyval.node) = call_op((yyvsp[(1) - (3)].node), GEQ, 1, (yyvsp[(3) - (3)].node));
		    }
    break;

  case 125:
#line 748 "parse.y"
    {
			(yyval.node) = call_op((yyvsp[(1) - (3)].node), '<', 1, (yyvsp[(3) - (3)].node));
		    }
    break;

  case 126:
#line 752 "parse.y"
    {
			(yyval.node) = call_op((yyvsp[(1) - (3)].node), LEQ, 1, (yyvsp[(3) - (3)].node));
		    }
    break;

  case 127:
#line 756 "parse.y"
    {
			(yyval.node) = call_op((yyvsp[(1) - (3)].node), EQ, 1, (yyvsp[(3) - (3)].node));
		    }
    break;

  case 128:
#line 760 "parse.y"
    {
			(yyval.node) = call_op((yyvsp[(1) - (3)].node), NEQ, 1, (yyvsp[(3) - (3)].node));
		    }
    break;

  case 129:
#line 764 "parse.y"
    {
			(yyval.node) = call_op((yyvsp[(1) - (3)].node), MATCH, 1, (yyvsp[(3) - (3)].node));
		    }
    break;

  case 130:
#line 768 "parse.y"
    {
			(yyval.node) = call_op((yyvsp[(1) - (3)].node), NMATCH, 1, (yyvsp[(3) - (3)].node));
		    }
    break;

  case 131:
#line 772 "parse.y"
    {
			(yyval.node) = call_op(cond((yyvsp[(2) - (2)].node)), '!', 0);
		    }
    break;

  case 132:
#line 776 "parse.y"
    {
			(yyval.node) = call_op((yyvsp[(2) - (2)].node), '~', 0);
		    }
    break;

  case 133:
#line 780 "parse.y"
    {
			(yyval.node) = call_op((yyvsp[(1) - (3)].node), LSHFT, 1, (yyvsp[(3) - (3)].node));
		    }
    break;

  case 134:
#line 784 "parse.y"
    {
			(yyval.node) = call_op((yyvsp[(1) - (3)].node), RSHFT, 1, (yyvsp[(3) - (3)].node));
		    }
    break;

  case 135:
#line 788 "parse.y"
    {
			(yyval.node) = call_op((yyvsp[(1) - (3)].node), COLON2, 1, (yyvsp[(3) - (3)].node));
		    }
    break;

  case 136:
#line 792 "parse.y"
    {
			(yyval.node) = NEW_AND(cond((yyvsp[(1) - (3)].node)), __r49_bugfix_r(cond,)((yyvsp[(3) - (3)].node)));
		    }
    break;

  case 137:
#line 796 "parse.y"
    {
			(yyval.node) = NEW_OR(cond((yyvsp[(1) - (3)].node)), __r49_bugfix_r(cond,)((yyvsp[(3) - (3)].node)));
		    }
    break;

  case 138:
#line 800 "parse.y"
    {
			(yyval.node) = (yyvsp[(1) - (1)].node);
		    }
    break;

  case 143:
#line 812 "parse.y"
    {
			(yyval.node) = NEW_IF(cond((yyvsp[(2) - (5)].node)), (yyvsp[(4) - (5)].node), (yyvsp[(5) - (5)].node));
		    }
    break;

  case 144:
#line 817 "parse.y"
    {
			(yyval.node) = Qnil;
		    }
    break;

  case 145:
#line 821 "parse.y"
    {
			(yyval.node) = (yyvsp[(2) - (2)].node);
		    }
    break;

  case 146:
#line 826 "parse.y"
    {
			(yyval.node) = Qnil;
		    }
    break;

  case 147:
#line 830 "parse.y"
    {
			(yyval.node) = (yyvsp[(3) - (4)].node);
		    }
    break;

  case 149:
#line 838 "parse.y"
    {
			(yyval.node) = NEW_WHEN((yyvsp[(2) - (5)].node), (yyvsp[(4) - (5)].node), (yyvsp[(5) - (5)].node));
		    }
    break;

  case 150:
#line 843 "parse.y"
    {
			(yyval.node) = Qnil;
		    }
    break;

  case 151:
#line 847 "parse.y"
    {
			if ((yyvsp[(2) - (2)].node) == Qnil)
			    (yyval.node) = (NODE*)1;
			else
			    (yyval.node) = (yyvsp[(2) - (2)].node);
		    }
    break;

  case 152:
#line 855 "parse.y"
    {
			(yyval.node) = Qnil;
		    }
    break;

  case 153:
#line 859 "parse.y"
    {
			(yyval.node) = (yyvsp[(2) - (2)].node);
		    }
    break;

  case 154:
#line 864 "parse.y"
    {
			(yyval.node) = Qnil;
		    }
    break;

  case 156:
#line 869 "parse.y"
    {
			(yyval.node) = (yyvsp[(2) - (2)].node);
		    }
    break;

  case 157:
#line 873 "parse.y"
    {
			(yyval.node) = call_op((yyvsp[(1) - (4)].node), '+', 1, (yyvsp[(4) - (4)].node));
		    }
    break;

  case 158:
#line 878 "parse.y"
    {
			(yyval.node) = Qnil;
		    }
    break;

  case 160:
#line 884 "parse.y"
    {
			value_expr((yyvsp[(1) - (1)].node));
			(yyval.node) = NEW_LIST((yyvsp[(1) - (1)].node));
		    }
    break;

  case 161:
#line 889 "parse.y"
    {
			value_expr((yyvsp[(3) - (3)].node));
			(yyval.node) = list_append((yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node));
		    }
    break;

  case 163:
#line 896 "parse.y"
    {
		    	/* __r49: make `()` in expression context not segfault */
			__r49_bugfix_q(if (!(yyvsp[(2) - (3)].node)) (yyval.node) = NEW_NIL(); else)
			(yyval.node) = (yyvsp[(2) - (3)].node);
		    }
    break;

  case 164:
#line 903 "parse.y"
    {
			literalize((yyvsp[(1) - (1)].val));
			(yyval.node) = NEW_STR((yyvsp[(1) - (1)].val));
		    }
    break;

  case 165:
#line 908 "parse.y"
    {
			value_expr((yyvsp[(1) - (4)].node));
			(yyval.node) = NEW_CALL((yyvsp[(1) - (4)].node), AREF, (yyvsp[(3) - (4)].node));
		    }
    break;

  case 166:
#line 913 "parse.y"
    {
			literalize((yyvsp[(1) - (1)].val));
			(yyval.node) = NEW_LIT((yyvsp[(1) - (1)].val));
		    }
    break;

  case 167:
#line 918 "parse.y"
    {
			if ((yyvsp[(2) - (3)].node) == Qnil)
			    (yyval.node) = NEW_ZARRAY(); /* zero length array*/
			else {
			    (yyval.node) = (yyvsp[(2) - (3)].node);
			}
		    }
    break;

  case 168:
#line 926 "parse.y"
    {
			(yyval.node) = NEW_HASH((yyvsp[(2) - (3)].node));
		    }
    break;

  case 169:
#line 930 "parse.y"
    {
			value_expr((yyvsp[(1) - (6)].node));
			(yyval.node) = NEW_CALL((yyvsp[(1) - (6)].node), (yyvsp[(3) - (6)].id), (yyvsp[(5) - (6)].node));
		    }
    break;

  case 170:
#line 935 "parse.y"
    {
			value_expr((yyvsp[(1) - (3)].node));
			(yyval.node) = NEW_CALL((yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].id), Qnil);
		    }
    break;

  case 171:
#line 940 "parse.y"
    {
			(yyval.node) = NEW_CALL(Qnil, (yyvsp[(1) - (4)].id), (yyvsp[(3) - (4)].node));
		    }
    break;

  case 172:
#line 944 "parse.y"
    {
			(yyval.node) = NEW_CALL(Qnil, (yyvsp[(1) - (4)].id), (yyvsp[(3) - (4)].node));
		    }
    break;

  case 173:
#line 948 "parse.y"
    {
			if (!cur_mid && !in_single)
			    Error("super called outside of method");
			(yyval.node) = NEW_SUPER((yyvsp[(3) - (4)].node));
		    }
    break;

  case 174:
#line 954 "parse.y"
    {
			if (!cur_mid && !in_single)
			    Error("super called outside of method");
			(yyval.node) = NEW_ZSUPER();
		    }
    break;

  case 176:
#line 962 "parse.y"
    {
			(yyval.val) = INT2FIX((yyvsp[(2) - (2)].id));
		    }
    break;

  case 177:
#line 965 "parse.y"
    {in_regexp = 1;}
    break;

  case 178:
#line 966 "parse.y"
    {
			(yyval.val) = (yyvsp[(3) - (3)].val);
		    }
    break;

  case 189:
#line 983 "parse.y"
    {
			(yyval.id) = NIL;
		    }
    break;

  case 190:
#line 987 "parse.y"
    {
			(yyval.id) = SELF;
		    }
    break;

  case 191:
#line 992 "parse.y"
    {
			if ((yyvsp[(1) - (1)].id) == SELF) {
			    (yyval.node) = NEW_SELF();
			}
			else if ((yyvsp[(1) - (1)].id) == NIL) {
			    (yyval.node) = NEW_NIL();
			}
			else if (is_local_id((yyvsp[(1) - (1)].id))) {
			    if (local_id((yyvsp[(1) - (1)].id)))
				(yyval.node) = NEW_LVAR((yyvsp[(1) - (1)].id));
			    else
				(yyval.node) = NEW_MVAR((yyvsp[(1) - (1)].id));
			}
			else if (is_global_id((yyvsp[(1) - (1)].id))) {
			    (yyval.node) = NEW_GVAR((yyvsp[(1) - (1)].id));
			}
			else if (is_instance_id((yyvsp[(1) - (1)].id))) {
			    (yyval.node) = NEW_IVAR((yyvsp[(1) - (1)].id));
			}
			else if (is_const_id((yyvsp[(1) - (1)].id))) {
			    (yyval.node) = NEW_CVAR((yyvsp[(1) - (1)].id));
			}
		    }
    break;

  case 192:
#line 1017 "parse.y"
    {
			(yyval.node) = Qnil;
		    }
    break;

  case 195:
#line 1024 "parse.y"
    {
			(yyval.node) = list_concat((yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node));
		    }
    break;

  case 196:
#line 1029 "parse.y"
    {
			(yyval.node) = NEW_LIST((yyvsp[(1) - (3)].node));
			(yyval.node) = list_append((yyval.node), (yyvsp[(3) - (3)].node));
		    }
    break;

  case 197:
#line 1034 "parse.y"
    { (yyval.id) = CLASS; }
    break;

  case 198:
#line 1035 "parse.y"
    { (yyval.id) = MODULE; }
    break;

  case 199:
#line 1036 "parse.y"
    { (yyval.id) = DEF; }
    break;

  case 200:
#line 1037 "parse.y"
    { (yyval.id) = FUNC; }
    break;

  case 201:
#line 1038 "parse.y"
    { (yyval.id) = IF; }
    break;

  case 202:
#line 1039 "parse.y"
    { (yyval.id) = UNLESS; }
    break;

  case 203:
#line 1040 "parse.y"
    { (yyval.id) = CASE; }
    break;

  case 204:
#line 1041 "parse.y"
    { (yyval.id) = WHILE; }
    break;

  case 205:
#line 1042 "parse.y"
    { (yyval.id) = UNTIL; }
    break;

  case 206:
#line 1043 "parse.y"
    { (yyval.id) = FOR; }
    break;

  case 207:
#line 1044 "parse.y"
    { (yyval.id) = DO; }
    break;

  case 208:
#line 1045 "parse.y"
    { (yyval.id) = PROTECT; }
    break;

  case 209:
#line 1046 "parse.y"
    { (yyval.id) = Qnil;}
    break;

  case 214:
#line 1054 "parse.y"
    { yyerrok; }
    break;

  case 215:
#line 1055 "parse.y"
    { yyerrok; }
    break;

  case 216:
#line 1057 "parse.y"
    { yyerrok; }
    break;

  case 217:
#line 1058 "parse.y"
    { yyerrok; }
    break;

  case 218:
#line 1059 "parse.y"
    { yyerrok; }
    break;

  case 219:
#line 1060 "parse.y"
    { yyerrok; }
    break;

  case 220:
#line 1061 "parse.y"
    { yyerrok; }
    break;


/* Line 1267 of yacc.c.  */
#line 3463 "parse.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;


  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse look-ahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
	{
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
	}
      else
	{
	  yydestruct ("Error: discarding",
		      yytoken, &yylval);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse look-ahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


#line 1062 "parse.y"


#include <stdio.h>
#include <ctype.h>
#include <sys/types.h>
#include "regex.h"

#define is_identchar(c) ((c)!=-1&&(isalnum(c) || (c) == '_' || ismbchar(c)))

static char *tokenbuf = NULL;
static int   tokidx, toksiz = 0;

__r49_required_change_r(char, void) *xmalloc();
__r49_required_change_r(char, void) *xrealloc();
VALUE newregexp();
VALUE newstring();
VALUE newfloat();
VALUE newinteger();
char *strdup();

#define EXPAND_B 1
#define LEAVE_BS 2

static void read_escape();

char *sourcefile;		/* current source file */
int   sourceline;		/* current line no. */

static char *lex_p;
static int lex_len;

__r49_void_return
lex_setsrc(src, ptr, len)
    char *src;
    char *ptr;
    int len;
{
    sourcefile = (char*)strdup(src);

    sourceline = 1;
    lex_p = ptr;
    lex_len = len;
}

#define nextc() ((--lex_len>=0)?(*lex_p++):-1)
#define pushback() (lex_len++, lex_p--)

#define tokfix() (tokenbuf[tokidx]='\0')
#define tok() tokenbuf
#define toklen() tokidx
#define toknow() &toknbuf[tokidx]

char *
newtok()
{
    tokidx = 0;
    if (!tokenbuf) {
	toksiz = 60;
	tokenbuf = ALLOC_N(char, 60);
    }
    if (toksiz > 1024) {
	REALLOC_N(tokenbuf, char, 60);
    }
    return tokenbuf;
}

void
tokadd(c)
    char c;
{
    if (tokidx >= toksiz) {
	toksiz *= 2;
	REALLOC_N(tokenbuf, char, toksiz);
    }
    tokenbuf[tokidx++] = c;
}

#ifdef __r49_required_change /* __r49: TODO: is this required change? it used to be "ubfix" whatever that is */
# define LAST(v) (&v[-1 + sizeof(v)/sizeof(v[0])])
#else
# define LAST(v) ((v)-1 + sizeof(v)/sizeof(v[0]))
#endif /* __r49_required_change */

static struct kwtable {
    char *name;
    int id;
    int state;
} kwtable [] = {
    "__END__",  0,             KEEP_STATE,
    "break",	BREAK,		EXPR_END,
    "case",	CASE,		KEEP_STATE,
    "class",	CLASS,		KEEP_STATE,
    "continue", CONTINUE,	EXPR_END,
    "def",	DEF,		KEEP_STATE,
    "do",	DO,		KEEP_STATE,
    "else",	ELSE,		EXPR_BEG,
    "elsif",	ELSIF,		EXPR_BEG,
    "end",	END,		EXPR_END,
    "ensure",	ENSURE,		EXPR_BEG,
    "for", 	FOR,		KEEP_STATE,
    "func", 	FUNC,		KEEP_STATE,
    "if",	IF,		KEEP_STATE,
    "in",	IN,		EXPR_BEG,
    "include",	INCLUDE,	EXPR_BEG,
    "module",	MODULE,		KEEP_STATE,
    "nil",	NIL,		EXPR_END,
    "protect",	PROTECT,	KEEP_STATE,
    "redo",	REDO,		EXPR_END,
    "resque",	RESQUE,		EXPR_BEG,
    "retry",	RETRY,		EXPR_END,
    "return",	RETURN,		EXPR_MID,
    "self",	SELF,		EXPR_END,
    "super",	SUPER,		EXPR_END,
    "then",     THEN,           EXPR_BEG,
    "undef",	UNDEF,		EXPR_BEG,
    "unless",	UNLESS,		__r49_bugfix_r(EXPR_BEG, KEEP_STATE), /* without this, there's no `end unless` */
    "until",	UNTIL,		EXPR_BEG,
    "using",	USING,		KEEP_STATE,
    "when",	WHEN,		EXPR_BEG,
    "while",	WHILE,		KEEP_STATE,
    "yield",	YIELD,		EXPR_BEG,
};

__r49_implicit(int)
yylex()
{
    register int c;
    struct kwtable *low = kwtable, *mid, *high = LAST(kwtable);
    int last;

    if (in_regexp) {
	int in_brack = 0;
	int re_start = sourceline;

	in_regexp = 0;
	newtok();
	while (c = nextc()) {
	    switch (c) {
	      case '[':
		in_brack = 1;
		break;
	      case ']':
		in_brack = 0;
		break;
	      case '\\':
		if ((c = nextc()) == -1) {
		    sourceline = re_start;
		    Error("unterminated regexp meets end of file");
		    return 0;
		}
		else if (c == '\n') {
		    sourceline++;
		}
		else if (in_brack && c == 'b') {
		    tokadd('\b');
		}
		else {
		    pushback();
		    read_escape(LEAVE_BS);
		}
		continue;

	      case '/':		/* end of the regexp */
		if (in_brack)
		    break;

		tokfix();
		yylval.val = regexp_new(tok(), toklen());
		lex_state = EXPR_END;
		return REGEXP;

	      case -1:
		Error("unterminated regexp");
		return 0;

	      default:
		if (ismbchar(c)) {
		    tokadd(c);
		    c = nextc();
		}
		break;
	    }
	    tokadd(c);
	}
    }

retry:
    switch (c = nextc()) {
      case '\0':
      case '\004':
      case '\032':
      case -1:			/* end of script. */
	return 0;

	/* white spaces */
      case ' ': case '\t': case '\f': case '\r':
	goto retry;

      case '#':		/* it's a comment */
	while ((c = nextc()) != '\n') {
	    if (c == -1)
		return 0;
	}
	/* fall through */
      case '\n':
	sourceline++;
	if (lex_state == EXPR_BEG) goto retry;
	lex_state = EXPR_BEG;
	return '\n';

      case '*':
	lex_state = EXPR_BEG;
	if ((c = nextc()) == '*') {
	    if (nextc() == '=') {
		yylval.id = POW;
		return SELF_ASGN;
	    }
	    pushback();
	    return POW;
	}
	else if (c == '=') {
	    yylval.id = '*';
	    return SELF_ASGN;
	}
	pushback();
	return '*';

      case '!':
	lex_state = EXPR_BEG;
	if ((c = nextc()) == '=') {
	    return NEQ;
	}
	if (c == '~') {
	    return NMATCH;
	}
	pushback();
	return '!';

      case '=':
	lex_state = EXPR_BEG;
	if ((c = nextc()) == '=') {
	    return EQ;
	}
	if (c == '~') {
	    return MATCH;
	}
	else if (c == '>') {
	    return ASSOC;
	}
	pushback();
	return '=';

      case '<':
	lex_state = EXPR_BEG;
	if ((c = nextc()) == '=') {
	    if ((c = nextc()) == '>') {
		return CMP;
	    }
	    pushback();
	    return LEQ;
	}
	if (c == '<') {
	    if (nextc() == '=') {
		yylval.id = LSHFT;
		return SELF_ASGN;
	    }
	    pushback();
	    return LSHFT;
	}
	pushback();
	return '<';

      case '>':
	lex_state = EXPR_BEG;
	if ((c = nextc()) == '=') {
	    return GEQ;
	}
	if (c == '>') {
	    if (nextc() == '=') {
		yylval.id = RSHFT;
		return SELF_ASGN;
	    }
	    pushback();
	    return RSHFT;
	}
	pushback();
	return '>';

      case '"':
	{
	    int strstart = sourceline;

	    newtok();
	    while ((c = nextc()) != '"') {
		if (c  == -1) {
		    sourceline = strstart;
		    Error("unterminated string meets end of file");
		    return 0;
		}
		if (ismbchar(c)) {
		    tokadd(c);
		    c = nextc();
		}
		else if (c == '\n') {
		    sourceline++;
		}
		else if (c == '\\') {
		    c = nextc();
		    if (c == '\n') {
			sourceline++;
		    }
		    else if (c == '"') {
			tokadd(c);
		    }
		    else {
			pushback();
			read_escape(LEAVE_BS | EXPAND_B);
		    }
		    continue;
		}
		tokadd(c);
	    }
	    tokfix();
	    yylval.val = str_new(tok(), toklen());
	    lex_state = EXPR_END;
	    return STRING;
	}

      case '\'':
	{
	    int strstart = sourceline;

	newtok();
	    while ((c = nextc()) != '\'') {
		if (c  == -1) {
		    sourceline = strstart;
		    Error("unterminated string meets end of file");
		    return 0;
		}
		if (ismbchar(c)) {
		    tokadd(c);
		    c = nextc();
		}
		else if (c == '\n') {
		    sourceline++;
		}
		else if (c == '\\') {
		    c = nextc();
		    switch (c) {
		      case '\n':
			sourceline++;
			continue;

		      case '\'':
			c = '\'';
			break;
		      case '\\':
			c = '\\';
			break;

		      default:
			tokadd('\\');
		    }
		}
		tokadd(c);
	    }
	    tokfix();
	    yylval.val = str_new(tok(), toklen());
	    lex_state = EXPR_END;
	    return STRING;
	}

      case '?':
	if ((c = nextc()) == '\\') {
	    newtok();
	    read_escape(EXPAND_B);
	    c = tok()[0];
	}
	c &= 0xff;
	yylval.val = INT2FIX(c);
	lex_state = EXPR_END;
	return INTEGER;

      case '&':
	lex_state = EXPR_BEG;
	if ((c = nextc()) == '&') {
	    return AND;
	}
	else if (c == '=') {
	    yylval.id = '&';
	    return SELF_ASGN;
	}
	pushback();
	return '&';

      case '|':
	lex_state = EXPR_BEG;
	if ((c = nextc()) == '|') {
	    return OR;
	}
	else if (c == '=') {
	    yylval.id = '|';
	    return SELF_ASGN;
	}
	pushback();
	return '|';

      case '+':
	if (lex_state == EXPR_BEG || lex_state == EXPR_MID) {
	    c = nextc();
	    pushback();
	    if (isdigit(c)) {
		__r49_bugfix_q(c = nextc();) /* __r49: without this, leading digit is repeated */
		goto start_num;
	    }
	}
	lex_state = EXPR_BEG;
	if ((c = nextc()) == '=') {
	    yylval.id = '+';
	    return SELF_ASGN;
	}
	pushback();
	return '+';

      case '-':
	if (lex_state == EXPR_BEG || lex_state == EXPR_MID) {
	    c = nextc();
	    pushback();
	    if (isdigit(c)) {
		c = '-';
		goto start_num;
	    }
	}
	lex_state = EXPR_BEG;
	if ((c = nextc()) == '=') {
	    yylval.id = '-';
	    return SELF_ASGN;
	}
	pushback();
	return '-';

      case '.':
	if ((c = nextc()) == '.') {
	    if ((c = nextc()) == '.') {
		return DOT3;
	    }
	    pushback();
	    lex_state = EXPR_BEG;
	    return DOT2;
	}
	pushback();
	if (!isdigit(c)) {
	    lex_state = EXPR_BEG;
	    return '.';
	}
	c = '.';
	/* fall through */

      start_num:
      case '0': case '1': case '2': case '3': case '4':
      case '5': case '6': case '7': case '8': case '9':
	{
	    int is_float, seen_point, seen_e;

	    lex_state = EXPR_END;
	    newtok();
	    if (c == '0') {
		c = nextc();
		if (c == 'x' || c == 'X') {
		    /* hexadecimal */
		    while (c = nextc()) {
			if (!isxdigit(c)) break;
			tokadd(c);
		    }
		    pushback();
		    tokfix();
		    yylval.val = str2inum(tok(), 16);
		    return INTEGER;
		}
		else if (c >= '0' && c <= '9') {
		    /* octal */
		    do {
			tokadd(c);
			c = nextc();
		    } while (c >= '0' && c <= '9');
		    pushback();
		    tokfix();
#if 0
		    yylval.val = INT2FIX(strtoul(tok(), Qnil, 8));
#else
		    yylval.val = str2inum(tok(), 8);
#endif
		    return INTEGER;
		}
	    }
	    if (c == '-' || c == '+') {
		tokadd(c);
		c = nextc();
	    }

	    is_float = seen_point = seen_e = 0;

	    for (;;) {
		switch (c) {
		  case '0': case '1': case '2': case '3': case '4':
		  case '5': case '6': case '7': case '8': case '9':
		    tokadd(c);
		    break;

		  case '.':
		    if (seen_point) {
			goto decode_num;
		    }
		    c = nextc();
		    if (!isdigit(c)) {
			pushback();
			goto decode_num;
		    }
		    tokadd('.');
		    tokadd(c);
		    is_float++;
		    seen_point++;
		    break;

		  case 'e':
		  case 'E':
		    if (seen_e) {
			goto decode_num;
		    }
		    tokadd(c);
		    seen_e++;
		    is_float++;
		    if ((c = nextc()) == '-' || c == '+')
			tokadd(c);
		    else
			continue;
		    break;

		  case '_':	/* `_' in decimal just ignored */
		    break;

		  default:
		    goto decode_num;
		}
		c = nextc();
	    }

	  decode_num:
	    pushback();
	    tokfix();
	    if (is_float) {
		double atof();

		yylval.val = float_new(atof(tok()));
		return FLOAT;
	    }
	    yylval.val = str2inum(tok(), 10);
	    return INTEGER;
	}

      case ']':
      case '}':
      case ')':
	lex_state = EXPR_END;
	return c;

      case ':':
	lex_state = EXPR_BEG;
	if (nextc() == ':') {
	    return COLON2;
	}
	pushback();
	return ':';

      case '/':
	lex_state = EXPR_BEG;
	if (nextc() == '=') {
	    yylval.id = '/';
	    return SELF_ASGN;
	}
	pushback();
	return c;

      case '^':
	lex_state = EXPR_BEG;
	if (nextc() == '=') {
	    yylval.id = '^';
	    return SELF_ASGN;
	}
	pushback();
	return c;

      case ',':
      case ';':
      case '`':
      case '[':
      case '(':
      case '{':
      case '~':
	lex_state = EXPR_BEG;
	return c;

      case '\\':
	c = nextc();
	if (c == '\n') goto retry; /* skip \\n */
	lex_state = EXPR_BEG;
	pushback();
	return '\\';

      case '%':
	if (lex_state == EXPR_BEG || lex_state == EXPR_MID) {
#ifdef __r49_bugfix /* fix `%` being parsed as a constant when it shouldnt be */
	    int __r49_is_constant = isalnum(nextc());
	    pushback();
	    if (!__r49_is_constant) goto __r49_not_a_constant;
#endif
	    /* class constant */
	    newtok();
	    tokadd('%');
	    c = nextc();
	    break;
	}
	else {
	__r49_bugfix_q(__r49_not_a_constant:)
	    lex_state = EXPR_BEG;
	    if (nextc() == '=') {
		yylval.id = '%';
		return SELF_ASGN;
	    }
	    pushback();
	    return c;
	}

      case '$':
	newtok();
	tokadd(c);
	c = nextc();
	switch (c) {
	  case '*':		/* $*: argv */
	  case '$':		/* $$: pid */
	  case '?':		/* $?: last status */
	  case '!':		/* $!: error string */
	  case '@':		/* $@: error position */
	  case '/':		/* $/: input record separator */
	  case '\\':		/* $\: output record separator */
	  case ',':		/* $,: output field separator */
	  case '.':		/* $.: last read line number */
	  case '_':		/* $_: last read line string */
	  case '&':		/* $&: last match */
	  case '~':		/* $~: match-data */
	  case '=':		/* $=: ignorecase */
	  __r49_bugfix_q(case ';': /* $;: field separator */)
	    tokadd(c);
	    tokadd('\0');
	    goto id_fetch;

	  default:
	    if (is_identchar(c))
		break;
	    pushback();
	    return tok()[0];
	}
	break;

      case '@':
	c = nextc();
	if (!is_identchar(c)) {
	    pushback();
	    return '@';
	}
	newtok();
	tokadd('@');
	break;

      default:
	if (c != '_' && !isalpha(c) && !ismbchar(c)) {
	    Error("Invalid char '%c' in expression", c);
	    goto retry;
	}

	newtok();
	break;
    }

    while (is_identchar(c)) {
	tokadd(c);
	if (ismbchar(c)) {
	    c = nextc();
	    tokadd(c);
	}
	c = nextc();
    }
    pushback();
    tokfix();

    /* See if it is a reserved word.  */
    while (low <= high) {
	mid = low + (high - low)/2;
	if (( c = strcmp(mid->name, tok())) == 0) {
	    if (mid->state != KEEP_STATE) {
		lex_state = mid->state;
	    }
	    return mid->id;
	}
	else if (c < 0) {
	    low = mid + 1;
	}
	else {
	    high = mid - 1;
	}
    }

  id_fetch:
    lex_state = EXPR_END;
    yylval.id = rb_intern(tok());
    switch (tok()[0]) {
      case '%':
	return CONSTANT;
      case '$':
	return GVAR;
      case '@':
	return IVAR;
      default:
	return IDENTIFIER;
    }
}

static void
read_escape(flag)
    int flag;
{
    char c;

    switch (c = nextc()) {
      case '\\':	/* Backslash */
	tokadd('\\');
	break;

      case 'n':	/* newline */
	tokadd('\n');
	break;

      case 't':	/* horizontal tab */
	tokadd('\t');
	break;

      case 'r':	/* carriage-return */
	tokadd('\r');
	break;

      case 'f':	/* form-feed */
	tokadd('\r');
	break;

      case 'v':	/* vertical tab */
	tokadd('\13');
	break;

      case 'a':
	tokadd('\a');
	break;

      case 'e':	/* escape */
	tokadd(033);
	break;

      case 'M':
	if ((c = nextc()) != '-') {
	    Error("Invalid escape character syntax");
	    tokadd('\0');
	    return;
	}
	if ((c = nextc()) == '\\') {
	    read_escape(flag);
	    tokenbuf[tokidx-1] |= 0200; /* kludge */
	}
	else {
	    tokadd((c & 0xff) | 0200);
	}
	break;

      case 'C':
	if ((c = nextc()) != '-') {
	    Error("Invalid escape character syntax");
	    tokadd('\0');
	    return;
	}
    case '^':
	if ((c = nextc())== '\\') {
	    read_escape (flag);
	    tokenbuf[tokidx-1] &= 0237; /* kludge */
	}
	else if (c == '?')
	    tokadd(0177);
	else
	    tokadd(c & 0237);
	break;

      case '0': case '1': case '2': case '3':
      case '4': case '5': case '6': case '7':
	{	/* octal constant */
	    register int i = c - '0';
	    register int count = 0;

	    while (++count < 3) {
		if ((c = nextc()) >= '0' && c <= '7') {
		    i *= 8;
		    i += c - '0';
		}
		else {
		    pushback();
		    break;
		}
	    }
	    tokadd(i&0xff);
	}
	break;

      case 'x':	/* hex constant */
	{
	    register int i = c - '0';
	    register int count = 0;

	    while (++count < 2) {
		c = nextc();
		if ((c = nextc()) >= '0' && c <= '9') {
		    i *= 16;
		    i += c - '0';
		}
		/* For some reason there was an int cast here, which no longer is guaranteed to
		 * work in 64 bit
		 */
		else if (__r49_64bit_r((int),) index("abcdefABCDEF", (c = nextc()))) {
		    i *= 16;
		    i += toupper(c) - 'A' + 10;
		}
		else {
		    pushback();
		    break;
		}
	    }
	    tokadd(i&0xff);
	}
	break;

      case 'b':	/* backspace */
	if (flag & EXPAND_B) {
	    tokadd('\b');
	    return;
	}
	/* go turough */
      default:
	if (flag & LEAVE_BS) {
	    tokadd('\\');
	}
	tokadd(c);
	break;
    }
}

NODE*
newnode(type, a0, a1, a2)
    enum node_type type;
    NODE *a0, *a1, *a2;
{
    NODE *n = ALLOC(NODE);

    n->type = type;
    n->line = sourceline;
    n->src  = sourcefile;

    n->u1.node = a0;
    n->u2.node = a1;
    n->u3.node = a2;

    return n;
}

static NODE*
block_append(head, tail)
    NODE *head, *tail;
{
    extern __r49_64bit_int_to_value verbose;

    if (tail == Qnil) return head;
    if (head == Qnil) return tail;

    if (head->type != NODE_BLOCK)
	head = NEW_BLOCK(head);

    if (head->nd_last == Qnil) head->nd_last = head;

    if (verbose) {
	switch (head->nd_last->nd_head->type) {
	  case NODE_BREAK:
	  case NODE_CONTINUE:
	  case NODE_REDO:
	  case NODE_RETURN:
	  case NODE_RETRY:
	    Warning("statement not reached");
	    break;

	  default:
	    break;
	}
    }
    
    if (tail->type == NODE_BLOCK) {
	head->nd_last->nd_next = tail;
	head->nd_last = tail->nd_last;
    }
    else {
	head->nd_last->nd_next = NEW_BLOCK(tail);
	head->nd_last = head->nd_last->nd_next;
    }
    return head;
}

static NODE*
list_append(head, tail)
    NODE *head, *tail;
{
    if (head == Qnil) return NEW_ARRAY(tail);

    if (head->nd_last == Qnil) head->nd_last = head;

    head->nd_last->nd_next = NEW_ARRAY(tail);
    head->nd_last = head->nd_last->nd_next;
    return head;
}

static NODE*
list_concat(head, tail)
    NODE *head, *tail;
{
    NODE *last;

    if (head->type != NODE_ARRAY || tail->type != NODE_ARRAY)
	Bug("list_concat() called with non-list");

    last = (head->nd_last)?head->nd_last:head;
    last->nd_next = tail;
    head->nd_last = tail->nd_last;

    return head;
}

static NODE*
list_copy(list)
    NODE *list;
{
    NODE *tmp;

    if (list == Qnil) return Qnil;

    tmp = Qnil;
    while(list) {
	tmp = list_append(tmp, list->nd_head);
	list = list->nd_next;
    }
    return tmp;
}

void freenode(node)
    NODE *node;
{
    if (node == Qnil) return;

    switch (node->type) {
      case NODE_BLOCK:
      case NODE_ARRAY:
	freenode(node->nd_head);
	freenode(node->nd_next);
	break;
      case NODE_IF:
      case NODE_WHEN:
      case NODE_PROT:
	freenode(node->nd_cond);
	freenode(node->nd_body);
	freenode(node->nd_else);
	break;
      case NODE_CASE:
      case NODE_WHILE:
      case NODE_UNTIL:
      case NODE_AND:
      case NODE_OR:
	freenode(node->nd_head);
	freenode(node->nd_body);
	break;
      case NODE_DO:
      case NODE_FOR:
	freenode(node->nd_ibdy);
	freenode(node->nd_iter);
	break;
      case NODE_LASGN:
      case NODE_GASGN:
      case NODE_IASGN:
	freenode(node->nd_value);
	break;
      case NODE_CALL:
      case NODE_SUPER:
	freenode(node->nd_recv);
      case NODE_CALL2:
	freenode(node->nd_args);
	break;
      case NODE_DEFS:
	freenode(node->nd_recv);
	break;
      case NODE_RETURN:
      case NODE_YIELD:
	freenode(node->nd_stts);
	break;
      case NODE_STR:
      case NODE_LIT:
	unliteralize(node->nd_lit);
	break;
      case NODE_CONST:
	unliteralize(node->nd_cval);
	break;
      case NODE_ARGS:
	freenode(node->nd_frml);
	break;
      case NODE_SCOPE:
	free(node->nd_tbl);
	freenode(node->nd_body);
	break;
      case NODE_DEFN:
      case NODE_ZARRAY:
      case NODE_CFUNC:
      case NODE_BREAK:
      case NODE_CONTINUE:
      case NODE_RETRY:
      case NODE_LVAR:
      case NODE_GVAR:
      case NODE_IVAR:
      case NODE_MVAR:
      case NODE_CLASS:
      case NODE_MODULE:
      case NODE_INC:
      case NODE_NIL:
	break;

/* __r49: It looks like `load()` wasn't terribly well tested, as a lot of node
          types didn't have any `frees` corresponding to them. */
#ifdef __r49_critical_bugfix
      case NODE_CASGN:
      case NODE_UNLESS:
      case NODE_MASGN:
      case NODE_ZSUPER:
      case NODE_REDO:
      case NODE_CVAR:
      case NODE_ALIAS:
      case NODE_UNDEF:
      case NODE_DOT3:
      case NODE_ATTRSET:
      case NODE_SELF:
      case NODE_HASH:
	break; /* __r49: Leak memory lol, better than `Bug`ging. */
#endif

      default:
	Bug("freenode: unknown node type %d", node->type);
	break;
    }
    free(node);
}

struct call_arg {
    ID id;
    VALUE recv;
    int narg;
    VALUE arg;
};

static VALUE
call_lit(arg)
    struct call_arg *arg;
{
    return rb_funcall(arg->recv, arg->id, arg->narg, arg->arg);
}

static VALUE
except_lit()
{
    extern VALUE errstr;

    Error("%s", RSTRING(errstr)->ptr);
    return Qnil;
}

static NODE *
call_op(recv, id, narg, arg1)
    NODE *recv;
    ID id;
    int narg;
    NODE *arg1;
{
    NODE *args;

    value_expr(recv);
    if (narg == 1)
	value_expr(arg1);

    if (recv->type != NODE_LIT || recv->type != NODE_STR
	|| (narg == 0 && id == '~'
	    && (TYPE(recv->nd_lit)==T_REGEXP || TYPE(recv->nd_lit)==T_STRING))
	|| arg1->type == NODE_LIT || arg1->type == NODE_STR) {
	if (narg > 0) {
	    args = NEW_ARRAY(arg1);
	    args->nd_argc = 1;
	}
	else {
	    args = Qnil;
	}
	return NEW_CALL(recv, id, args);
    }
    else {
	struct call_arg arg_data;
	NODE *result;

	arg_data.recv = recv->nd_lit;
	arg_data.id = id;
	arg_data.narg = narg;
	if (narg == 1) arg_data.arg = arg1->nd_lit;
	result = NEW_LIT(rb_resque(call_lit, __r49_cast_to_charp(struct call_arg, &arg_data), except_lit, Qnil));
	freenode(recv);
	if (narg == 1) freenode(arg1);
	return result;
    }
}

static NODE*
asignable(id, val)
    ID id;
    NODE *val;
{
    NODE *lhs;

    if (id == SELF) {
	lhs = Qnil;
	Error("Can't change the value of self");
    }
    else if (id == NIL) {
	lhs = Qnil;
	Error("Can't asign to nil");
    }
    else if (is_local_id(id)) {
	lhs = NEW_LASGN(id, val);
    }
    else if (is_global_id(id)) {
	lhs = NEW_GASGN(id, val);
    }
    else if (is_instance_id(id)) {
	lhs = NEW_IASGN(id, val);
    }
    else if (is_const_id(id)) {
	if (cur_mid || in_single)
	    Error("class constant asigned in method body");
	lhs = NEW_CASGN(id, val);
    }
    else {
	Bug("bad id for variable");
    }
    return lhs;
}

static NODE *
aryset(recv, idx, val)
    NODE *recv, *idx, *val;
{
    NODE *args;

    value_expr(recv);
    return NEW_CALL(recv, ASET, list_append(idx, val));
}

static NODE *
attrset(recv, id, val)
    NODE *recv, *val;
    ID id;
{
    value_expr(recv);

    id &= ~ID_SCOPE_MASK;
    id |= ID_ATTRSET;

    return NEW_CALL(recv, id, NEW_ARRAY(val));
}

static void
value_expr(node)
    NODE *node;
{
    switch (node->type) {
      case NODE_RETURN:
      case NODE_CONTINUE:
      case NODE_BREAK:
      case NODE_REDO:
      case NODE_RETRY:
	Error("void value expression");
	break;

      case NODE_BLOCK:
	if (node->nd_last)
	    return value_expr(node->nd_last->nd_head);
	break;

      default:
	break;
    }
}

static NODE*
cond(node)
    NODE *node;
{
    value_expr(node);
    if (node->type == NODE_STR) {
	return call_op(NEW_GVAR(rb_intern("$_")),MATCH,1,node);
    }
    else if (node->type == NODE_LIT && TYPE(node->nd_lit) == T_REGEXP) {
	return call_op(node,MATCH,1,NEW_GVAR(rb_intern("$_")));
    }
    return node;
}

static NODE*
cond2(node)
    NODE *node;
{
    node = cond(node);
    if (node->type == NODE_LIT) {
	if (FIXNUM_P(node->nd_lit)) {
	    return call_op(node,EQ,1,NEW_GVAR(rb_intern("$.")));
	}
    }
    return node;
}

st_table *new_idhash();

static struct local_vars {
    ID *tbl;
    int cnt;
    struct local_vars *next;
} *lvtbl;

static void
push_local()
{
    struct local_vars *local;

    local = ALLOC(struct local_vars);
    local->next = lvtbl;
    local->cnt = 0;
    local->tbl = Qnil;
    lvtbl = local;
}

void
pop_local()
{
    struct local_vars *local = lvtbl;

    lvtbl = local->next;
    if (local->tbl) local->tbl[0] = local->cnt;
    free(local);
}

static ID*
local_tbl()
{
    return lvtbl->tbl;
}

static int
local_cnt(id)
    ID id;
{
    int cnt, max;

    if (id == 0) return lvtbl->cnt;

    for (cnt=0, max=lvtbl->cnt; cnt<max ;cnt++) {
	if (lvtbl->tbl[cnt+1] == id) return cnt;
    }

    if (lvtbl->tbl == Qnil)
	lvtbl->tbl = ALLOC_N(ID, 2);
    else
	REALLOC_N(lvtbl->tbl, ID, lvtbl->cnt+2);

    lvtbl->tbl[lvtbl->cnt+1] = id;
    return lvtbl->cnt++;
}

static int
local_id(id)
    ID id;
{
    int i, max;

    if (lvtbl == Qnil) return FALSE;
    for (i=1, max=lvtbl->cnt+1; i<max; i++) {
	if (lvtbl->tbl[i] == id) return TRUE;
    }
    return FALSE;
}

static void
init_top_local()
{
    if (lvtbl == Qnil) {
	push_local();
    }
    else if (the_env->local_tbl) {
	lvtbl->cnt = the_env->local_tbl[0];
    }
    else {
	lvtbl->cnt = 0;
    }
    lvtbl->tbl = the_env->local_tbl;
}

static void
setup_top_local()
{
    if (lvtbl->cnt > 0) {
	if (the_env->local_vars == Qnil) {
	    the_env->local_vars = ALLOC_N(VALUE, lvtbl->cnt);
	    bzero(the_env->local_vars, lvtbl->cnt * sizeof(VALUE));
	}
	else {
	    int i;

	    REALLOC_N(the_env->local_vars, VALUE, lvtbl->cnt);
	    for (i=lvtbl->tbl[0]; i<lvtbl->cnt; i++) {
		the_env->local_vars[i] = Qnil;
	    }
	}
	lvtbl->tbl[0] = lvtbl->cnt;
	the_env->local_tbl = lvtbl->tbl;
    }
    else {
	the_env->local_vars = Qnil;
    }
}

void
yyappend_print()
{
    eval_tree =
	block_append(eval_tree, NEW_CALL(Qnil, rb_intern("print"),
					 NEW_ARRAY(NEW_GVAR(rb_intern("$_")))));
}

void
yywhole_loop(chop, split)
    int chop, split;
{
    if (split) {
	eval_tree =
	    block_append(NEW_GASGN(rb_intern("$F"),
				   NEW_CALL(NEW_GVAR(rb_intern("$_")),
					    rb_intern("split"), Qnil)),
				   eval_tree);
    }
    if (chop) {
	eval_tree =
	    block_append(NEW_CALL(NEW_GVAR(rb_intern("$_")),
				  rb_intern("chop"), Qnil), eval_tree);
    }
    eval_tree = NEW_WHILE(NEW_CALL(0,rb_intern("gets"),0),eval_tree);
}

static struct op_tbl rb_op_tbl[] = {
    DOT2,	"..",
    '+',	"+",
    '-',	"-",
    '+',	"+(binary)",
    '-',	"-(binary)",
    '*',	"*",
    '/',	"/",
    '%',	"%",
    POW,	"**",
    UPLUS,	"+(unary)",
    UMINUS,	"-(unary)",
    UPLUS,	"+@",
    UMINUS,	"-@",
    '|',	"|",
    '^',	"^",
    '&',	"&",
    CMP,	"<=>",
    '>',	">",
    GEQ,	">=",
    '<',	"<",
    LEQ,	"<=",
    EQ,		"==",
    NEQ,	"!=",
    MATCH,	"=~",
    NMATCH,	"!~",
    '!',	"!",
    '~',	"~",
    '!',	"!(unary)",
    '~',	"~(unary)",
    '!',	"!@",
    '~',	"~@",
    AREF,	"[]",
    ASET,	"[]=",
    LSHFT,	"<<",
    RSHFT,	">>",
    COLON2,	"::",
    Qnil,	Qnil,
};

char *rb_id2name();
char *rb_class2name();

st_table *rb_symbol_tbl;

#define sym_tbl rb_symbol_tbl

void
Init_sym()
{
    int strcmp();

    sym_tbl = st_init_table(strcmp, st_strhash);
}

ID
rb_intern(name)
    char *name;
{
    static ID last_id = LAST_TOKEN;
    __r49_required_change_r(int, ID) id;
    int last;

    if (st_lookup(sym_tbl, name, __r49_cast_to_charpp(__r49_required_change_r(int, ID), &id)))
	return id;

    id = ++last_id;
    id <<= 3;
    switch (name[0]) {
      case '$':
	id |= ID_GLOBAL;
	break;
      case '@':
	id |= ID_INSTANCE;
	break;
      case '%':
	if (name[1] != '\0') {
	    id |= ID_CONST;
	    break;
	}
	/* fall through */
      default:
	if (name[0] != '_' && !isalpha(name[0]) && !ismbchar(name[0])) {
	    /* operator */
	    int i;

	    id = Qnil;
	    for (i=0; rb_op_tbl[i].tok; i++) {
		if (strcmp(rb_op_tbl[i].name, name) == 0) {
		    id = rb_op_tbl[i].tok;
		    break;
		}
	    }
	    if (id == Qnil) Bug("Unknown operator `%s'", name);
	    break;
	}
	last = strlen(name)-1;
	if (name[last] == '=') {
	    /* attribute asignment */
	    char *buf = (char*)alloca(last+1);

	    strncpy(buf, name, last);
	    buf[last] = '\0';
	    id = rb_intern(buf);
	    id &= ~ID_SCOPE_MASK;
	    id |= ID_ATTRSET;
	}
	else {
	    id |= ID_LOCAL;
	}
	break;
    }
    st_add_direct(sym_tbl, strdup(name), id);
    return id;
}

static char *find_ok;

static __r49_implicit(enum st_retval)
id_find(name, id1, id2)
    char *name;
    ID id1, id2;
{
    if (id1 == id2) {
	find_ok = name;
	return ST_STOP;
    }
    return ST_CONTINUE;
}

char *
rb_id2name(id)
    ID id;
{
    find_ok = Qnil;

    if (id < LAST_TOKEN) {
	int i = 0;

	for (i=0; rb_op_tbl[i].tok; i++) {
	    if (rb_op_tbl[i].tok == id)
		return rb_op_tbl[i].name;
	}
    }

    st_foreach(sym_tbl, id_find, id);
    if (!find_ok && is_attrset_id(id)) {
	char *res;
	ID id2; 

	id2 = (id & ~ID_SCOPE_MASK) | ID_LOCAL;
	res = rb_id2name(id2);

	if (res) {
	    char *buf = (char*)alloca(strlen(res)+2);

	    strcpy(buf, res);
	    strcat(buf, "=");
	    rb_intern(buf);
	    return rb_id2name(id);
	}
    }
    return find_ok;
}

char *
rb_class2name(class)
    struct RClass *class;
{
    extern st_table *rb_class_tbl;

    find_ok = Qnil;

    switch (TYPE(class)) {
      case T_CLASS:
      case T_MODULE:
      case T_ICLASS:
	break;
      default:
	Fail("0x%x is not a class/module", class);
    }

    while (FL_TEST(class, FL_SINGLE)) {
	class = (struct RClass*)class->super;
    }

    st_foreach(rb_class_tbl, id_find, class);
    if (find_ok) {
	return rb_id2name((ID)find_ok);
    }
    Bug("class 0x%x not named", class);
}

