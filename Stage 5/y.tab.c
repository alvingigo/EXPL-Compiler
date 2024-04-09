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
     PLUS = 258,
     MINUS = 259,
     MUL = 260,
     DIV = 261,
     START = 262,
     END = 263,
     READ = 264,
     WRITE = 265,
     VAR = 266,
     STRVAL = 267,
     NUM = 268,
     ASSIGN = 269,
     IF = 270,
     ELSE = 271,
     WHILE = 272,
     THEN = 273,
     ENDIF = 274,
     ENDWHILE = 275,
     DO = 276,
     BREAK = 277,
     CONTINUE = 278,
     LT = 279,
     GT = 280,
     LE = 281,
     GE = 282,
     EQ = 283,
     NEQ = 284,
     AND = 285,
     OR = 286,
     DECL = 287,
     ENDDECL = 288,
     INT = 289,
     STR = 290,
     RETURN = 291,
     MAIN = 292
   };
#endif
/* Tokens.  */
#define PLUS 258
#define MINUS 259
#define MUL 260
#define DIV 261
#define START 262
#define END 263
#define READ 264
#define WRITE 265
#define VAR 266
#define STRVAL 267
#define NUM 268
#define ASSIGN 269
#define IF 270
#define ELSE 271
#define WHILE 272
#define THEN 273
#define ENDIF 274
#define ENDWHILE 275
#define DO 276
#define BREAK 277
#define CONTINUE 278
#define LT 279
#define GT 280
#define LE 281
#define GE 282
#define EQ 283
#define NEQ 284
#define AND 285
#define OR 286
#define DECL 287
#define ENDDECL 288
#define INT 289
#define STR 290
#define RETURN 291
#define MAIN 292




/* Copy the first part of user declarations.  */
#line 1 "exprtree.y"

    #include <stdio.h>
    #include <stdlib.h>

    #include "symboltable.h"
    #include "symboltable.c"
    #include "tasktree.h"
    #include "typecheck.h"
    #include "tasktree.c"
    #include "codegen.c"
    #include "evaluvate.c"
    #include "typecheck.c"
   
    int yylex(void);
    int g=0;
     void yyerror(char const *s);
     void typecheck(int t1,int t2,char c);
     void assignType(struct tnode* node, int type);
    extern FILE *yyin;
    FILE *fp;
    FILE *intermediate;
    int declarationtype,FDeclarationType;
    struct ParamList* argList1=NULL,*argList2=NULL;


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
#line 26 "exprtree.y"
{
    struct tnode* no;
    
}
/* Line 193 of yacc.c.  */
#line 200 "y.tab.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 213 "y.tab.c"

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
#define YYFINAL  10
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   366

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  46
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  33
/* YYNRULES -- Number of rules.  */
#define YYNRULES  80
/* YYNRULES -- Number of states.  */
#define YYNSTATES  175

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   292

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      42,    43,     2,     2,    38,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    39,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    40,     2,    41,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    44,     2,    45,     2,     2,     2,     2,
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
      35,    36,    37
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     7,    11,    14,    15,    18,    20,    24,
      26,    28,    30,    32,    36,    38,    43,    45,    50,    53,
      55,    56,    66,    70,    72,    73,    76,    80,    83,    84,
      87,    89,    93,    97,    99,   104,   108,   112,   121,   124,
     126,   128,   130,   132,   134,   136,   138,   140,   143,   149,
     155,   160,   171,   180,   189,   198,   201,   204,   208,   210,
     211,   215,   219,   223,   227,   231,   235,   239,   243,   247,
     251,   255,   259,   263,   265,   267,   269,   271,   276,   278,
     283
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      47,     0,    -1,    48,    55,    65,    -1,    32,    49,    33,
      -1,    32,    33,    -1,    -1,    49,    50,    -1,    50,    -1,
      51,    53,    39,    -1,    34,    -1,    35,    -1,    34,    -1,
      35,    -1,    53,    38,    54,    -1,    54,    -1,    11,    40,
      13,    41,    -1,    11,    -1,    11,    42,    57,    43,    -1,
      55,    56,    -1,    56,    -1,    -1,    51,    11,    42,    57,
      43,    44,    59,    63,    45,    -1,    57,    38,    58,    -1,
      58,    -1,    -1,    52,    11,    -1,    32,    60,    33,    -1,
      32,    33,    -1,    -1,    60,    61,    -1,    61,    -1,    52,
      62,    39,    -1,    62,    38,    62,    -1,    11,    -1,     7,
      66,    64,     8,    -1,     7,    64,     8,    -1,    36,    76,
      39,    -1,    51,    37,    42,    43,    44,    59,    63,    45,
      -1,    66,    67,    -1,    67,    -1,    68,    -1,    69,    -1,
      70,    -1,    71,    -1,    72,    -1,    73,    -1,    74,    -1,
      77,    39,    -1,     9,    42,    78,    43,    39,    -1,    10,
      42,    76,    43,    39,    -1,    78,    14,    76,    39,    -1,
      15,    42,    76,    43,    18,    66,    16,    66,    19,    39,
      -1,    15,    42,    76,    43,    18,    66,    19,    39,    -1,
      17,    42,    76,    43,    21,    66,    20,    39,    -1,    21,
      66,    17,    42,    76,    43,    20,    39,    -1,    22,    39,
      -1,    23,    39,    -1,    75,    38,    76,    -1,    76,    -1,
      -1,    76,     3,    76,    -1,    76,     4,    76,    -1,    76,
       5,    76,    -1,    76,     6,    76,    -1,    76,    24,    76,
      -1,    76,    25,    76,    -1,    76,    28,    76,    -1,    76,
      29,    76,    -1,    76,    27,    76,    -1,    76,    26,    76,
      -1,    76,    30,    76,    -1,    76,    31,    76,    -1,    42,
      76,    43,    -1,    13,    -1,    78,    -1,    77,    -1,    12,
      -1,    11,    42,    75,    43,    -1,    11,    -1,    11,    40,
      76,    41,    -1,    11,    40,    78,    41,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    54,    54,    59,    60,    61,    64,    65,    68,    71,
      72,    74,    75,    77,    78,    81,    82,    83,    91,    92,
      93,    96,   152,   153,   154,   157,   161,   162,   163,   166,
     167,   169,   172,   173,   177,   178,   181,   190,   205,   206,
     209,   210,   211,   212,   213,   214,   215,   216,   221,   223,
     225,   229,   231,   234,   236,   239,   241,   244,   247,   248,
     251,   253,   255,   257,   259,   261,   263,   265,   267,   269,
     271,   273,   275,   276,   277,   278,   279,   283,   293,   296,
     300
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "PLUS", "MINUS", "MUL", "DIV", "START",
  "END", "READ", "WRITE", "VAR", "STRVAL", "NUM", "ASSIGN", "IF", "ELSE",
  "WHILE", "THEN", "ENDIF", "ENDWHILE", "DO", "BREAK", "CONTINUE", "LT",
  "GT", "LE", "GE", "EQ", "NEQ", "AND", "OR", "DECL", "ENDDECL", "INT",
  "STR", "RETURN", "MAIN", "','", "';'", "'['", "']'", "'('", "')'", "'{'",
  "'}'", "$accept", "Program", "GDeclBlock", "GDeclList", "GDecl", "Type",
  "FType", "GIdList", "GId", "FdefBlock", "Fdef", "ParamList", "Param",
  "LdeclBlock", "LdeclList", "Ldecl", "IdList", "Body", "RetStmt",
  "MainBlock", "Slist", "Stmt", "InputStmt", "OutputStmt", "AsgStmt",
  "Ifstmt", "Whilestmt", "Breakstmt", "Contstmt", "ArgList", "expr",
  "func", "id", 0
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
     285,   286,   287,   288,   289,   290,   291,   292,    44,    59,
      91,    93,    40,    41,   123,   125
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    46,    47,    48,    48,    48,    49,    49,    50,    51,
      51,    52,    52,    53,    53,    54,    54,    54,    55,    55,
      55,    56,    57,    57,    57,    58,    59,    59,    59,    60,
      60,    61,    62,    62,    63,    63,    64,    65,    66,    66,
      67,    67,    67,    67,    67,    67,    67,    67,    68,    69,
      70,    71,    71,    72,    72,    73,    74,    75,    75,    75,
      76,    76,    76,    76,    76,    76,    76,    76,    76,    76,
      76,    76,    76,    76,    76,    76,    76,    77,    78,    78,
      78
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     3,     3,     2,     0,     2,     1,     3,     1,
       1,     1,     1,     3,     1,     4,     1,     4,     2,     1,
       0,     9,     3,     1,     0,     2,     3,     2,     0,     2,
       1,     3,     3,     1,     4,     3,     3,     8,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     2,     5,     5,
       4,    10,     8,     8,     8,     2,     2,     3,     1,     0,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     1,     1,     1,     1,     4,     1,     4,
       4
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       5,     0,     0,     0,     4,     9,    10,     0,     7,     0,
       1,     0,     0,    19,     3,     6,    16,     0,    14,     0,
       0,    18,     2,     0,    24,     0,     8,    24,     0,     0,
      11,    12,     0,     0,    23,    13,     0,     0,    15,    25,
       0,    17,     0,     0,    22,    28,    28,     0,     0,     0,
      27,     0,     0,    30,     0,     0,     0,    33,     0,    26,
      29,     0,     0,    78,     0,     0,     0,     0,     0,     0,
       0,     0,    39,    40,    41,    42,    43,    44,    45,    46,
       0,     0,    21,    37,     0,    31,     0,     0,     0,    59,
       0,     0,     0,    55,    56,    76,    73,     0,     0,    75,
      74,    35,     0,    38,    47,     0,    32,    78,     0,     0,
       0,    74,     0,    58,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      36,    34,     0,     0,     0,    79,    80,     0,    77,     0,
       0,     0,    72,    60,    61,    62,    63,    64,    65,    69,
      68,    66,    67,    70,    71,    50,    48,    49,    57,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      52,    53,    54,     0,    51
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     2,     3,     7,     8,     9,    32,    17,    18,    12,
      13,    33,    34,    48,    52,    53,    58,    55,    70,    22,
      71,    72,    73,    74,    75,    76,    77,    78,    79,   112,
      98,    99,   100
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -67
static const yytype_int16 yypact[] =
{
     -22,   -12,     7,    22,   -67,   -67,   -67,    54,   -67,    13,
     -67,    25,    22,   -67,   -67,   -67,    10,    37,   -67,    51,
      -2,   -67,   -67,    27,    36,    13,   -67,    36,    56,    38,
     -67,   -67,    90,   -27,   -67,   -67,   -25,    64,   -67,   -67,
      36,   -67,    66,    68,   -67,    86,    86,    57,   137,   137,
     -67,   150,    87,   -67,    63,   117,   118,   -67,    44,   -67,
     -67,   127,   128,    62,   143,   160,   328,   132,   164,    -9,
     196,    63,   -67,   -67,   -67,   -67,   -67,   -67,   -67,   -67,
     171,   197,   -67,   -67,   150,   -67,   201,    -9,    -9,    -9,
      -9,    -9,   343,   -67,   -67,   -67,   -67,    -9,   244,   -67,
     -67,   -67,   210,   -67,   -67,    -9,   181,   180,   178,   121,
     211,   182,   -24,   276,   129,   162,   183,   170,    -9,    -9,
      -9,    -9,    -9,    -9,    -9,    -9,    -9,    -9,    -9,    -9,
     -67,   -67,   260,   185,   187,   -67,   -67,    -9,   -67,   204,
     222,    -9,   -67,   287,   287,   112,   112,   153,   153,   153,
     153,   100,   100,   153,   153,   -67,   -67,   -67,   276,   328,
     328,   203,    32,   310,   110,   328,   205,   206,   212,   325,
     -67,   -67,   -67,   214,   -67
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -67,   -67,   -67,   -67,   247,     3,    -8,   -67,   230,   -67,
     245,   229,   218,   213,   -67,   208,   177,   227,   191,   -67,
     -65,   -66,   -67,   -67,   -67,   -67,   -67,   -67,   -67,   -67,
     -60,   -46,   -54
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_int16 yytable[] =
{
      81,    92,    63,    95,    96,   103,    11,    10,    80,    19,
       1,    40,    81,    40,   137,    20,    41,    81,    42,   138,
      80,     4,     5,     6,    16,    80,   103,   109,   110,   113,
     114,   115,   108,    97,   111,    28,    19,   117,    81,    51,
      29,    61,    62,    63,    51,   132,    80,    64,   165,    65,
      23,   166,    24,    66,    67,    68,     5,     6,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
      30,    31,    61,    62,    63,    25,    26,   158,    64,    38,
      65,   161,    84,    85,    66,    67,    68,    14,     5,     6,
      50,    30,    31,    27,   162,   163,   103,   103,    37,    69,
     169,    39,    88,   103,    89,    81,    81,    43,    81,    81,
      45,    81,    46,    80,    80,    81,    80,    80,    47,    80,
      59,    30,    31,    80,   118,   119,   120,   121,   126,   127,
     168,   160,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,    54,   122,   123,   124,   125,   126,
     127,   128,   129,   122,   123,   124,   125,   126,   127,   128,
     129,    57,    82,    83,   134,   118,   119,   120,   121,    86,
      87,    93,   139,   118,   119,   120,   121,    -1,    -1,    -1,
      -1,   126,   127,    -1,    -1,    90,   122,   123,   124,   125,
     126,   127,   128,   129,   122,   123,   124,   125,   126,   127,
     128,   129,    91,    94,   101,   140,   118,   119,   120,   121,
     104,   105,   107,   142,   118,   119,   120,   121,   131,    84,
      88,   133,   159,   136,   156,   141,   157,   122,   123,   124,
     125,   126,   127,   128,   129,   122,   123,   124,   125,   126,
     127,   128,   129,   160,   170,   171,   164,   118,   119,   120,
     121,   172,   135,   174,    15,    35,    36,    21,    44,    49,
      60,   106,   102,   118,   119,   120,   121,     0,   122,   123,
     124,   125,   126,   127,   128,   129,    56,     0,     0,   118,
     119,   120,   121,   130,   122,   123,   124,   125,   126,   127,
     128,   129,   120,   121,     0,     0,     0,     0,     0,   155,
     122,   123,   124,   125,   126,   127,   128,   129,     0,     0,
       0,   122,   123,   124,   125,   126,   127,   128,   129,    61,
      62,    63,     0,     0,     0,    64,     0,    65,     0,     0,
     167,    66,    67,    68,    61,    62,    63,    61,    62,    63,
      64,     0,    65,    64,   173,    65,    66,    67,    68,    66,
      67,    68,    61,    62,    63,     0,     0,     0,    64,     0,
     116,     0,     0,     0,    66,    67,    68
};

static const yytype_int16 yycheck[] =
{
      54,    66,    11,    12,    13,    71,     3,     0,    54,    11,
      32,    38,    66,    38,    38,    12,    43,    71,    43,    43,
      66,    33,    34,    35,    11,    71,    92,    87,    88,    89,
      90,    91,    86,    42,    88,    37,    11,    97,    92,    47,
      13,     9,    10,    11,    52,   105,    92,    15,    16,    17,
      40,    19,    42,    21,    22,    23,    34,    35,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
      34,    35,     9,    10,    11,    38,    39,   137,    15,    41,
      17,   141,    38,    39,    21,    22,    23,    33,    34,    35,
      33,    34,    35,    42,   159,   160,   162,   163,    42,    36,
     165,    11,    40,   169,    42,   159,   160,    43,   162,   163,
      44,   165,    44,   159,   160,   169,   162,   163,    32,   165,
      33,    34,    35,   169,     3,     4,     5,     6,    28,    29,
      20,    21,     3,     4,     5,     6,    24,    25,    26,    27,
      28,    29,    30,    31,     7,    24,    25,    26,    27,    28,
      29,    30,    31,    24,    25,    26,    27,    28,    29,    30,
      31,    11,    45,    45,    43,     3,     4,     5,     6,    42,
      42,    39,    43,     3,     4,     5,     6,    24,    25,    26,
      27,    28,    29,    30,    31,    42,    24,    25,    26,    27,
      28,    29,    30,    31,    24,    25,    26,    27,    28,    29,
      30,    31,    42,    39,     8,    43,     3,     4,     5,     6,
      39,    14,    11,    43,     3,     4,     5,     6,     8,    38,
      40,    43,    18,    41,    39,    42,    39,    24,    25,    26,
      27,    28,    29,    30,    31,    24,    25,    26,    27,    28,
      29,    30,    31,    21,    39,    39,    43,     3,     4,     5,
       6,    39,    41,    39,     7,    25,    27,    12,    40,    46,
      52,    84,    71,     3,     4,     5,     6,    -1,    24,    25,
      26,    27,    28,    29,    30,    31,    49,    -1,    -1,     3,
       4,     5,     6,    39,    24,    25,    26,    27,    28,    29,
      30,    31,     5,     6,    -1,    -1,    -1,    -1,    -1,    39,
      24,    25,    26,    27,    28,    29,    30,    31,    -1,    -1,
      -1,    24,    25,    26,    27,    28,    29,    30,    31,     9,
      10,    11,    -1,    -1,    -1,    15,    -1,    17,    -1,    -1,
      20,    21,    22,    23,     9,    10,    11,     9,    10,    11,
      15,    -1,    17,    15,    19,    17,    21,    22,    23,    21,
      22,    23,     9,    10,    11,    -1,    -1,    -1,    15,    -1,
      17,    -1,    -1,    -1,    21,    22,    23
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    32,    47,    48,    33,    34,    35,    49,    50,    51,
       0,    51,    55,    56,    33,    50,    11,    53,    54,    11,
      51,    56,    65,    40,    42,    38,    39,    42,    37,    13,
      34,    35,    52,    57,    58,    54,    57,    42,    41,    11,
      38,    43,    43,    43,    58,    44,    44,    32,    59,    59,
      33,    52,    60,    61,     7,    63,    63,    11,    62,    33,
      61,     9,    10,    11,    15,    17,    21,    22,    23,    36,
      64,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      77,    78,    45,    45,    38,    39,    42,    42,    40,    42,
      42,    42,    66,    39,    39,    12,    13,    42,    76,    77,
      78,     8,    64,    67,    39,    14,    62,    11,    78,    76,
      76,    78,    75,    76,    76,    76,    17,    76,     3,     4,
       5,     6,    24,    25,    26,    27,    28,    29,    30,    31,
      39,     8,    76,    43,    43,    41,    41,    38,    43,    43,
      43,    42,    43,    76,    76,    76,    76,    76,    76,    76,
      76,    76,    76,    76,    76,    39,    39,    39,    76,    18,
      21,    76,    66,    66,    43,    16,    19,    20,    20,    66,
      39,    39,    39,    19,    39
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
#line 54 "exprtree.y"
    {finalise();}
    break;

  case 3:
#line 59 "exprtree.y"
    {initialise();}
    break;

  case 4:
#line 60 "exprtree.y"
    {initialise();}
    break;

  case 6:
#line 64 "exprtree.y"
    {}
    break;

  case 7:
#line 65 "exprtree.y"
    {}
    break;

  case 8:
#line 68 "exprtree.y"
    {}
    break;

  case 9:
#line 71 "exprtree.y"
    {declarationtype=INT_TYPE;}
    break;

  case 10:
#line 72 "exprtree.y"
    {declarationtype=STR_TYPE;}
    break;

  case 11:
#line 74 "exprtree.y"
    {FDeclarationType = INT_TYPE;}
    break;

  case 12:
#line 75 "exprtree.y"
    {FDeclarationType = STR_TYPE;}
    break;

  case 15:
#line 81 "exprtree.y"
    {GInstall((yyvsp[(1) - (4)].no)->varname,declarationtype,(yyvsp[(3) - (4)].no)->val,NULL);printf("debug %d\n",g++);}
    break;

  case 16:
#line 82 "exprtree.y"
    {GInstall((yyvsp[(1) - (1)].no)->varname,declarationtype,1,NULL);printf("debug %d\n",g++);}
    break;

  case 17:
#line 83 "exprtree.y"
    {GInstall((yyvsp[(1) - (4)].no)->varname,declarationtype,-1,Phead);printf("debug %d\n",g++);
                                    Phead=NULL;
                                    Ptail=NULL;
                                }
    break;

  case 18:
#line 91 "exprtree.y"
    {}
    break;

  case 19:
#line 92 "exprtree.y"
    {}
    break;

  case 21:
#line 96 "exprtree.y"
    {Gtemp=GLookup((yyvsp[(2) - (9)].no)->varname);
                                                            printf("hskdn\n");
                                                             
                                                                if(Gtemp==NULL){
                                                                    printf("Please properly declare your functions ( %s )",(yyvsp[(2) - (9)].no)->varname);
                                                                    exit(1);
                                                                }  
                                                                else if((Gtemp->flabel)<0){
                                                                    printf("when defining function make sure you declare it as a function ( %s )",(yyvsp[(2) - (9)].no)->varname);exit(1);
                                                                }else if (Gtemp->type!=declarationtype){
                                                                    printf("Type Mismatch (%s)",(yyvsp[(2) - (9)].no)->varname);exit(1);
                                                                }
                                                                
                                                            argList1=Gtemp->param;
                                                            argList2=Phead;

                                                            while(argList1!=NULL || argList2!=NULL){
                                                                if (argList1==NULL){
                                                                    printf("function def arguments bad ( %s )",(yyvsp[(2) - (9)].no)->varname);exit(1);
                                                                }
                                                                if (argList2==NULL){
                                                                    printf("function def arguments bad ( %s )",(yyvsp[(2) - (9)].no)->varname);exit(1);
                                                                }    
                                                                if(argList1->type!=argList2->type){
                                                                    printf("function call arguments bad (type error) ( %s )",(yyvsp[(2) - (9)].no)->varname);exit(1);
                                                                }
                                                                argList1=argList1->next;
                                                                argList2=argList2->next;
                                                            }
                                                            printf("hskdn\n");


                                                            fprintf(intermediate,"F%d:\n",Gtemp->flabel);
                                                            printf("hskdn\n");
                                                            
                                                            fprintf(intermediate,"PUSH BP\n");
                                                            fprintf(intermediate,"MOV BP,SP\n");
                                                            Ltemp=Lhead;

                                                            while(Ltemp!=NULL){
                                                                if (Ltemp->binding>0){
                                                                    fprintf(intermediate,"PUSH R0\n");
                                                                }
                                                                Ltemp=Ltemp->next;
                                                            }
                                                            printf("hskdn\n");

                                    
                                                            codeGen((yyvsp[(8) - (9)].no));
                                                            Lhead=NULL;
                                                            Ltail=NULL;
                                                            Phead=NULL;
                                                            Ptail=NULL;
                                                            }
    break;

  case 25:
#line 157 "exprtree.y"
    {ParamInstall((yyvsp[(2) - (2)].no)->varname,FDeclarationType);}
    break;

  case 26:
#line 161 "exprtree.y"
    {InstallParamsInLocal();}
    break;

  case 27:
#line 162 "exprtree.y"
    {InstallParamsInLocal();}
    break;

  case 28:
#line 163 "exprtree.y"
    {InstallParamsInLocal();}
    break;

  case 31:
#line 169 "exprtree.y"
    {}
    break;

  case 33:
#line 173 "exprtree.y"
    {LInstall((yyvsp[(1) - (1)].no)->varname,FDeclarationType);}
    break;

  case 34:
#line 177 "exprtree.y"
    {(yyval.no)=createTree(0,1,N_CONNECTOR,NULL,(yyvsp[(2) - (4)].no),(yyvsp[(3) - (4)].no),NULL);}
    break;

  case 35:
#line 178 "exprtree.y"
    {(yyval.no)=(yyvsp[(2) - (3)].no);}
    break;

  case 36:
#line 181 "exprtree.y"
    {
                                if (declarationtype == (yyvsp[(2) - (3)].no)->type){
                                    (yyval.no)=createTree(0,1,N_RET,NULL,(yyvsp[(2) - (3)].no),NULL,NULL);
                                }else{
                                    yyerror("return type mismatch (  )");
                                }
                            }
    break;

  case 37:
#line 190 "exprtree.y"
    {fprintf(intermediate, "MAIN:\n");
                                                        fprintf(intermediate, "PUSH BP\n");
                                                        fprintf(intermediate, "MOV BP,SP\n");

                                                        Ltemp=Lhead;
                                                        while(Ltemp!=NULL){
                                                            fprintf(intermediate,"PUSH R0\n");
                                                            Ltemp=Ltemp->next;
                                                        }
                                                        codeGen((yyvsp[(7) - (8)].no));
                                                        Lhead=NULL;
                                                        Ltail=NULL;
                                                    }
    break;

  case 38:
#line 205 "exprtree.y"
    {(yyval.no)=createTree(0,1,N_CONNECTOR,NULL,(yyvsp[(1) - (2)].no),(yyvsp[(2) - (2)].no),NULL);}
    break;

  case 39:
#line 206 "exprtree.y"
    {(yyval.no)=(yyvsp[(1) - (1)].no);}
    break;

  case 40:
#line 209 "exprtree.y"
    {(yyval.no) = (yyvsp[(1) - (1)].no);}
    break;

  case 41:
#line 210 "exprtree.y"
    {(yyval.no) = (yyvsp[(1) - (1)].no);}
    break;

  case 42:
#line 211 "exprtree.y"
    {(yyval.no) = (yyvsp[(1) - (1)].no);}
    break;

  case 43:
#line 212 "exprtree.y"
    {(yyval.no)=(yyvsp[(1) - (1)].no);}
    break;

  case 44:
#line 213 "exprtree.y"
    {(yyval.no)=(yyvsp[(1) - (1)].no);}
    break;

  case 45:
#line 214 "exprtree.y"
    {(yyval.no)=(yyvsp[(1) - (1)].no);}
    break;

  case 46:
#line 215 "exprtree.y"
    {(yyval.no)=(yyvsp[(1) - (1)].no);}
    break;

  case 47:
#line 216 "exprtree.y"
    {(yyval.no)=(yyvsp[(1) - (2)].no);}
    break;

  case 48:
#line 221 "exprtree.y"
    {(yyval.no)=createTree(0,voidtype,N_READ,NULL,(yyvsp[(3) - (5)].no),NULL,NULL);}
    break;

  case 49:
#line 223 "exprtree.y"
    {(yyval.no)=createTree(0,voidtype,N_WRITE,NULL,(yyvsp[(3) - (5)].no),NULL,NULL);}
    break;

  case 50:
#line 225 "exprtree.y"
    {  typecheck((yyvsp[(1) - (4)].no)->type,(yyvsp[(3) - (4)].no)->type,'=');
                                
                                (yyval.no)=createTree(0,voidtype,N_ASSIGN,NULL,(yyvsp[(1) - (4)].no),(yyvsp[(3) - (4)].no),NULL);}
    break;

  case 51:
#line 229 "exprtree.y"
    { typecheck((yyvsp[(3) - (10)].no)->type,booltype,'e');
                                                            (yyval.no)=createTree(0,voidtype,N_IF_ELSE,NULL,(yyvsp[(3) - (10)].no),(yyvsp[(8) - (10)].no),(yyvsp[(6) - (10)].no));}
    break;

  case 52:
#line 231 "exprtree.y"
    { typecheck((yyvsp[(3) - (8)].no)->type,booltype,'i');
                                                (yyval.no)=createTree(0,voidtype,N_IF,NULL,(yyvsp[(3) - (8)].no),(yyvsp[(6) - (8)].no),NULL);}
    break;

  case 53:
#line 234 "exprtree.y"
    { typecheck((yyvsp[(3) - (8)].no)->type,booltype,'w');
                                                        (yyval.no)=createTree(0,voidtype,N_WHILE,NULL,(yyvsp[(3) - (8)].no),(yyvsp[(6) - (8)].no),NULL);}
    break;

  case 54:
#line 236 "exprtree.y"
    { typecheck((yyvsp[(5) - (8)].no)->type,booltype,'w');
                                                        (yyval.no)=createTree(0,voidtype,N_DOWHILE,NULL,(yyvsp[(2) - (8)].no),(yyvsp[(5) - (8)].no),NULL);}
    break;

  case 55:
#line 239 "exprtree.y"
    {(yyval.no)=createTree(0,voidtype,N_BREAK,NULL,NULL,NULL,NULL);}
    break;

  case 56:
#line 241 "exprtree.y"
    {(yyval.no)=createTree(0,voidtype,N_CONT,NULL,NULL,NULL,NULL);}
    break;

  case 57:
#line 244 "exprtree.y"
    {(yyvsp[(3) - (3)].no)->argList=(yyvsp[(1) - (3)].no);
                            (yyval.no)=(yyvsp[(3) - (3)].no);  
                            }
    break;

  case 58:
#line 247 "exprtree.y"
    {(yyval.no)=(yyvsp[(1) - (1)].no);}
    break;

  case 59:
#line 248 "exprtree.y"
    {(yyval.no)=NULL;}
    break;

  case 60:
#line 251 "exprtree.y"
    { typecheck((yyvsp[(1) - (3)].no)->type,(yyvsp[(3) - (3)].no)->type,'a');
                            (yyval.no)=createTree(0,inttype,N_ADD,NULL,(yyvsp[(1) - (3)].no),(yyvsp[(3) - (3)].no),NULL);}
    break;

  case 61:
#line 253 "exprtree.y"
    { typecheck((yyvsp[(1) - (3)].no)->type,(yyvsp[(3) - (3)].no)->type,'a');
                            (yyval.no)=createTree(0,inttype,N_SUB,NULL,(yyvsp[(1) - (3)].no),(yyvsp[(3) - (3)].no),NULL);}
    break;

  case 62:
#line 255 "exprtree.y"
    { typecheck((yyvsp[(1) - (3)].no)->type,(yyvsp[(3) - (3)].no)->type,'a');
                            (yyval.no)=createTree(0,inttype,N_MUL,NULL,(yyvsp[(1) - (3)].no),(yyvsp[(3) - (3)].no),NULL);}
    break;

  case 63:
#line 257 "exprtree.y"
    { typecheck((yyvsp[(1) - (3)].no)->type,(yyvsp[(3) - (3)].no)->type,'a');
                            (yyval.no)=createTree(0,inttype,N_DIV,NULL,(yyvsp[(1) - (3)].no),(yyvsp[(3) - (3)].no),NULL);}
    break;

  case 64:
#line 259 "exprtree.y"
    { typecheck((yyvsp[(1) - (3)].no)->type,(yyvsp[(3) - (3)].no)->type,'b');
                            (yyval.no)=createTree(0,booltype,N_LT,NULL,(yyvsp[(1) - (3)].no),(yyvsp[(3) - (3)].no),NULL);}
    break;

  case 65:
#line 261 "exprtree.y"
    { typecheck((yyvsp[(1) - (3)].no)->type,(yyvsp[(3) - (3)].no)->type,'b');
                            (yyval.no)=createTree(0,booltype,N_GT,NULL,(yyvsp[(1) - (3)].no),(yyvsp[(3) - (3)].no),NULL);}
    break;

  case 66:
#line 263 "exprtree.y"
    { typecheck((yyvsp[(1) - (3)].no)->type,(yyvsp[(3) - (3)].no)->type,'b');
                            (yyval.no)=createTree(0,booltype,N_EQ,NULL,(yyvsp[(1) - (3)].no),(yyvsp[(3) - (3)].no),NULL);}
    break;

  case 67:
#line 265 "exprtree.y"
    { typecheck((yyvsp[(1) - (3)].no)->type,(yyvsp[(3) - (3)].no)->type,'b');
                            (yyval.no)=createTree(0,booltype,N_NEQ,NULL,(yyvsp[(1) - (3)].no),(yyvsp[(3) - (3)].no),NULL);}
    break;

  case 68:
#line 267 "exprtree.y"
    { typecheck((yyvsp[(1) - (3)].no)->type,(yyvsp[(3) - (3)].no)->type,'b');
                            (yyval.no)=createTree(0,booltype,N_GE,NULL,(yyvsp[(1) - (3)].no),(yyvsp[(3) - (3)].no),NULL);}
    break;

  case 69:
#line 269 "exprtree.y"
    { typecheck((yyvsp[(1) - (3)].no)->type,(yyvsp[(3) - (3)].no)->type,'b');
                            (yyval.no)=createTree(0,booltype,N_LE,NULL,(yyvsp[(1) - (3)].no),(yyvsp[(3) - (3)].no),NULL);}
    break;

  case 70:
#line 271 "exprtree.y"
    {typecheck((yyvsp[(1) - (3)].no)->type,(yyvsp[(3) - (3)].no)->type,'b');
                            (yyval.no)=createTree(0,booltype,N_AND,NULL,(yyvsp[(1) - (3)].no),(yyvsp[(3) - (3)].no),NULL);}
    break;

  case 71:
#line 273 "exprtree.y"
    {typecheck((yyvsp[(1) - (3)].no)->type,(yyvsp[(3) - (3)].no)->type,'b');
                            (yyval.no)=createTree(0,booltype,N_AND,NULL,(yyvsp[(1) - (3)].no),(yyvsp[(3) - (3)].no),NULL);}
    break;

  case 72:
#line 275 "exprtree.y"
    {(yyval.no)=(yyvsp[(2) - (3)].no);}
    break;

  case 73:
#line 276 "exprtree.y"
    {(yyval.no)=(yyvsp[(1) - (1)].no);}
    break;

  case 74:
#line 277 "exprtree.y"
    {(yyval.no)=(yyvsp[(1) - (1)].no);}
    break;

  case 75:
#line 278 "exprtree.y"
    {(yyval.no)=(yyvsp[(1) - (1)].no);}
    break;

  case 76:
#line 279 "exprtree.y"
    {(yyval.no)=(yyvsp[(1) - (1)].no);}
    break;

  case 77:
#line 283 "exprtree.y"
    {   assignType((yyvsp[(1) - (4)].no),1);

                                (yyvsp[(1) - (4)].no)->nodetype=N_FUNC;
                                (yyvsp[(1) - (4)].no)->left=reverseList((yyvsp[(3) - (4)].no));
                                (yyval.no)=(yyvsp[(1) - (4)].no);}
    break;

  case 78:
#line 293 "exprtree.y"
    {  assignType((yyvsp[(1) - (1)].no),0);
                (yyval.no)=(yyvsp[(1) - (1)].no);
                }
    break;

  case 79:
#line 296 "exprtree.y"
    {assignType((yyvsp[(1) - (4)].no),2);
                        
                        (yyval.no)=createTree(0,(yyvsp[(1) - (4)].no)->type,N_ARRAY,(yyvsp[(1) - (4)].no)->varname,(yyvsp[(1) - (4)].no),(yyvsp[(3) - (4)].no),NULL);
    }
    break;

  case 80:
#line 300 "exprtree.y"
    {assignType((yyvsp[(1) - (4)].no),2);

                    (yyval.no)=createTree(0,(yyvsp[(1) - (4)].no)->type,N_ARRAY,(yyvsp[(1) - (4)].no)->varname,(yyvsp[(1) - (4)].no),(yyvsp[(3) - (4)].no),NULL);

    }
    break;


/* Line 1267 of yacc.c.  */
#line 2050 "y.tab.c"
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


#line 307 "exprtree.y"


void yyerror(char const *s){
    printf("yyerror %s",s);exit(1);
    return;
}



int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Please provide an input filename\n");
        exit(1);
    } else {
        fp = fopen(argv[1], "r");
        if (!fp) {
            printf("Invalid input file specified\n");
            exit(1);
        } else {
            yyin = fp;
        }
    }
    yyparse();
    return 0;
}
