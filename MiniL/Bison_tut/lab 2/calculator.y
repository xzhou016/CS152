%{
#include <stdio.h>
#include <string.h>
#include <math.h>

void yyerror(const char *str);
int yywrap();
int yylex(void);
;
%}

%define api.value.type {double}

%token NUMBER PLUS MINUS MULT DIV L_PAREN R_PAREN EQUAL NEWLINE
%left MINUS PLUS
%left MULT DIV

%% 
program: 
	program statement
	| /* Empty */
	;

statement:
	NEWLINE			
	| expression		{printf("result: %i\n", $1);}
	| float_expression	{printf("result: %f\n", $1);}
	;


expression:
	I_NUMBER 			{$$ = $1;}
	| expression PLUS expression 	{$$ = $1 + $3;}
	| expression MINUS expression 	{$$ = $1 - $3;}
	| expression MULT expression 	{$$ = $1 * $3;}
	| expression DIV expression 	{$$ = $1 / (float)$3;}
	| MINUS expression 		{$$ = -$2;}
	| L_PAREN expression R_PAREN	{$$ = $2;}
	;
%%
void yyerror(const char *str)
{
	fprintf(stderr,"error: %s\n",str);
}

