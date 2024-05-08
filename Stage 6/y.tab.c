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
     MOD = 270,
     IF = 271,
     ELSE = 272,
     WHILE = 273,
     THEN = 274,
     ENDIF = 275,
     ENDWHILE = 276,
     DO = 277,
     BREAK = 278,
     CONTINUE = 279,
     LT = 280,
     GT = 281,
     LE = 282,
     GE = 283,
     EQ = 284,
     NEQ = 285,
     AND = 286,
     OR = 287,
     DECL = 288,
     ENDDECL = 289,
     INT = 290,
     STR = 291,
     NILL = 292,
     RETURN = 293,
     MAIN = 294,
     TYPE = 295,
     ENDTYPE = 296,
     ALLOC = 297,
     FREE = 298,
     INIT = 299,
     NEQNILL = 300,
     DEQNILL = 301
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
#define MOD 270
#define IF 271
#define ELSE 272
#define WHILE 273
#define THEN 274
#define ENDIF 275
#define ENDWHILE 276
#define DO 277
#define BREAK 278
#define CONTINUE 279
#define LT 280
#define GT 281
#define LE 282
#define GE 283
#define EQ 284
#define NEQ 285
#define AND 286
#define OR 287
#define DECL 288
#define ENDDECL 289
#define INT 290
#define STR 291
#define NILL 292
#define RETURN 293
#define MAIN 294
#define TYPE 295
#define ENDTYPE 296
#define ALLOC 297
#define FREE 298
#define INIT 299
#define NEQNILL 300
#define DEQNILL 301




/* Copy the first part of user declarations.  */
#line 1 "exprtree.y"

    #include <stdio.h>
    #include <stdlib.h>
    #include "tasktree.h"
   #include "symboltable.h"  
    #include "symboltable.c"
    #include "typecheck.h"
    #include "tasktree.c"
    #include "codegen.c"
    #include "evaluvate.c"
    #include "typecheck.c"
    int yydebug=0;
    int yylex(void);
    int g=0;
    void yyerror(char const *s);
    extern FILE *yyin;
    FILE *fp;
    FILE *intermediate;
    struct tnode* tempNode;
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
#line 23 "exprtree.y"
{
    struct tnode* no;
    
}
/* Line 193 of yacc.c.  */
#line 215 "y.tab.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 228 "y.tab.c"

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
#define YYFINAL  9
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   495

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  56
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  41
/* YYNRULES -- Number of rules.  */
#define YYNRULES  111
/* YYNRULES -- Number of states.  */
#define YYNSTATES  239

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   301

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      53,    54,     2,     2,    47,     2,    55,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    50,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    51,     2,    52,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    48,     2,    49,     2,     2,     2,     2,
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
      45,    46
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     8,    12,    15,    18,    20,    25,    27,
      30,    32,    36,    38,    40,    42,    46,    49,    50,    53,
      55,    59,    61,    63,    65,    67,    69,    71,    75,    77,
      82,    84,    89,    92,    94,    95,   105,   109,   111,   112,
     115,   119,   122,   123,   126,   128,   132,   136,   138,   143,
     147,   151,   160,   164,   168,   171,   173,   175,   177,   179,
     181,   183,   185,   187,   190,   195,   201,   207,   213,   219,
     225,   230,   237,   244,   249,   254,   259,   270,   279,   288,
     297,   300,   303,   307,   309,   310,   314,   318,   322,   326,
     330,   334,   338,   342,   346,   350,   354,   358,   362,   365,
     368,   371,   374,   378,   380,   382,   384,   386,   388,   393,
     395,   400
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      57,     0,    -1,    58,    65,    72,    82,    -1,    40,    59,
      41,    -1,    40,    41,    -1,    59,    60,    -1,    60,    -1,
      61,    48,    62,    49,    -1,    11,    -1,    62,    63,    -1,
      63,    -1,    64,    11,    50,    -1,    35,    -1,    36,    -1,
      11,    -1,    33,    66,    34,    -1,    33,    34,    -1,    -1,
      66,    67,    -1,    67,    -1,    68,    70,    50,    -1,    35,
      -1,    36,    -1,    11,    -1,    35,    -1,    36,    -1,    11,
      -1,    70,    47,    71,    -1,    71,    -1,    11,    51,    13,
      52,    -1,    11,    -1,    11,    53,    74,    54,    -1,    72,
      73,    -1,    73,    -1,    -1,    68,    11,    53,    74,    54,
      48,    76,    80,    49,    -1,    74,    47,    75,    -1,    75,
      -1,    -1,    69,    11,    -1,    33,    77,    34,    -1,    33,
      34,    -1,    -1,    77,    78,    -1,    78,    -1,    69,    79,
      50,    -1,    79,    47,    79,    -1,    11,    -1,     7,    84,
      81,     8,    -1,     7,    81,     8,    -1,    38,    94,    50,
      -1,    68,    39,    53,    54,    48,    76,    80,    49,    -1,
      83,    55,    11,    -1,    11,    55,    11,    -1,    84,    85,
      -1,    85,    -1,    86,    -1,    87,    -1,    88,    -1,    89,
      -1,    90,    -1,    91,    -1,    92,    -1,    95,    50,    -1,
      44,    53,    54,    50,    -1,    43,    53,    96,    54,    50,
      -1,    43,    53,    83,    54,    50,    -1,     9,    53,    96,
      54,    50,    -1,     9,    53,    83,    54,    50,    -1,    10,
      53,    94,    54,    50,    -1,    83,    14,    94,    50,    -1,
      96,    14,    42,    53,    54,    50,    -1,    83,    14,    42,
      53,    54,    50,    -1,    96,    14,    94,    50,    -1,    83,
      14,    37,    50,    -1,    96,    14,    37,    50,    -1,    16,
      53,    94,    54,    19,    84,    17,    84,    20,    50,    -1,
      16,    53,    94,    54,    19,    84,    20,    50,    -1,    18,
      53,    94,    54,    22,    84,    21,    50,    -1,    22,    84,
      18,    53,    94,    54,    21,    50,    -1,    23,    50,    -1,
      24,    50,    -1,    93,    47,    94,    -1,    94,    -1,    -1,
      94,     3,    94,    -1,    94,     4,    94,    -1,    94,     5,
      94,    -1,    94,     6,    94,    -1,    94,    15,    94,    -1,
      94,    25,    94,    -1,    94,    26,    94,    -1,    94,    29,
      94,    -1,    94,    30,    94,    -1,    94,    28,    94,    -1,
      94,    27,    94,    -1,    94,    31,    94,    -1,    94,    32,
      94,    -1,    83,    46,    -1,    83,    45,    -1,    96,    46,
      -1,    96,    45,    -1,    53,    94,    54,    -1,    13,    -1,
      96,    -1,    95,    -1,    12,    -1,    83,    -1,    11,    53,
      93,    54,    -1,    11,    -1,    11,    51,    94,    52,    -1,
      11,    51,    96,    52,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    56,    56,    60,    61,    64,    65,    68,    71,    74,
      75,    78,    82,    83,    84,    99,   100,   101,   103,   104,
     107,   110,   111,   112,   118,   119,   120,   127,   128,   131,
     132,   133,   141,   142,   143,   146,   202,   203,   204,   207,
     211,   212,   213,   216,   217,   219,   222,   223,   227,   228,
     231,   240,   258,   261,   269,   270,   274,   275,   276,   277,
     278,   279,   280,   281,   282,   283,   284,   289,   290,   292,
     294,   297,   299,   302,   305,   307,   309,   311,   314,   316,
     319,   321,   324,   327,   328,   332,   334,   336,   338,   340,
     342,   344,   346,   348,   350,   352,   354,   356,   358,   362,
     366,   370,   374,   375,   377,   378,   379,   381,   385,   395,
     398,   402
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "PLUS", "MINUS", "MUL", "DIV", "START",
  "END", "READ", "WRITE", "VAR", "STRVAL", "NUM", "ASSIGN", "MOD", "IF",
  "ELSE", "WHILE", "THEN", "ENDIF", "ENDWHILE", "DO", "BREAK", "CONTINUE",
  "LT", "GT", "LE", "GE", "EQ", "NEQ", "AND", "OR", "DECL", "ENDDECL",
  "INT", "STR", "NILL", "RETURN", "MAIN", "TYPE", "ENDTYPE", "ALLOC",
  "FREE", "INIT", "NEQNILL", "DEQNILL", "','", "'{'", "'}'", "';'", "'['",
  "']'", "'('", "')'", "'.'", "$accept", "Program", "TypeDefBlock",
  "TypeDefList", "TypeDef", "UserDefType", "FieldListDecl", "FieldDecl",
  "TypeName", "GDeclBlock", "GDeclList", "GDecl", "Type", "FType",
  "GIdList", "GId", "FdefBlock", "Fdef", "ParamList", "Param",
  "LdeclBlock", "LdeclList", "Ldecl", "IdList", "Body", "RetStmt",
  "MainBlock", "Field", "Slist", "Stmt", "InputStmt", "OutputStmt",
  "AsgStmt", "Ifstmt", "Whilestmt", "Breakstmt", "Contstmt", "ArgList",
  "expr", "func", "id", 0
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
     295,   296,   297,   298,   299,   300,   301,    44,   123,   125,
      59,    91,    93,    40,    41,    46
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    56,    57,    58,    58,    59,    59,    60,    61,    62,
      62,    63,    64,    64,    64,    65,    65,    65,    66,    66,
      67,    68,    68,    68,    69,    69,    69,    70,    70,    71,
      71,    71,    72,    72,    72,    73,    74,    74,    74,    75,
      76,    76,    76,    77,    77,    78,    79,    79,    80,    80,
      81,    82,    83,    83,    84,    84,    85,    85,    85,    85,
      85,    85,    85,    85,    85,    85,    85,    86,    86,    87,
      88,    88,    88,    88,    88,    88,    89,    89,    90,    90,
      91,    92,    93,    93,    93,    94,    94,    94,    94,    94,
      94,    94,    94,    94,    94,    94,    94,    94,    94,    94,
      94,    94,    94,    94,    94,    94,    94,    94,    95,    96,
      96,    96
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     4,     3,     2,     2,     1,     4,     1,     2,
       1,     3,     1,     1,     1,     3,     2,     0,     2,     1,
       3,     1,     1,     1,     1,     1,     1,     3,     1,     4,
       1,     4,     2,     1,     0,     9,     3,     1,     0,     2,
       3,     2,     0,     2,     1,     3,     3,     1,     4,     3,
       3,     8,     3,     3,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     2,     4,     5,     5,     5,     5,     5,
       4,     6,     6,     4,     4,     4,    10,     8,     8,     8,
       2,     2,     3,     1,     0,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     2,     2,
       2,     2,     3,     1,     1,     1,     1,     1,     4,     1,
       4,     4
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,    17,     8,     4,     0,     6,     0,     1,
       0,     0,     3,     5,     0,    23,    16,    21,    22,     0,
      19,     0,     0,     0,    33,    14,    12,    13,     0,    10,
       0,    15,    18,    30,     0,    28,     0,     0,    32,     2,
       7,     9,     0,     0,    38,     0,    20,    38,     0,    11,
       0,    26,    24,    25,     0,     0,    37,    27,     0,     0,
      29,    39,     0,    31,     0,     0,    36,    42,    42,     0,
       0,     0,    41,     0,     0,    44,     0,     0,     0,    47,
       0,    40,    43,     0,     0,   109,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    55,    56,    57,
      58,    59,    60,    61,    62,     0,     0,    35,    51,     0,
      45,     0,     0,     0,    84,     0,     0,     0,     0,    80,
      81,   106,   103,     0,   107,     0,   105,   104,     0,     0,
      49,     0,     0,     0,    54,    63,     0,    46,   109,     0,
       0,     0,     0,   104,     0,    83,    53,     0,     0,     0,
       0,    99,    98,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    50,   101,   100,     0,
       0,     0,     0,     0,     0,    52,    48,     0,     0,     0,
       0,     0,     0,   110,   111,     0,   108,     0,     0,     0,
     102,    85,    86,    87,    88,    89,    90,    91,    95,    94,
      92,    93,    96,    97,     0,     0,    64,    74,     0,    70,
      75,     0,    73,    68,    67,    69,    82,     0,     0,     0,
      66,    65,     0,     0,     0,     0,     0,    72,    71,     0,
       0,     0,     0,     0,    77,    78,    79,     0,    76
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,     6,     7,     8,    28,    29,    30,    11,
      19,    20,    21,    54,    34,    35,    23,    24,    55,    56,
      70,    74,    75,    80,    77,    94,    39,   124,    96,    97,
      98,    99,   100,   101,   102,   103,   104,   144,   125,   126,
     127
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -88
static const yytype_int16 yypact[] =
{
     -35,    -7,    11,   -20,   -88,   -88,    -5,   -88,   -24,   -88,
      32,    45,   -88,   -88,    71,   -88,   -88,   -88,   -88,    43,
     -88,    29,    93,    45,   -88,   -88,   -88,   -88,   -10,   -88,
     117,   -88,   -88,   -21,   100,   -88,    77,     5,   -88,   -88,
     -88,   -88,    89,   167,    90,    29,   -88,    90,   108,   -88,
     144,   -88,   -88,   -88,   170,   -40,   -88,   -88,    17,   143,
     -88,   -88,    90,   -88,   151,   165,   -88,   181,   181,    49,
     209,   209,   -88,   206,    75,   -88,   354,   182,   183,   -88,
     148,   -88,   -88,   196,   199,   124,   200,   214,   111,   184,
     185,     6,   217,   218,   242,    -6,   354,   -88,   -88,   -88,
     -88,   -88,   -88,   -88,   -88,   235,   254,   -88,   -88,   206,
     -88,   275,     6,     6,     6,   277,     6,     6,   417,   -88,
     -88,   -88,   -88,     6,    57,   269,   -88,    27,   275,   236,
     -88,    16,   278,   283,   -88,   -88,    63,   245,    85,     7,
     239,   161,   251,    72,    61,   439,   -88,   179,   197,   249,
     215,   -88,   -88,     6,     6,     6,     6,     6,     6,     6,
       6,     6,     6,     6,     6,     6,   -88,   -88,   -88,    59,
     255,   258,   260,   264,   301,   -88,   -88,   261,   265,   309,
     270,   271,   272,   -88,   -88,     6,   -88,   304,   303,     6,
     -88,   447,   447,   455,   455,   455,   463,   463,   463,   463,
     129,   129,   463,   463,   292,   293,   -88,   -88,   290,   -88,
     -88,   291,   -88,   -88,   -88,   -88,   439,   111,   111,   233,
     -88,   -88,   296,   300,   338,   378,   150,   -88,   -88,   111,
     302,   307,   316,   394,   -88,   -88,   -88,   317,   -88
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -88,   -88,   -88,   -88,   347,   -88,   -88,   340,   -88,   -88,
     -88,   350,    -1,    99,   -88,   326,   -88,   351,   328,   311,
     312,   -88,   305,   274,   313,   289,   -88,   -73,   -86,   -87,
     -88,   -88,   -88,   -88,   -88,   -88,   -88,   -88,   -66,   -55,
     -76
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_int16 yytable[] =
{
     106,    25,   118,    95,     4,     1,     4,    62,   131,   134,
      22,     9,   106,    10,    63,    95,    36,    85,   121,   122,
     106,   105,    37,    95,    14,    26,    27,    85,   121,   122,
      43,   134,    44,   105,     5,   140,    12,   143,   139,    40,
      33,   105,   106,    15,    48,    95,   141,   142,   145,   132,
     147,   148,   170,   172,    15,   169,    15,   150,   173,   123,
      51,   180,   132,   105,    62,   174,    16,    17,    18,   123,
     179,    64,   167,   168,    85,   121,   122,    31,    17,    18,
      17,    18,    25,    72,    52,    53,    51,   191,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     177,    51,   151,   152,    36,   178,    26,    27,   185,    81,
      52,    53,   132,   204,   132,   186,   123,   167,   168,   216,
      83,    84,    85,   219,   184,    52,    53,    86,    42,    87,
      47,   224,   225,    88,    89,    90,   113,   134,   134,    49,
     115,   106,   106,   233,    95,    95,   134,    45,   106,   106,
      46,    95,    95,   106,    92,    93,    95,   106,   162,   163,
      95,    59,   105,   105,   153,   154,   155,   156,    73,   105,
     105,   232,   218,    73,   105,   113,   157,   114,   105,   115,
      50,    61,   153,   154,   155,   156,   158,   159,   160,   161,
     162,   163,   164,   165,   157,   109,    60,    65,   110,    67,
     153,   154,   155,   156,   158,   159,   160,   161,   162,   163,
     164,   165,   157,    68,    69,   182,    76,    79,   153,   154,
     155,   156,   158,   159,   160,   161,   162,   163,   164,   165,
     157,   107,   108,   187,   119,   120,   153,   154,   155,   156,
     158,   159,   160,   161,   162,   163,   164,   165,   157,   111,
     130,   188,   112,   116,   153,   154,   155,   156,   158,   159,
     160,   161,   162,   163,   164,   165,   157,   117,   136,   190,
     128,   129,   153,   154,   155,   156,   158,   159,   160,   161,
     162,   163,   164,   165,   157,   135,   138,   226,   146,   175,
     171,   176,   109,   181,   158,   159,   160,   161,   162,   163,
     164,   165,   189,   183,   153,   154,   155,   156,   206,   205,
     207,   210,   153,   154,   155,   156,   157,   208,   211,   166,
     213,   214,   215,   217,   157,   218,   158,   159,   160,   161,
     162,   163,   164,   165,   158,   159,   160,   161,   162,   163,
     164,   165,   220,   221,   222,   223,   227,    83,    84,    85,
     228,   209,   234,    13,    86,   229,    87,   235,   230,   212,
      88,    89,    90,    83,    84,    85,   236,   238,    41,    32,
      86,    57,    87,    66,    38,    58,    88,    89,    90,    82,
      71,    92,    93,   137,    78,   133,     0,    83,    84,    85,
       0,     0,    91,     0,    86,     0,    87,    92,    93,   231,
      88,    89,    90,    83,    84,    85,     0,     0,     0,     0,
      86,     0,    87,     0,   237,     0,    88,    89,    90,     0,
       0,    92,    93,     0,     0,     0,    83,    84,    85,     0,
       0,     0,     0,    86,     0,   149,     0,    92,    93,    88,
      89,    90,   153,   154,   155,   156,     0,     0,     0,     0,
       0,     0,   155,   156,   157,     0,     0,     0,     0,     0,
      92,    93,   157,     0,   158,   159,   160,   161,   162,   163,
     164,   165,   158,   159,   160,   161,   162,   163,   164,   165,
     158,   159,   160,   161,   162,   163,   164,   165,    -1,    -1,
      -1,    -1,   162,   163,    -1,    -1
};

static const yytype_int16 yycheck[] =
{
      76,    11,    88,    76,    11,    40,    11,    47,    14,    96,
      11,     0,    88,    33,    54,    88,    11,    11,    12,    13,
      96,    76,    23,    96,    48,    35,    36,    11,    12,    13,
      51,   118,    53,    88,    41,   111,    41,   113,   111,    49,
      11,    96,   118,    11,    39,   118,   112,   113,   114,    55,
     116,   117,   128,    37,    11,   128,    11,   123,    42,    53,
      11,    54,    55,   118,    47,   131,    34,    35,    36,    53,
     136,    54,    45,    46,    11,    12,    13,    34,    35,    36,
      35,    36,    11,    34,    35,    36,    11,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
      37,    11,    45,    46,    11,    42,    35,    36,    47,    34,
      35,    36,    55,    54,    55,    54,    53,    45,    46,   185,
       9,    10,    11,   189,    52,    35,    36,    16,    11,    18,
      53,   217,   218,    22,    23,    24,    51,   224,   225,    50,
      55,   217,   218,   229,   217,   218,   233,    47,   224,   225,
      50,   224,   225,   229,    43,    44,   229,   233,    29,    30,
     233,    53,   217,   218,     3,     4,     5,     6,    69,   224,
     225,    21,    22,    74,   229,    51,    15,    53,   233,    55,
      13,    11,     3,     4,     5,     6,    25,    26,    27,    28,
      29,    30,    31,    32,    15,    47,    52,    54,    50,    48,
       3,     4,     5,     6,    25,    26,    27,    28,    29,    30,
      31,    32,    15,    48,    33,    54,     7,    11,     3,     4,
       5,     6,    25,    26,    27,    28,    29,    30,    31,    32,
      15,    49,    49,    54,    50,    50,     3,     4,     5,     6,
      25,    26,    27,    28,    29,    30,    31,    32,    15,    53,
       8,    54,    53,    53,     3,     4,     5,     6,    25,    26,
      27,    28,    29,    30,    31,    32,    15,    53,    14,    54,
      53,    53,     3,     4,     5,     6,    25,    26,    27,    28,
      29,    30,    31,    32,    15,    50,    11,    54,    11,    11,
      54,     8,    47,    54,    25,    26,    27,    28,    29,    30,
      31,    32,    53,    52,     3,     4,     5,     6,    50,    54,
      50,    50,     3,     4,     5,     6,    15,    53,    53,    50,
      50,    50,    50,    19,    15,    22,    25,    26,    27,    28,
      29,    30,    31,    32,    25,    26,    27,    28,    29,    30,
      31,    32,    50,    50,    54,    54,    50,     9,    10,    11,
      50,    50,    50,     6,    16,    17,    18,    50,    20,    50,
      22,    23,    24,     9,    10,    11,    50,    50,    28,    19,
      16,    45,    18,    62,    23,    47,    22,    23,    24,    74,
      68,    43,    44,   109,    71,    96,    -1,     9,    10,    11,
      -1,    -1,    38,    -1,    16,    -1,    18,    43,    44,    21,
      22,    23,    24,     9,    10,    11,    -1,    -1,    -1,    -1,
      16,    -1,    18,    -1,    20,    -1,    22,    23,    24,    -1,
      -1,    43,    44,    -1,    -1,    -1,     9,    10,    11,    -1,
      -1,    -1,    -1,    16,    -1,    18,    -1,    43,    44,    22,
      23,    24,     3,     4,     5,     6,    -1,    -1,    -1,    -1,
      -1,    -1,     5,     6,    15,    -1,    -1,    -1,    -1,    -1,
      43,    44,    15,    -1,    25,    26,    27,    28,    29,    30,
      31,    32,    25,    26,    27,    28,    29,    30,    31,    32,
      25,    26,    27,    28,    29,    30,    31,    32,    25,    26,
      27,    28,    29,    30,    31,    32
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    40,    57,    58,    11,    41,    59,    60,    61,     0,
      33,    65,    41,    60,    48,    11,    34,    35,    36,    66,
      67,    68,    68,    72,    73,    11,    35,    36,    62,    63,
      64,    34,    67,    11,    70,    71,    11,    68,    73,    82,
      49,    63,    11,    51,    53,    47,    50,    53,    39,    50,
      13,    11,    35,    36,    69,    74,    75,    71,    74,    53,
      52,    11,    47,    54,    54,    54,    75,    48,    48,    33,
      76,    76,    34,    69,    77,    78,     7,    80,    80,    11,
      79,    34,    78,     9,    10,    11,    16,    18,    22,    23,
      24,    38,    43,    44,    81,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    95,    96,    49,    49,    47,
      50,    53,    53,    51,    53,    55,    53,    53,    84,    50,
      50,    12,    13,    53,    83,    94,    95,    96,    53,    53,
       8,    14,    55,    81,    85,    50,    14,    79,    11,    83,
      96,    94,    94,    96,    93,    94,    11,    94,    94,    18,
      94,    45,    46,     3,     4,     5,     6,    15,    25,    26,
      27,    28,    29,    30,    31,    32,    50,    45,    46,    83,
      96,    54,    37,    42,    94,    11,     8,    37,    42,    94,
      54,    54,    54,    52,    52,    47,    54,    54,    54,    53,
      54,    94,    94,    94,    94,    94,    94,    94,    94,    94,
      94,    94,    94,    94,    54,    54,    50,    50,    53,    50,
      50,    53,    50,    50,    50,    50,    94,    19,    22,    94,
      50,    50,    54,    54,    84,    84,    54,    50,    50,    17,
      20,    21,    21,    84,    50,    50,    50,    20,    50
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
#line 56 "exprtree.y"
    {finalise();}
    break;

  case 7:
#line 68 "exprtree.y"
    {TInstall((yyvsp[(1) - (4)].no)->varname,1,Fhead);}
    break;

  case 8:
#line 71 "exprtree.y"
    {tempNode=(yyvsp[(1) - (1)].no);
                    (yyval.no)=(yyvsp[(1) - (1)].no);}
    break;

  case 11:
#line 78 "exprtree.y"
    {FInstall((yyvsp[(2) - (3)].no)->varname,declarationtype);}
    break;

  case 12:
#line 82 "exprtree.y"
    {declarationtype=Tlookup("integer");}
    break;

  case 13:
#line 83 "exprtree.y"
    {declarationtype=Tlookup("string");}
    break;

  case 14:
#line 84 "exprtree.y"
    {declarationtype=Tlookup((yyvsp[(1) - (1)].no)->varname);
                    if (declarationtype==NULL){

                        if(!strcmp(tempNode->varname,(yyvsp[(1) - (1)].no)->varname)){
                            declarationtype=Tlookup("dummy");
                        }else{
                            yyerror("Undefined user type\n");
                        }
                    }
                }
    break;

  case 15:
#line 99 "exprtree.y"
    {initialise();}
    break;

  case 16:
#line 100 "exprtree.y"
    {initialise();}
    break;

  case 18:
#line 103 "exprtree.y"
    {}
    break;

  case 19:
#line 104 "exprtree.y"
    {}
    break;

  case 20:
#line 107 "exprtree.y"
    {}
    break;

  case 21:
#line 110 "exprtree.y"
    {declarationtype=Tlookup("integer");}
    break;

  case 22:
#line 111 "exprtree.y"
    {declarationtype=Tlookup("string");}
    break;

  case 23:
#line 112 "exprtree.y"
    {declarationtype=Tlookup((yyvsp[(1) - (1)].no)->varname);
            if (declarationtype==NULL){
                yyerror("Undefined user type\n");
            }
          }
    break;

  case 24:
#line 118 "exprtree.y"
    {Fdeclarationtype = Tlookup("integer");}
    break;

  case 25:
#line 119 "exprtree.y"
    {Fdeclarationtype = Tlookup("string");}
    break;

  case 26:
#line 120 "exprtree.y"
    {Fdeclarationtype=Tlookup((yyvsp[(1) - (1)].no)->varname);
            if (Fdeclarationtype==NULL){
                yyerror("Type Not Defined");
            }
          }
    break;

  case 29:
#line 131 "exprtree.y"
    {GInstall((yyvsp[(1) - (4)].no)->varname,declarationtype,(yyvsp[(3) - (4)].no)->val,NULL);}
    break;

  case 30:
#line 132 "exprtree.y"
    {GInstall((yyvsp[(1) - (1)].no)->varname,declarationtype,1,NULL);}
    break;

  case 31:
#line 133 "exprtree.y"
    {GInstall((yyvsp[(1) - (4)].no)->varname,declarationtype,-1,Phead);
                                    Phead=NULL;
                                    Ptail=NULL;
                                }
    break;

  case 35:
#line 146 "exprtree.y"
    {Gtemp=GLookup((yyvsp[(2) - (9)].no)->varname);
                                                            
                                                             
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
                                                            


                                                            fprintf(intermediate,"F%d:\n",Gtemp->flabel);
                                                            
                                                            
                                                            fprintf(intermediate,"PUSH BP\n");
                                                            fprintf(intermediate,"MOV BP,SP\n");
                                                            Ltemp=Lhead;

                                                            while(Ltemp!=NULL){
                                                                if (Ltemp->binding>0){
                                                                    fprintf(intermediate,"PUSH R0\n");
                                                                }
                                                                Ltemp=Ltemp->next;
                                                            }
                                                            

                                    
                                                            codeGen((yyvsp[(8) - (9)].no));
                                                            Lhead=NULL;
                                                            Ltail=NULL;
                                                            Phead=NULL;
                                                            Ptail=NULL;
                                                            }
    break;

  case 39:
#line 207 "exprtree.y"
    {ParamInstall((yyvsp[(2) - (2)].no)->varname,Fdeclarationtype);}
    break;

  case 40:
#line 211 "exprtree.y"
    {InstallParamsInLocal();}
    break;

  case 41:
#line 212 "exprtree.y"
    {InstallParamsInLocal();}
    break;

  case 42:
#line 213 "exprtree.y"
    {InstallParamsInLocal();}
    break;

  case 45:
#line 219 "exprtree.y"
    {}
    break;

  case 47:
#line 223 "exprtree.y"
    {LInstall((yyvsp[(1) - (1)].no)->varname,Fdeclarationtype);}
    break;

  case 48:
#line 227 "exprtree.y"
    {(yyval.no)=createTree(0,Tlookup("void"),N_CONNECTOR,NULL,(yyvsp[(2) - (4)].no),(yyvsp[(3) - (4)].no),NULL);}
    break;

  case 49:
#line 228 "exprtree.y"
    {(yyval.no)=(yyvsp[(2) - (3)].no);}
    break;

  case 50:
#line 231 "exprtree.y"
    {   
                                if (declarationtype == (yyvsp[(2) - (3)].no)->type){
                                    (yyval.no)=createTree(0,Tlookup("void"),N_RET,NULL,(yyvsp[(2) - (3)].no),NULL,NULL);
                                }else{
                                    yyerror("return type mismatch (  )");
                                }
                            }
    break;

  case 51:
#line 240 "exprtree.y"
    { if(declarationtype != Tlookup("integer")) {
                                                            yyerror("Main return type should be of integer type\n");
                                                        }
                                                        fprintf(intermediate, "MAIN:\n");
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

  case 52:
#line 258 "exprtree.y"
    {
                        assignTypeField((yyvsp[(3) - (3)].no),(yyvsp[(1) - (3)].no)->type->fields);
                        (yyval.no)=createTree(0,(yyvsp[(3) - (3)].no)->type,N_FIELD,NULL,(yyvsp[(1) - (3)].no),(yyvsp[(3) - (3)].no),NULL);}
    break;

  case 53:
#line 261 "exprtree.y"
    {
                    assignType((yyvsp[(1) - (3)].no),0);
                    assignTypeField((yyvsp[(3) - (3)].no),(yyvsp[(1) - (3)].no)->type->fields);
                    (yyval.no)=createTree(0,(yyvsp[(3) - (3)].no)->type,N_FIELD,NULL,(yyvsp[(1) - (3)].no),(yyvsp[(3) - (3)].no),NULL); 
                    }
    break;

  case 54:
#line 269 "exprtree.y"
    {(yyval.no)=createTree(0,Tlookup("void"),N_CONNECTOR,NULL,(yyvsp[(1) - (2)].no),(yyvsp[(2) - (2)].no),NULL);}
    break;

  case 55:
#line 270 "exprtree.y"
    {(yyval.no)=(yyvsp[(1) - (1)].no);}
    break;

  case 56:
#line 274 "exprtree.y"
    {(yyval.no) = (yyvsp[(1) - (1)].no);}
    break;

  case 57:
#line 275 "exprtree.y"
    {(yyval.no) = (yyvsp[(1) - (1)].no);}
    break;

  case 58:
#line 276 "exprtree.y"
    {(yyval.no) = (yyvsp[(1) - (1)].no);}
    break;

  case 59:
#line 277 "exprtree.y"
    {(yyval.no)=(yyvsp[(1) - (1)].no);}
    break;

  case 60:
#line 278 "exprtree.y"
    {(yyval.no)=(yyvsp[(1) - (1)].no);}
    break;

  case 61:
#line 279 "exprtree.y"
    {(yyval.no)=(yyvsp[(1) - (1)].no);}
    break;

  case 62:
#line 280 "exprtree.y"
    {(yyval.no)=(yyvsp[(1) - (1)].no);}
    break;

  case 63:
#line 281 "exprtree.y"
    {(yyval.no)=(yyvsp[(1) - (2)].no);}
    break;

  case 64:
#line 282 "exprtree.y"
    {(yyval.no)=createTree(0,Tlookup("void"),N_INIT,NULL,NULL,NULL,NULL);}
    break;

  case 65:
#line 283 "exprtree.y"
    {(yyval.no)=createTree(0,Tlookup("void"),N_FREE,NULL,(yyvsp[(3) - (5)].no),NULL,NULL);}
    break;

  case 66:
#line 284 "exprtree.y"
    {(yyval.no)=createTree(0,Tlookup("void"),N_FREE,NULL,(yyvsp[(3) - (5)].no),NULL,NULL);}
    break;

  case 67:
#line 289 "exprtree.y"
    {(yyval.no)=createTree(0,Tlookup("void"),N_READ,NULL,(yyvsp[(3) - (5)].no),NULL,NULL);}
    break;

  case 68:
#line 290 "exprtree.y"
    {(yyval.no)=createTree(0,Tlookup("void"),N_READ,NULL,(yyvsp[(3) - (5)].no),NULL,NULL);}
    break;

  case 69:
#line 292 "exprtree.y"
    {(yyval.no)=createTree(0,Tlookup("void"),N_WRITE,NULL,(yyvsp[(3) - (5)].no),NULL,NULL);}
    break;

  case 70:
#line 294 "exprtree.y"
    {typecheck((yyvsp[(1) - (4)].no)->type,(yyvsp[(3) - (4)].no)->type,'=');
                                
                                (yyval.no)=createTree(0,Tlookup("void"),N_ASSIGN,NULL,(yyvsp[(1) - (4)].no),(yyvsp[(3) - (4)].no),NULL);}
    break;

  case 71:
#line 297 "exprtree.y"
    { (yyval.no)=createTree(0,Tlookup("void"),N_ASSIGN,NULL,(yyvsp[(1) - (6)].no),(yyvsp[(3) - (6)].no),NULL);}
    break;

  case 72:
#line 299 "exprtree.y"
    {(yyval.no)=createTree(0,Tlookup("void"),N_ASSIGN,NULL,(yyvsp[(1) - (6)].no),(yyvsp[(3) - (6)].no),NULL);
                                            }
    break;

  case 73:
#line 302 "exprtree.y"
    {   typecheck((yyvsp[(1) - (4)].no)->type,(yyvsp[(3) - (4)].no)->type,'=');
                                    (yyval.no)=createTree(0,Tlookup("void"),N_ASSIGN,NULL,(yyvsp[(1) - (4)].no),(yyvsp[(3) - (4)].no),NULL);}
    break;

  case 74:
#line 305 "exprtree.y"
    {(yyval.no)=createTree(0,Tlookup("void"),N_ASSIGN,NULL,(yyvsp[(1) - (4)].no),(yyvsp[(3) - (4)].no),NULL);}
    break;

  case 75:
#line 307 "exprtree.y"
    {printf("hello\n");(yyval.no)=createTree(0,Tlookup("void"),N_ASSIGN,NULL,(yyvsp[(1) - (4)].no),(yyvsp[(3) - (4)].no),NULL);}
    break;

  case 76:
#line 309 "exprtree.y"
    { typecheck((yyvsp[(3) - (10)].no)->type,Tlookup("boolean"),'e');
                                                            (yyval.no)=createTree(0,Tlookup("void"),N_IF_ELSE,NULL,(yyvsp[(3) - (10)].no),(yyvsp[(8) - (10)].no),(yyvsp[(6) - (10)].no));}
    break;

  case 77:
#line 311 "exprtree.y"
    { typecheck((yyvsp[(3) - (8)].no)->type,Tlookup("boolean"),'i');
                                                (yyval.no)=createTree(0,Tlookup("void"),N_IF,NULL,(yyvsp[(3) - (8)].no),(yyvsp[(6) - (8)].no),NULL);}
    break;

  case 78:
#line 314 "exprtree.y"
    { typecheck((yyvsp[(3) - (8)].no)->type,Tlookup("boolean"),'w');
                                                        (yyval.no)=createTree(0,Tlookup("void"),N_WHILE,NULL,(yyvsp[(3) - (8)].no),(yyvsp[(6) - (8)].no),NULL);}
    break;

  case 79:
#line 316 "exprtree.y"
    { typecheck((yyvsp[(5) - (8)].no)->type,Tlookup("boolean"),'w');
                                                        (yyval.no)=createTree(0,Tlookup("void"),N_DOWHILE,NULL,(yyvsp[(2) - (8)].no),(yyvsp[(5) - (8)].no),NULL);}
    break;

  case 80:
#line 319 "exprtree.y"
    {(yyval.no)=createTree(0,Tlookup("void"),N_BREAK,NULL,NULL,NULL,NULL);}
    break;

  case 81:
#line 321 "exprtree.y"
    {(yyval.no)=createTree(0,Tlookup("void"),N_CONT,NULL,NULL,NULL,NULL);}
    break;

  case 82:
#line 324 "exprtree.y"
    {(yyvsp[(3) - (3)].no)->argList=(yyvsp[(1) - (3)].no);
                            (yyval.no)=(yyvsp[(3) - (3)].no);  
                            }
    break;

  case 83:
#line 327 "exprtree.y"
    {(yyval.no)=(yyvsp[(1) - (1)].no);}
    break;

  case 84:
#line 328 "exprtree.y"
    {(yyval.no)=NULL;}
    break;

  case 85:
#line 332 "exprtree.y"
    { typecheck((yyvsp[(1) - (3)].no)->type,(yyvsp[(3) - (3)].no)->type,'a');
                            (yyval.no)=createTree(0,Tlookup("integer"),N_ADD,NULL,(yyvsp[(1) - (3)].no),(yyvsp[(3) - (3)].no),NULL);}
    break;

  case 86:
#line 334 "exprtree.y"
    { typecheck((yyvsp[(1) - (3)].no)->type,(yyvsp[(3) - (3)].no)->type,'a');
                            (yyval.no)=createTree(0,Tlookup("integer"),N_SUB,NULL,(yyvsp[(1) - (3)].no),(yyvsp[(3) - (3)].no),NULL);}
    break;

  case 87:
#line 336 "exprtree.y"
    { typecheck((yyvsp[(1) - (3)].no)->type,(yyvsp[(3) - (3)].no)->type,'a');
                            (yyval.no)=createTree(0,Tlookup("integer"),N_MUL,NULL,(yyvsp[(1) - (3)].no),(yyvsp[(3) - (3)].no),NULL);}
    break;

  case 88:
#line 338 "exprtree.y"
    { typecheck((yyvsp[(1) - (3)].no)->type,(yyvsp[(3) - (3)].no)->type,'a');
                            (yyval.no)=createTree(0,Tlookup("integer"),N_DIV,NULL,(yyvsp[(1) - (3)].no),(yyvsp[(3) - (3)].no),NULL);}
    break;

  case 89:
#line 340 "exprtree.y"
    {typecheck((yyvsp[(1) - (3)].no)->type,(yyvsp[(3) - (3)].no)->type,'a');
                            (yyval.no)=createTree(0,Tlookup("integer"),N_MOD,NULL,(yyvsp[(1) - (3)].no),(yyvsp[(3) - (3)].no),NULL);}
    break;

  case 90:
#line 342 "exprtree.y"
    { typecheck((yyvsp[(1) - (3)].no)->type,(yyvsp[(3) - (3)].no)->type,'b');
                            (yyval.no)=createTree(0,Tlookup("boolean"),N_LT,NULL,(yyvsp[(1) - (3)].no),(yyvsp[(3) - (3)].no),NULL);}
    break;

  case 91:
#line 344 "exprtree.y"
    { typecheck((yyvsp[(1) - (3)].no)->type,(yyvsp[(3) - (3)].no)->type,'b');
                            (yyval.no)=createTree(0,Tlookup("boolean"),N_GT,NULL,(yyvsp[(1) - (3)].no),(yyvsp[(3) - (3)].no),NULL);}
    break;

  case 92:
#line 346 "exprtree.y"
    { typecheck((yyvsp[(1) - (3)].no)->type,(yyvsp[(3) - (3)].no)->type,'b');
                            (yyval.no)=createTree(0,Tlookup("boolean"),N_EQ,NULL,(yyvsp[(1) - (3)].no),(yyvsp[(3) - (3)].no),NULL);}
    break;

  case 93:
#line 348 "exprtree.y"
    { typecheck((yyvsp[(1) - (3)].no)->type,(yyvsp[(3) - (3)].no)->type,'b');
                            (yyval.no)=createTree(0,Tlookup("boolean"),N_NEQ,NULL,(yyvsp[(1) - (3)].no),(yyvsp[(3) - (3)].no),NULL);}
    break;

  case 94:
#line 350 "exprtree.y"
    { typecheck((yyvsp[(1) - (3)].no)->type,(yyvsp[(3) - (3)].no)->type,'b');
                            (yyval.no)=createTree(0,Tlookup("boolean"),N_GE,NULL,(yyvsp[(1) - (3)].no),(yyvsp[(3) - (3)].no),NULL);}
    break;

  case 95:
#line 352 "exprtree.y"
    { typecheck((yyvsp[(1) - (3)].no)->type,(yyvsp[(3) - (3)].no)->type,'b');
                            (yyval.no)=createTree(0,Tlookup("boolean"),N_LE,NULL,(yyvsp[(1) - (3)].no),(yyvsp[(3) - (3)].no),NULL);}
    break;

  case 96:
#line 354 "exprtree.y"
    {typecheck((yyvsp[(1) - (3)].no)->type,(yyvsp[(3) - (3)].no)->type,'b');
                            (yyval.no)=createTree(0,Tlookup("boolean"),N_AND,NULL,(yyvsp[(1) - (3)].no),(yyvsp[(3) - (3)].no),NULL);}
    break;

  case 97:
#line 356 "exprtree.y"
    {typecheck((yyvsp[(1) - (3)].no)->type,(yyvsp[(3) - (3)].no)->type,'b');
                            (yyval.no)=createTree(0,Tlookup("boolean"),N_AND,NULL,(yyvsp[(1) - (3)].no),(yyvsp[(3) - (3)].no),NULL);}
    break;

  case 98:
#line 358 "exprtree.y"
    {
                            typecheck((yyvsp[(1) - (2)].no)->type, NULL, '!');
                            (yyval.no) = createTree(0,Tlookup("boolean"), N_EQ, NULL,(yyvsp[(1) - (2)].no), (yyvsp[(2) - (2)].no), NULL);
                        }
    break;

  case 99:
#line 362 "exprtree.y"
    {
                            typecheck((yyvsp[(1) - (2)].no)->type, NULL, '!');
                            (yyval.no) = createTree(0,Tlookup("boolean"), N_NEQ, NULL,(yyvsp[(1) - (2)].no), (yyvsp[(2) - (2)].no), NULL);
                        }
    break;

  case 100:
#line 366 "exprtree.y"
    {
                            assignType((yyvsp[(1) - (2)].no), 0);
                            (yyval.no) = createTree(0,Tlookup("boolean"), N_EQ, NULL,(yyvsp[(1) - (2)].no), (yyvsp[(2) - (2)].no), NULL);
                        }
    break;

  case 101:
#line 370 "exprtree.y"
    {
                            assignType((yyvsp[(1) - (2)].no), 0);
                            (yyval.no) = createTree(0,Tlookup("boolean"), N_NEQ, NULL, (yyvsp[(1) - (2)].no), (yyvsp[(2) - (2)].no),NULL);
                        }
    break;

  case 102:
#line 374 "exprtree.y"
    {(yyval.no)=(yyvsp[(2) - (3)].no);}
    break;

  case 103:
#line 375 "exprtree.y"
    {(yyvsp[(1) - (1)].no)->type=Tlookup("integer");
        (yyval.no)=(yyvsp[(1) - (1)].no);}
    break;

  case 104:
#line 377 "exprtree.y"
    {(yyval.no)=(yyvsp[(1) - (1)].no);}
    break;

  case 105:
#line 378 "exprtree.y"
    {(yyval.no)=(yyvsp[(1) - (1)].no);}
    break;

  case 106:
#line 379 "exprtree.y"
    {(yyvsp[(1) - (1)].no)->type=Tlookup("string");
        (yyval.no)=(yyvsp[(1) - (1)].no);}
    break;

  case 107:
#line 381 "exprtree.y"
    {(yyval.no)=(yyvsp[(1) - (1)].no);}
    break;

  case 108:
#line 385 "exprtree.y"
    {   assignType((yyvsp[(1) - (4)].no),1);

                                (yyvsp[(1) - (4)].no)->nodetype=N_FUNC;
                                (yyvsp[(1) - (4)].no)->left=reverseList((yyvsp[(3) - (4)].no));
                                (yyval.no)=(yyvsp[(1) - (4)].no);}
    break;

  case 109:
#line 395 "exprtree.y"
    {  assignType((yyvsp[(1) - (1)].no),0);
                (yyval.no)=(yyvsp[(1) - (1)].no);
                }
    break;

  case 110:
#line 398 "exprtree.y"
    {assignType((yyvsp[(1) - (4)].no),2);
                        
                        (yyval.no)=createTree(0,(yyvsp[(1) - (4)].no)->type,N_ARRAY,(yyvsp[(1) - (4)].no)->varname,(yyvsp[(1) - (4)].no),(yyvsp[(3) - (4)].no),NULL);
    }
    break;

  case 111:
#line 402 "exprtree.y"
    {assignType((yyvsp[(1) - (4)].no),2);

                    (yyval.no)=createTree(0,(yyvsp[(1) - (4)].no)->type,N_ARRAY,(yyvsp[(1) - (4)].no)->varname,(yyvsp[(1) - (4)].no),(yyvsp[(3) - (4)].no),NULL);

    }
    break;


/* Line 1267 of yacc.c.  */
#line 2299 "y.tab.c"
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


#line 409 "exprtree.y"


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

    TInstall("integer",1,NULL);
    TInstall("string",1,NULL);
    TInstall("boolean",1,NULL);
    TInstall("void",0,NULL);
    TInstall("dummy",0,NULL);
    yyparse();
    return 0;
}
