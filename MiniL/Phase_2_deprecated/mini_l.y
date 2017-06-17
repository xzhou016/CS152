%{
	#include "heading.h"
	void yyerror(const char * error_symbol);
	extern int lineNum;
	extern int colNum;
	FILE *yyin;
%}

%union{

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
}
%error-verbose
%start Program

//           member       non-termimnal
%type       <program>       Program
%type       <declarations>  Declarations
%type       <declaration>   Declaration
%type       <statements>    Statements
%type       <statement>     Statement
%type       <functions>     Functions
%type       <function>      Function
%type       <ids>           IDs
%type       <vars>          Vars
%type       <var>           Var
%type       <expressions>   Expressions
%type       <expression>    Expression
%type       <nonemptyexpressionlist> NonemptyExpressionList
%type       <boolexpr>      BoolExpr

// assoc      member        token
%nonassoc   <junk>          LO
%nonassoc   <junk>          INTEGER
%nonassoc   <junk>          ARRAY
%nonassoc   <junk>          FUNCTION
%nonassoc   <junk>          BEGIN_PARAMS
%nonassoc   <junk>          END_PARAMS
%nonassoc   <junk>          BEGIN_LOCALS
%nonassoc   <junk>          END_LOCALS
%nonassoc   <junk>          BEGIN_BODY
%nonassoc   <junk>          END_BODY
%nonassoc   <junk>          BEGINLOOP
%nonassoc   <junk>          ENDLOOP
%token      <junk>          IF
%token      <junk>          THEN
%token      <junk>          ELSE
%token      <junk>          ENDIF
%token      <junk>          DO
%token      <junk>          WHILE
%token      <junk>          READ
%token      <junk>          WRITE
%token      <junk>          CONTINUE
%token      <junk>          RETURN
%token      <junk>          TRUE
%token      <junk>          FALSE
%right      <junk>          ASSIGN   /* ":=" */
%token      <junk>          OF
%left       <junk>          OR
%left       <junk>          AND
%right      <junk>          NOT
%left       <junk>          NE
%left       <junk>          EQ
%left       <junk>          GE
%left       <junk>          GT
%left       <junk>          LE
%left       <junk>          LT
%left       <junk>          SUB    /* binary */
%left       <junk>          ADD
%left       <junk>          MOD
%left       <junk>          DIV
%left       <junk>          TIMES
%right      <junk>          UMINUS
%left       <junk>          L_BRAC
%left       <junk>          R_BRAC
%left       <junk>          L_PARENT
%left       <junk>          R_PARENT
%right      <junk>          COMMA
%right      <junk>          SEMICOLON
%nonassoc   <junk>          COLON
%nonassoc   <junk>          HI
%token      <ident>         ID
%token      <int_val>       NUMBER


%%
Program      : /* empty */
	     | Functions
	     ;
Functions    : /* empty */                         {printf("Function -> Empty Function\n");}
             | Functions Function                  {printf("Function -> Functions Function\n");}
             ;
Declarations : /* empty */                         {printf("Declaration -> Empty declaration\n");}
             | Declarations Declaration            {printf("Declaration -> Declarations Declaration\n");}
             ;
Statements   : /* empty */                         {printf("Statement -> Empty statement\n");}
             | Statement SEMICOLON                 {printf("Statement -> Statement SEMICOLON\n");}
             | Statements Statement SEMICOLON      {printf("Statement -> Statements Statement SEMICOLON\n");}
             ;
IDs          : /* empty */                         {printf("ID -> Empty ID\n");}
             | IDs SEMICOLON ID                    {printf("ID -> IDs SEMICOLON ID\n");}
             ;
Vars         : Var                     {printf("Var -> Var\n");}
             | Vars SEMICOLON Var      {printf("Var -> Vars SEMICOLON Var\n");}
             ;                   /* any nonempty comma-separated list of Vars */
Expressions  : /* empty */                       {printf("Expression -> Empty Expression\n");}
             | NonemptyExpressionList            {printf("Expression -> NonemptyExpressionList\n");}
             ;      /* any possibly empty comma-separated list of Expressions */
NonemptyExpressionList
             : Expression                              {printf("Expression -> Expression\n");}
             | NonemptyExpressionList COMMA Expression {printf("Expression -> NonemptyExpressionList COMMA Expression\n");}
             ;            /* any nonempty comma-separated list of Expressions */


Function     : FUNCTION ID SEMICOLON 
	       BEGIN_PARAMS Declarations END_PARAMS 
	       BEGIN_LOCALS Declarations END_LOCALS 
	       BEGIN_BODY Statements END_BODY 
	       {printf("Function -> BEGIN_PARAMS Declarations END_PARAMS BEGIN_LOCALS Declarations END_LOCALS BEGIN_BODY Statements END_BODY \n");}
	     ;

Declaration  : IDs COLON                                        {printf("declaration -> IDs COLON\n");}
             | IDs COLON ARRAY L_BRAC NUMBER R_BRAC OF INTEGER {printf("declaration -> IDs COLON ARRAY L_BRAC NUMBER R_BRAC OF INTERGER\n");}
	     ;
Statement    : Var ASSIGN Expression                                   {printf("Statement -> Var ASSIGN Expression\n");}
             | IF BoolExpr THEN Statements ENDIF                       {printf("Statement -> IF BoolExpr THEN Statements ENDIF\n");}
             | IF BoolExpr THEN Statements ENDIF ELSE Statements ENDIF {printf("Statement -> IF BoolExpr THEN Statements ENDIF ELSE Statements ENDIF\n");}
             | WHILE BoolExpr BEGINLOOP Statements ENDLOOP             {printf("Statement -> WHILE BoolExpr BEGINLOOP Statements ENDLOOP\n");}
             | DO BEGINLOOP Statements ENDLOOP WHILE BoolExpr          {printf("Statement -> DO BEGINLOOP Statements ENDLOOP WHILE BoolExpr\n");}
             | READ Vars                                               {printf("Statement -> READ Vars\n");}
             | CONTINUE                                                {printf("Statement -> CONTINUE\n");}
             | RETURN Expression                                       {printf("Statement -> RETURN Expression\n");}
             | WRITE Vars                                              {printf("Statement -> WRITE Vars\n");}
             ;

BoolExpr    : Expression EQ Expression          {printf("BoolExpr -> Expression EQ Expression\n");}
             | Expression NE Expression         {printf("BoolExpr -> Expression NE Expression\n");}
             | Expression LT Expression         {printf("BoolExpr -> Expression LT Expression\n");}
             | Expression GT Expression         {printf("BoolExpr -> Expression GT Expression\n");}
             | Expression LE Expression         {printf("BoolExpr -> Expression LE Expression\n");}
             | Expression GE Expression         {printf("BoolExpr -> Expression GE Expression\n");}
	     | BoolExpr AND BoolExpr            {printf("BoolExpr -> BoolExpr AND BoolExpr\n");}
	     | BoolExpr OR BoolExpr             {printf("BoolExpr -> BoolExpr OR BoolExpr\n");}
             | NOT BoolExpr                     {printf("BoolExpr -> NOT BoolExpr\n");}
             | TRUE                             {printf("BoolExpr -> TRUE\n");}
             | FALSE                            {printf("BoolExpr -> FALSE\n");}
             | L_PARENT BoolExpr R_PARENT       {printf("BoolExpr -> L_PARENT BoolExpr R_PARENT\n");}
	     ;
Expression   : Var                              {printf("Expression -> Var\n");}
	     | NUMBER                           {printf("Expression -> NUMBER\n");}
             | L_PARENT Expression R_PARENT     {printf("Expression -> L_PARENT Expression R_PARENT\n");}
             | ID L_PARENT Expressions R_PARENT {printf("Expression -> ID L_PARENT Expressions R_PARENT\n");}
             | Expression ADD Expression        {printf("Expression -> Expression ADD Expression\n");}
             | Expression SUB Expression        {printf("Expression -> Expression SUB Expression\n");}
             | Expression TIMES Expression      {printf("Expression -> Expression TIMES Expression\n");}
             | Expression DIV Expression        {printf("Expression -> Expression DIV Expression\n");}
             | Expression MOD Expression        {printf("Expression -> Expression MOD Expression\n");}
             | SUB Expression  %prec UMINUS     {printf("Expression -> SUB Expression\n");}
             ;
Var	     : ID                               {printf("Var -> ID\n");}
             | ID L_BRAC Expression R_BRAC      {printf("Var -> ID L_BRAC Expression R_BRAC\n");}
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
