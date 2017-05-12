%{
	#include<stdio.h>
	#include<string.h>
	void yyerr(int, char *);
	extern int lineNum;
	extern int colNum;
	FILE *yyin;
%}

%union{
	int	int_val;
	char *	str_val;
}
%start program

%token L_PARENT R_PARENT L_BRAC R_BRAC SUB SEMICOLON COLON COMMA
%token TIMES DIV MOD ADD
%token LT LTE GT GTE EQ NEQ
%token NOT AND OR ASSIGN

%token FUNCTION BEGIN_PARAMS END_PARAMS BEGIN_LOCALS END_LOCALS BEGIN_BODY END_BODY INTERGER ARRAY OF
%token IF THEN ENDIF ELSE 
%token WHILE DO BEGINLOOP ENDLOOP CONTINUE READ WRITE

%%
program: /* empty */
	| function program
	;
function: FUNCTION ID SEMICOLON BEGIN_PARAMS declaration SEMICOLON END_PARAMS BEGIN_LOCALS declaration SEMICOLON END_LOCALS BEGIN_BODY statement SEMICOLON END_BODY
	;
declaration: {printf("Empty declaration.\n");}
	| ID comma COLON array INTEGER SEMICOLON declaration
	;
comma: 	{printf("Empty comma\n");}
	| COMMA ID comma
	;
array:	{printf("No array\n");}
	| ARRAY L_BRAC NUMBER R_BRAC OF
	;

statement: {printf("Empty statement\n");} 
	|var ASSIGN
	| IF bool_expr THEN statement SEMICOLON more_statement else ENDIF
	| WHILE bool_expr BEGINLOOP statement SEMICOLON more_statement ENDLOOP
	| DO BEGINLOOP statement SEMICOLON more_statement ENDLOOP WHILE bool-exp
	| READ var var_comma
	| COTINUE
	| RETURN expression 
	;
bool_expr: relation_and_expr
	| relation_and_expr OR relation_and_expr
	;
relation_and_expr: relation_expr
	| relation_expr AND relation_expr
	;
relation_expr : NOT 
	| 

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
