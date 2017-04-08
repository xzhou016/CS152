%{
#include <stdio.h>
int 	 count_num = 0
    	,count_op = 0
	,count_para = 0
	,count_eq = 0;
%}



%%

[0-9].[0-9]+	{printf("NUMBER %f\n", yytext); ++count_num;}
\+		printf("PLUS\n"); ++count_op;
\-		printf("MINUS\n"); ++count_op;
\*		printf("MULT\n"); ++count_op;
\/		printf("DIV\n"); ++count_op;
\(		printf("L_PAREN\n"); ++count_para;
\)		printf("R_PAREN\n"); ++count_para;
\=		printf("EQUAL\n"); ++count_eq;
\n              /* ignore EOL */;
[ \t]+          /* ignore whitespace */;


%%

int main(int argc, char* argv) {
    FILE *fh;

    if (argc == 2 && (fh = fopen(argv[1], "r")))
        yyin = fh;
    yylex();

   	printf("Number count: %d ", count_num);
	printf("Operator count: %d ", count_op);
	printf("Parentheses count: %d ", count_para);
	printf("Equal count: %d\n", count_eq);
    return 0;
}

int yywrap()
{
return(1);
}
