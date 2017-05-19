%{
	#include<stdio.h>
	#include<string.h>
	#include "y.tab.h"
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
\(			{return L_PARENT; 		colNum += yyleng;}
\)			{return R_PARENT;			colNum += yyleng;}
\[			{return L_BRAC;				colNum += yyleng;}
\]			{return R_BRAC;				colNum += yyleng;}
\-			{return SUB;					colNum += yyleng;}
\;			{return SEMICOLON;		colNum += yyleng;}
\:			{return COLON;				colNum += yyleng;}
\,			{return COMMA;				colNum += yyleng;}

\*			{return TIMES;				colNum += yyleng;}
\/			{return DIV;					colNum += yyleng;}
\%			{return MOD;					colNum += yyleng;}
\+			{return ADD;					colNum += yyleng;}

\<			{return LT;						colNum += yyleng;}
\<=			{return LTE;					colNum += yyleng;}
\>			{return GT;						colNum += yyleng;}
\>=			{return GTE;					colNum += yyleng;}
\==			{return EQ;						colNum += yyleng;}
\<\>		{return NEQ;					colNum += yyleng;}

not			{return NOT;					colNum += yyleng;}
and			{return AND;					colNum += yyleng;}
or			{return OR;						colNum += yyleng;}
\:=			{return ASSIGN;				colNum += yyleng;}

true		{return TRUE;					colNum += yyleng;}
false 	{return FALSE; 				colNum += yyleng;}


function			{return FUNCTION;						colNum += yyleng;}
beginparams		{return BEGIN_PARAMS;				colNum += yyleng;}
endparams			{return END_PARAMS;					colNum += yyleng;}
beginlocals		{return BEGIN_LOCALS;				colNum += yyleng;}
endlocals			{return END_LOCALS;					colNum += yyleng;}
beginboday		{return BEGIN_BODY;					colNum += yyleng;}
endbody				{return END_BODY;						colNum += yyleng;}
interger			{return INTERGER;						colNum += yyleng;}
array					{return ARRAY;							colNum += yyleng;}
of						{return OF;									colNum += yyleng;}
if						{return IF;									colNum += yyleng;}
then					{return THEN;								colNum += yyleng;}
endif					{return ENDIF;							colNum += yyleng;}
else					{return ELSE;								colNum += yyleng;}
while					{return WHILE;							colNum += yyleng;}
do						{return DO;									colNum += yyleng;}
beginloop			{return BEGINLOOP;					colNum += yyleng;}
endloop				{return ENDLOOP;						colNum += yyleng;}
continue			{return CONTINUE;						colNum += yyleng;}
read					{return READ;								colNum += yyleng;}
write					{return WRITE;							colNum += yyleng;}
return				{return RETURN;							colNum += yyleng;}

{WHITE_SPACE}		{colNum += yyleng;}
\n							{++lineNum;				colNum = 1;}
{COMMENT}				{colNum += yyleng;}
{ID}						{return ID;				printf("ID %s\n", yytext);		colNum += yyleng;}
{NUMBER}				{return NUMBER;		printf("NUMBER %s\n", yytext);		colNum += yyleng;}
.								{printf("Error at line %d, column %d: unrecognized symbol \"%s\"\n", lineNum, colNum, yytext);}
{ID_ERR_1}			{printf("Error at line %d, column %d: identifier \"%s\" must begin with a letter\n", lineNum, colNum, yytext);}
{ID_ERR_2}			{printf("Error at line %d, column %d: identifier \"%s\" cannot end with an underscore\n", lineNum, colNum, yytext);}
