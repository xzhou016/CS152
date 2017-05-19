%{
	#include<stdio.h>
	#include<string.h>
	void yyerror(const char * error_symbol);
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

%token FUNCTION BEGIN_PARAMS END_PARAMS BEGIN_LOCALS END_LOCALS BEGIN_BODY END_BODY INTEGER ARRAY OF
%token IF THEN ENDIF ELSE TRUE FALSE
%token WHILE DO BEGINLOOP ENDLOOP CONTINUE READ WRITE RETURN

%%
program: /* empty */
	| function program
	;
function: FUNCTION ID SEMICOLON 
	BEGIN_PARAMS declaration END_PARAMS 
	BEGIN_LOCALS declaration END_LOCALS 
	BEGIN_BODY statement more_statement END_BODY 
	{printf("function -> FUNCTION ID SEMICOLON BEGIN_PARAMS declaration SEMICOLON END_PARAMS BEGIN_LOCALS declaration SEMICOLON END_LOCALS BEGIN_BODY statement more_statement SEMICOLON END_BODY\n");}
	{}
	;
declaration: 								{printf("declaration -> Empty declaration\n");}
	| ID comma COLON array INTEGER SEMICOLON declaration 		{printf("declaration -> ID comma COLON array INTEGER SEMICOLON declaration\n");}
	;
comma: 									{printf("comma -> Empty comma\n");}
	| COMMA ID comma 						{printf("comma -> COMMA ID comma\n");}
	;
array:									{printf("array -> Empty array\n");}
	| ARRAY L_BRAC NUMBER R_BRAC OF 				{printf("array -> ARRAY L_BRAC NUMBER R_BRAC OF\n");}
	;


statement:											{printf("statement -> Empty statement\n");}
	| var ASSIGN expression									{printf("statement -> var ASSIGN\n");}
	| IF L_PARENT bool_expr R_PARENT THEN statement SEMICOLON more_statement else ENDIF	{printf("statement -> IF bool_expr THEN statement SEMICOLON more_statement else ENDIF\n");}
	| WHILE bool_expr BEGINLOOP statement SEMICOLON more_statement ENDLOOP 			{printf("statement -> WHILE bool_expr BEGINLOOP statement SEMICOLON more_statement ENDLOOP\n");}
	| DO BEGINLOOP statement SEMICOLON more_statement ENDLOOP WHILE bool_expr		{printf("statement -> DO BEGINLOOP statement SEMICOLON more_statement ENDLOOP WHILE bool_expr\n");}
	| READ var var_comma 									{printf("statement -> READ var var_comma\n");}
	| CONTINUE 										{printf("statement -> CONTINUE\n");}
	| RETURN expression									{printf("statement -> RETURN expression\n");}
	| WRITE var var_comma									{printf("statement -> READ var var_comma\n");}
	;
more_statement: 										{printf("statement -> Empty statement\n");}
	| statement SEMICOLON more_statement							{printf("statement -> statement SEMICOLON more_statement\n");}
	;


bool_expr: relation_and_expr more_bool_expr 						{printf("bool_expr -> relation_and_expr more_bool_expr\n");}
	;
relation_and_expr: relation_expr more_relation_and_expr 				{printf("relation_and_expr -> relation_expr more_relation_and_expr\n");}
	;
more_bool_expr:										{printf("bool_expr -> Empty bool expression\n");}
	| OR relation_and_expr more_bool_expr 						{printf("bool_expr -> OR relation_and_expr bool_expr\n");}
	;
more_relation_and_expr: 								{printf("relation_and_expr -> Empty relation_and_expr\n");}
	| AND relation_expr  more_relation_and_expr					{printf("relation_and_expr -> AND relation_expr  more_relation_and_expr\n");}
	;

relation_expr: NOT more_relation_expr 							{printf("relation_expr -> NOT more_relation_expr\n");}
	| more_relation_expr								{printf("relation_expr -> more_relation_expr\n");}
	;
more_relation_expr: expression compare expression 					{printf("relation_expr -> expression compare expression\n");}
 	| TRUE										{printf("relation_expr -> TRUE\n");}
	| FALSE										{printf("relation_expr -> FALSE\n");}
	| L_PARENT bool_expr R_PARENT							{printf("relation_expr -> L_PARENT bool_expr R_PARENT\n");}
	;
expression: multiplicative_expr more_expression						{printf("expression -> multiplicative_expr more_expression\n");}
	;
compare: EQ										{printf("compare -> EQ\n");}
	| NEQ										{printf("compare -> NEQ\n");}
	| LT										{printf("compare -> LT\n");}
	| GT										{printf("compare -> GT\n");}
	| LTE										{printf("compare -> LTE\n");}
	| GTE										{printf("compare -> GTE\n");}
more_expression:									{printf("expression -> Empty expression\n");}
	| ADD multiplicative_expr more_expression					{printf("expression -> ADD multiplicative_expr more_expression\n");}
	| SUB multiplicative_expr more_expression					{printf("expression -> SUB multiplicative_expr more_expression\n");}
	;
multiplicative_expr: term more_multiplicative_expr					{printf("multiplicative_expr -> term more_multiplicative_expr\n");}
	;
more_multiplicative_expr:								{printf("multiplicative_expr -> Empty multiplicative_expr\n");}
	| TIMES term more_multiplicative_expr						{printf("multiplicative_expr -> TIMES term more_multiplicative_expr\n");}
	| DIV term more_multiplicative_expr						{printf("multiplicative_expr -> DIV term more_multiplicative_expr\n");}
	| MOD term more_multiplicative_expr						{printf("multiplicative_expr -> MOD term more_multiplicative_expr\n");}
	;


term: SUB more_term						{printf("term -> SUB more_term\n");}
	| more_term						{printf("term -> more_term\n");}
	| ID  L_PARENT term_expr term_comma R_PARENT		{printf("term -> ID  L_PARENT term_expr term_comma R_PARENT\n");}
	;
more_term: var				{printf("term -> var\n");}
	| NUMBER			{printf("term -> NUMBER\n");}
	| L_PARENT expression R_PARENT	{printf("term -> L_PARENT expression R_PARENT\n");}
	;

term_expr:				{printf("term_expr -> Empty term_expr\n");}
	| expression			{printf("term_expr -> expression\n");}
	;
term_comma:				{printf("term_comma -> Empty term_comma\n");}
	| COMMA expression term_comma	{printf("term_comma -> COMMA expression term_comma\n");}
	;


else:											{printf("else -> Empty else\n");}
	| ELSE statement SEMICOLON more_statement					{printf("else -> ELSE statement SEMICOLON more_statement\n");}
	;


var: ID more_var									{printf("var -> ID more_var\n");}
		;
more_var:										{printf("var -> Empty var\n");}
	| L_BRAC expression R_BRAC							{printf("var -> L_BRAC expression R_BRAC\n");}
	;
var_comma:										{printf("var_comma -> Empty var_comma\n");}
	| COMMA var var_comma								{printf("var_comma -> COMMA var var_comma\n");}
	;



%%


int main(int argc, char** argv){
    FILE *fh;

    if(argc == 2 && (fh = fopen(argv[1], "r")))
        yyin = fh;
    else
		yyin = stdin;
  	yyparse();
		return 0;
}

void yyerror( const char* error_symbol) {
			printf("Error at line %d, column %d: unrecognized symbol \"%s\"\n", lineNum, colNum, error_symbol);
}
