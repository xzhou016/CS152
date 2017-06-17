%{
	#include <stdio.h>
	#include <string.h>
	#include "y.tab.h"
	int lineNum = 1;
	int colNum = 1;
        extern int yylineno;
        int yyerror( char* s );
%}

%option         noyywrap
%x              inComment 
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
\(       {return yylval.junk = L_PARENT;  colNum += yyleng;}
\)       {return yylval.junk = R_PARENT;  colNum += yyleng;}
\[       {return yylval.junk = L_BRAC;    colNum += yyleng;}
\]       {return yylval.junk = R_BRAC;    colNum += yyleng;}
\-       {return yylval.junk = SUB;       colNum += yyleng;}
\;       {return yylval.junk = SEMICOLON; colNum += yyleng;}
\:       {return yylval.junk = COLON;     colNum += yyleng;}
\,       {return yylval.junk = COMMA;     colNum += yyleng;}

\*       {return yylval.junk = TIMES;     colNum += yyleng;}
\/       {return yylval.junk = DIV;       colNum += yyleng;}
\%       {return yylval.junk = MOD;       colNum += yyleng;}
\+       {return yylval.junk = ADD;       colNum += yyleng;}

\<       {return yylval.junk = LT;        colNum += yyleng;}
\<=       {return yylval.junk = LTE;      colNum += yyleng;}
\>              {return yylval.junk = GT; colNum += yyleng;}
\>=       {return yylval.junk = GTE;colNum += yyleng;}
\==       {return yylval.junk = EQ;colNum += yyleng;}
\<\>       {return yylval.junk = NEQ;colNum += yyleng;}

not       {return yylval.junk = NOT;colNum += yyleng;}
and       {return yylval.junk = AND;colNum += yyleng;}
or       {return yylval.junk = OR;colNum += yyleng;}
\:=       {return yylval.junk = ASSIGN;	colNum += yyleng;}

true       {return yylval.junk = TRUE;      colNum += yyleng;}
false       {return yylval.junk = FALSE;  colNum += yyleng;}


function       {return yylval.junk = FUNCTION;     colNum += yyleng;}
beginparams    {return yylval.junk = BEGINPARAMS;  colNum += yyleng;}
endparams      {return yylval.junk = ENDPARAMS;    colNum += yyleng;}
beginlocals    {return yylval.junk = BEGINLOCALS;  colNum += yyleng;}
endlocals      {return yylval.junk = END_LOCALS;colNum += yyleng;}
beginbody      {return yylval.junk = BEGIN_BODY;colNum += yyleng;}
endbody	       {return yylval.junk = END_BODY;colNum += yyleng;}
integer	       {return yylval.junk = INTEGER;colNum += yyleng;}
array          {return yylval.junk = ARRAY;	colNum += yyleng;}
of	       {return yylval.junk = OF;colNum += yyleng;}
if	       {return yylval.junk = IF;colNum += yyleng;}
then	       {return yylval.junk = THEN;colNum += yyleng;}
endif          {return yylval.junk = ENDIF;	colNum += yyleng;}
else	       {return yylval.junk = ELSE;colNum += yyleng;}
while          {return yylval.junk = WHILE;colNum += yyleng;}
do	       {return yylval.junk = DO;colNum += yyleng;}
beginloop      {return yylval.junk = BEGINLOOP;colNum += yyleng;}
endloop        {return yylval.junk = ENDLOOP;colNum += yyleng;}
continue       {return yylval.junk = CONTINUE;colNum += yyleng;}
read           {return yylval.junk = READ;colNum += yyleng;}
write          {return yylval.junk = WRITE;	colNum += yyleng;}
return         {return yylval.junk = RETURN;	colNum += yyleng;}

{WHITE_SPACE}  {colNum += yyleng;}
\n             {++lineNum; colNum = 1;}
{COMMENT}      {colNum += yyleng;}
{ID}	       { yylval.ident   = new std::string( yytext ); return ID; colNum += yyleng; }
{NUMBER}       {yylval.int_val = atoi( yytext ); return  NUMBER;}
.              {printf("Error at line %d, column %d: unrecognized symbol \"%s\"\n", lineNum, colNum, yytext);}
{ID_ERR_1}     {printf("Error at line %d, column %d: identifier \"%s\" must begin with a letter\n", lineNum, colNum, yytext);}
{ID_ERR_2}      {printf("Error at line %d, column %d: identifier \"%s\" cannot end with an underscore\n", lineNum, colNum, yytext);}
