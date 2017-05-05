%{
	#include<stdio.h>
	#include<string.h>
	void yyerr(int, char *);

%}

%token L_PARENT R_PARENT L_BRAC R_BRAC SUB SEMICOLON COLON COMMA
%token TIMES DIV MOD ADD
%token LT LTE GT GTE EQ NEQ
%token NOT AND OR ASSIGN

%token FUNCTIONS BEGIN_PARAMS END_PARAMS BEGIN_LOCALS END_LOCALS BEGIN_BODY END_BODY INTERGER ARRAY OF
%token IF THEN ENDIF ELSE WHILE DO BEGINLOOP ENDLOOP CONTINUE READ WRITE


%%




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
