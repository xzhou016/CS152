%{
	#include<stdio.h>
	#include<string.h>
	int lineNum = 1;
	int colNum = 1;
	void yyerr(int, char *);
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
\(			{printf("L_PARENT\n");		colNum += yyleng;}
\)			{printf("R_PARENT\n");		colNum += yyleng;}
\[			{printf("L_BRAC\n");		colNum += yyleng;}
\]			{printf("R_BRAC\n");		colNum += yyleng;}
\-			{printf("SUB\n");		colNum += yyleng;}
\;			{printf("SEMICOLON\n");		colNum += yyleng;}
\:			{printf("COLON\n");		colNum += yyleng;}
\,			{printf("COMMA\n");		colNum += yyleng;}

\*			{printf("TIMES\n");		colNum += yyleng;}
\/			{printf("DIV\n");		colNum += yyleng;}
\%			{printf("MOD\n");		colNum += yyleng;}
\+			{printf("ADD\n");		colNum += yyleng;}

\<			{printf("LT\n");		colNum += yyleng;}
\<=			{printf("LTE\n");		colNum += yyleng;}
\>			{printf("GT\n");		colNum += yyleng;}
\>=			{printf("GTE\n");		colNum += yyleng;}
\==			{printf("EQ\n");		colNum += yyleng;}
\<\>			{printf("NEQ\n");		colNum += yyleng;}

not			{printf("NOT\n");		colNum += yyleng;}
and			{printf("AND\n");		colNum += yyleng;}
or			{printf("OR\n");		colNum += yyleng;}
\:=			{printf("ASSIGN\n");		colNum += yyleng;}
	

function		{printf("FUNCTION\n");		colNum += yyleng;}
beginparams		{printf("BEGIN_PARAMS\n");	colNum += yyleng;}
endparams		{printf("END_PARAMS\n");	colNum += yyleng;}
beginlocals		{printf("BEGIN_LOCALS\n");	colNum += yyleng;}
endlocals		{printf("END_LOCALS\n");	colNum += yyleng;}
beginboday		{printf("BEGIN_BODY\n");	colNum += yyleng;}
endbody			{printf("END_BODY\n");		colNum += yyleng;}
interger		{printf("INTERGER\n");		colNum += yyleng;}
array			{printf("ARRAY\n");		colNum += yyleng;}
of			{printf("OF\n");		colNum += yyleng;}
if			{printf("IF\n");		colNum += yyleng;}
then			{printf("THEN\n");		colNum += yyleng;}
endif			{printf("ENDIF\n");		colNum += yyleng;}
else			{printf("ELSE\n");		colNum += yyleng;}
while			{printf("WHILE\n");		colNum += yyleng;}
do			{printf("DO\n");		colNum += yyleng;}
beginloop		{printf("BEGINLOOP\n");		colNum += yyleng;}
endloop			{printf("ENDLOOP\n");		colNum += yyleng;}
continue		{printf("CONTINUE\n");		colNum += yyleng;}
read			{printf("READ\n");		colNum += yyleng;}
write			{printf("WRITE\n");		colNum += yyleng;}

{WHITE_SPACE}		{colNum += yyleng;}
\n			{++lineNum;			colNum = 1;}
{COMMENT}		{colNum += yyleng;}
{ID}			{printf("ID %s\n", yytext);		colNum += yyleng;}
{NUMBER}		{printf("NUMBER %s\n", yytext);		colNum += yyleng;}
.			{yyerr(1, yytext);}
{ID_ERR_1}		{yyerr(2, yytext);}
{ID_ERR_2}		{yyerr(3, yytext);}


%%	
void yyerr(int error_code, char* error_symbol) {
	switch (error_code)  {
		case 1: {
			printf("Error at line %d, column %d: unrecognized symbol \"%s\"\n", lineNum, colNum, error_symbol);
		break;		
		}
		case 2: {
			printf("Error at line %d, column %d: identifier \"%s\" must begin with a letter\n", lineNum, colNum, error_symbol);
		break;		
		}
		case 3: {
			printf("Error at line %d, column %d: identifier \"%s\" cannot end with an underscore\n", lineNum, colNum, error_symbol);
		break;		
		}
	}
	exit(1);
}

int main(int argc, char** argv){
    FILE *fh;

    if(argc == 2 && (fh = fopen(argv[1], "r")))
        yyin = fh;
    else 
	yyin = stdin;
    yylex();

}
