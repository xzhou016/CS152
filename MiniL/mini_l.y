%{
	#include<stdio.h>
	#include<string.h>
	void yyerr(int, char *);
	void yyerr(char *);
	extern int lineNum;
	extern int colNum;
	FILE *yyin;
%}

%union{
	int	int_val;
	char *	str_val;
}
%error-verbose
%start program

%token <int_val>NUMBER <str_val>ID

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
function: FUNCTION ID SEMICOLON BEGIN_PARAMS declaration SEMICOLON END_PARAMS BEGIN_LOCALS declaration SEMICOLON END_LOCALS BEGIN_BODY statement SEMICOLON END_BODY {printf("FUNCTION ID SEMICOLON BEGIN_PARAMS declaration SEMICOLON END_PARAMS BEGIN_LOCALS declaration SEMICOLON END_LOCALS BEGIN_BODY statement SEMICOLON END_BODY\n");}
	;
declaration: 																							{printf("Empty declaration.\n");}
	| ID comma COLON array INTEGER SEMICOLON declaration 		{printf("ID comma COLON array INTEGER SEMICOLON declaration\n");}
	;
comma: 								{printf("Empty comma\n");}
	| COMMA ID comma 		{printf("COMMA ID comma\n");}
	;
array:															{printf("No array\n");}
	| ARRAY L_BRAC NUMBER R_BRAC OF 	{printf("ARRAY L_BRAC NUMBER R_BRAC OF\n");}
	;


statement: 																																			{printf("Empty statement\n");}
	|	var ASSIGN 																																	{printf("var ASSIGN\n");}
	| IF bool_expr THEN statement SEMICOLON more_statement else ENDIF 						{printf("IF bool_expr THEN statement SEMICOLON more_statement else ENDIF\n");}
	| WHILE bool_expr BEGINLOOP statement SEMICOLON more_statement ENDLOOP 				{printf("WHILE bool_expr BEGINLOOP statement SEMICOLON more_statement ENDLOOP\n");}
	| DO BEGINLOOP statement SEMICOLON more_statement ENDLOOP WHILE bool_expr			{printf("DO BEGINLOOP statement SEMICOLON more_statement ENDLOOP WHILE bool_expr\n");}
	| READ var var_comma 																													{printf("READ var var_comma\n");}
	| CONTINUE 																																		{printf("CONTINUE\n");}
	| RETURN expression																														{printf("RETURN expression\n");}
	;
more_statement: 												{printf("Empty statement\n");}
	| statement SEMICOLON more_statement	{printf("statement SEMICOLON more_statement\n");}
	;


bool_expr: relation_and_expr more_bool_expr 						{printf("relation_and_expr more_bool_expr\n");}
	;
relation_and_expr: relation_expr more_relation_and_expr {printf("relation_expr more_relation_and_expr\n");}
	;
more_bool_expr:																			{printf("Empty bool expression\n");}
	| OR relation_and_expr more_bool_expr 						{printf("OR relation_and_expr bool_expr\n");}
	;
more_relation_and_expr: 														{printf("Empty relation_and_expr\n");}
	| AND relation_expr  more_relation_and_expr				{printf("AND relation_expr  more_relation_and_expr\n");}
	;

relation_expr: NOT more_relation_expr 							{printf("NOT more_relation_expr\n");}
	| more_relation_expr															{printf("more_relation_expr\n");}
	;
more_relation_expr: expression compare expression 	{printf("expression compare expression\n");}
 	| TRUE																						{printf("TRUE\n");}
	| FALSE																						{printf("FALSE\n");}
	| L_PARENT bool_expr R_PARENT											{printf("L_PARENT bool_expr R_PARENT\n");}
	;
expression: multiplicative_expr more_expression			{printf("multiplicative_expr more_expression\n");}
	;
compare: EQ																					{printf("EQ\n");}
	|	NEQ																							{printf("NEQ\n");}
	|	LT																							{printf("LT\n");}
	| GT																							{printf("GT\n");}
	| LTE																							{printf("LTE\n");}
	| GTE																							{printf("GTE\n");}
more_expression:																		{printf("Empty expression\n");}
	| ADD multiplicative_expr more_expression					{printf("ADD multiplicative_expr more_expression\n");}
	| SUB multiplicative_expr more_expression					{printf("SUB multiplicative_expr more_expression\n");}
	;
multiplicative_expr: term more_multiplicative_expr	{printf("term more_multiplicative_expr\n");}
	;
more_multiplicative_expr:														{printf("Empty multiplicative_expr\n");}
	| TIMES term more_multiplicative_expr							{printf("TIMES term more_multiplicative_expr\n");}
	| DIV term more_multiplicative_expr								{printf("DIV term more_multiplicative_expr\n");}
	| MOD term more_multiplicative_expr								{printf("MOD term more_multiplicative_expr\n");}
	;


term: SUB var																				{printf("SUB var\n");}
	| NUMBER																					{printf("NUMBER\n");}
	| L_PARENT expression R_PARENT										{printf("L_PARENT expression R_PARENT\n");}
	| ID L_PARENT term_expr term_comma R_PARENT				{printf("ID L_PARENT term_expr term_comma R_PARENT\n");}
	;
term_expr:																					{printf("Empty term_expr\n");}
	| expression																			{printf("expression\n");}
	;
term_comma:																					{printf("Empty term_comma\n");}
	| COMMA expression term_comma											{printf("COMMA expression term_comma\n");}
	;


else:																								{printf("Empty else\n");}
	| ELSE statement SEMICOLON more_statement					{printf("ELSE statement SEMICOLON more_statement\n");}
	;


var: ID more_var																		{printf("ID more_var\n");}
		;
more_var:																						{printf("Empty var\n");}
	| L_BRAC expression R_BRAC												{printf("L_BRAC expression R_BRAC\n");}
	;
var_comma:																					{printf("Empty var_comma\n");}
	| COMMA var var_comma															{printf("COMMA var var_comma\n");}
	;



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

void yyerr(char* error_symbol){
	printf("Unrecognized on line %d, colNum %d: %s\n",  lineNum, colNum);
}

int main(int argc, char** argv){
    FILE *fh;

    if(argc == 2 && (fh = fopen(argv[1], "r")))
        yyin = fh;
    else
	yyin = stdin;
    yylex();

}
