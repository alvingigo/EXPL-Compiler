/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton interface for Bison's Yacc-like parsers in C

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




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 23 "exprtree.y"
{
    struct tnode* no;
    
}
/* Line 1529 of yacc.c.  */
#line 146 "y.tab.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

