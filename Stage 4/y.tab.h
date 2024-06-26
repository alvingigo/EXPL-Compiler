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
     DECL = 285,
     ENDDECL = 286,
     INT = 287,
     STR = 288
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
#define DECL 285
#define ENDDECL 286
#define INT 287
#define STR 288




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 22 "exprtree.y"
{
    struct tnode* no;
    
}
/* Line 1529 of yacc.c.  */
#line 120 "y.tab.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

