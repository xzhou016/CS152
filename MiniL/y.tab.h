/* A Bison parser, made by GNU Bison 2.7.  */

/* Bison interface for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2012 Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     NUMBER = 258,
     ID = 259,
     L_PARENT = 260,
     R_PARENT = 261,
     L_BRAC = 262,
     R_BRAC = 263,
     SUB = 264,
     SEMICOLON = 265,
     COLON = 266,
     COMMA = 267,
     TIMES = 268,
     DIV = 269,
     MOD = 270,
     ADD = 271,
     LT = 272,
     LTE = 273,
     GT = 274,
     GTE = 275,
     EQ = 276,
     NEQ = 277,
     NOT = 278,
     AND = 279,
     OR = 280,
     ASSIGN = 281,
     FUNCTION = 282,
     BEGIN_PARAMS = 283,
     END_PARAMS = 284,
     BEGIN_LOCALS = 285,
     END_LOCALS = 286,
     BEGIN_BODY = 287,
     END_BODY = 288,
     INTEGER = 289,
     ARRAY = 290,
     OF = 291,
     IF = 292,
     THEN = 293,
     ENDIF = 294,
     ELSE = 295,
     TRUE = 296,
     FALSE = 297,
     WHILE = 298,
     DO = 299,
     BEGINLOOP = 300,
     ENDLOOP = 301,
     CONTINUE = 302,
     READ = 303,
     WRITE = 304,
     RETURN = 305
   };
#endif


#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{
/* Line 2058 of yacc.c  */
#line 10 "mini_l.y"

	int	int_val;
	char *	str_val;


/* Line 2058 of yacc.c  */
#line 113 "y.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;

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

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
