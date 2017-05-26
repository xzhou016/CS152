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
     LO = 258,
     INTEGER = 259,
     ARRAY = 260,
     FUNCTION = 261,
     BEGIN_PARAMS = 262,
     END_PARAMS = 263,
     BEGIN_LOCALS = 264,
     END_LOCALS = 265,
     BEGIN_BODY = 266,
     END_BODY = 267,
     BEGINLOOP = 268,
     ENDLOOP = 269,
     IF = 270,
     THEN = 271,
     ELSE = 272,
     ENDIF = 273,
     DO = 274,
     WHILE = 275,
     READ = 276,
     WRITE = 277,
     CONTINUE = 278,
     RETURN = 279,
     TRUE = 280,
     FALSE = 281,
     ASSIGN = 282,
     OF = 283,
     OR = 284,
     AND = 285,
     NOT = 286,
     NE = 287,
     EQ = 288,
     GE = 289,
     GT = 290,
     LE = 291,
     LT = 292,
     SUB = 293,
     ADD = 294,
     MOD = 295,
     DIV = 296,
     TIMES = 297,
     UMINUS = 298,
     L_BRAC = 299,
     R_BRAC = 300,
     L_PARENT = 301,
     R_PARENT = 302,
     COMMA = 303,
     SEMICOLON = 304,
     COLON = 305,
     HI = 306,
     ID = 307,
     NUMBER = 308
   };
#endif


#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{
/* Line 2058 of yacc.c  */
#line 9 "mini_l.y"


   int        junk;
   int        int_val;
   string*    ident;
   string*    str_val;
	
   Program*              program;
   list<Function*>*      functions;	// for the non-terminal "Functions"
   list<Declaration*>*   declarations;  // for the non-terminal "Declarations"
   list<Statement*>*     statements;   
   list<Var*>*           vars;
   list<Expression*>*    expressions;
   list<Expression*>*    nonemptyexpressionlist;
   list<string*>*        ids;
   Function*             function;   
   Declaration*          declaration;      
   Statement*            statement;
   Expression*           expression;
   Var*                  var;
   BoolExpr*             boolexpr;


/* Line 2058 of yacc.c  */
#line 134 "y.tab.h"
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
