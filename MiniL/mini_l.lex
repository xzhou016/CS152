%{
	#include<stdio.h>
	#include<string.h>
	#include "tok.h"
	int lineNum = 1;
	int colNum = 1;
%}

DIGIT 		[0-9]
LETTER 		[a-zA-Z]
UNDERLINE	[_]
WHITE_SPACE	[ \t]+
NUMBER 		{DIGIT}+
COMMENT 	##.*
ID 		{LETTER}(({LETTER}|{NUMBER}|{UNDERLINE})*({LETTER}|{NUMBER}))?
ID_ERR_1 	{NUMBER}+{ID}
ID_ERR_2	{ID}{UNDERLINE}

%%
\(			{return L_PARENT; 	printf("L_PARENT\n");		colNum += yyleng;}
\)			{return R_PARENT;	printf("R_PARENT\n");		colNum += yyleng;}
\[			{return L_BRAC;		printf("L_BRAC\n");		colNum += yyleng;}
\]			{return R_BARC;		printf("R_BRAC\n");		colNum += yyleng;}
\-			{return SUB;		printf("SUB\n");		colNum += yyleng;}
\;			{return SEMICOLON;	printf("SEMICOLON\n");		colNum += yyleng;}
\:			{return COLON;		printf("COLON\n");		colNum += yyleng;}
\,			{return COMMA;		printf("COMMA\n");		colNum += yyleng;}

\*			{return TIMES;		printf("TIMES\n");		colNum += yyleng;}
\/			{return DIV;		printf("DIV\n");		colNum += yyleng;}
\%			{return MOD;		printf("MOD\n");		colNum += yyleng;}
\+			{return ADD;		printf("ADD\n");		colNum += yyleng;}

\<			{return LT;		printf("LT\n");			colNum += yyleng;}
\<=			{return LTE;		printf("LTE\n");		colNum += yyleng;}
\>			{return GT;		printf("GT\n");			colNum += yyleng;}
\>=			{return GTE;		printf("GTE\n");		colNum += yyleng;}
\==			{return EQ;		printf("EQ\n");			colNum += yyleng;}
\<\>			{return NEQ;		printf("NEQ\n");		colNum += yyleng;}

not			{return NOT;		printf("NOT\n");		colNum += yyleng;}
and			{return AND;		printf("AND\n");		colNum += yyleng;}
or			{return OR;		printf("OR\n");			colNum += yyleng;}
\:=			{return ASSIGN;		printf("ASSIGN\n");		colNum += yyleng;}
	

function		{return FUNCTION;	printf("FUNCTION\n");		colNum += yyleng;}
beginparams		{return BEGIN_PARAMS;	printf("BEGIN_PARAMS\n");	colNum += yyleng;}
endparams		{return END_PARAMS;	printf("END_PARAMS\n");		colNum += yyleng;}
beginlocals		{return BEGIN_LOCALS;	printf("BEGIN_LOCALS\n");	colNum += yyleng;}
endlocals		{return END_LOCALS;	printf("END_LOCALS\n");		colNum += yyleng;}
beginboday		{return BEGIN_BODY;	printf("BEGIN_BODY\n");		colNum += yyleng;}
endbody			{return END_BODY;	printf("END_BODY\n");		colNum += yyleng;}
interger		{return INTERGER;	printf("INTERGER\n");		colNum += yyleng;}
array			{return ARRAY;		printf("ARRAY\n");		colNum += yyleng;}
of			{return OF;		printf("OF\n");			colNum += yyleng;}
if			{return IF;		printf("IF\n");			colNum += yyleng;}
then			{return THEN;		printf("THEN\n");		colNum += yyleng;}
endif			{return ENDIF;		printf("ENDIF\n");		colNum += yyleng;}
else			{return ELSE;		printf("ELSE\n");		colNum += yyleng;}
while			{return WHILE;		printf("WHILE\n");		colNum += yyleng;}
do			{return DO;		printf("DO\n");			colNum += yyleng;}
beginloop		{return BEGINLOOP;	printf("BEGINLOOP\n");		colNum += yyleng;}
endloop			{return ENDLOOP;	printf("ENDLOOP\n");		colNum += yyleng;}
continue		{return CONTINUE;	printf("CONTINUE\n");		colNum += yyleng;}
read			{return READ;		printf("READ\n");		colNum += yyleng;}
write			{return WRITE;		printf("WRITE\n");		colNum += yyleng;}

{WHITE_SPACE}		{colNum += yyleng;}
\n			{++lineNum;				colNum = 1;}
{COMMENT}		{colNum += yyleng;}
{ID}			{printf("ID %s\n", yytext);		colNum += yyleng;}
{NUMBER}		{printf("NUMBER %s\n", yytext);		colNum += yyleng;}
.			{yyerr(1, yytext);}
{ID_ERR_1}		{yyerr(2, yytext);}
{ID_ERR_2}		{yyerr(3, yytext);}

