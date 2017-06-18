%{
#include <stdio.h>
#include "y.tab.h"
int 	 count_num = 0
    	,count_op = 0
	,count_para = 0
	,count_eq = 0;
%}



%%

[0-9]+		{yylval = atoi(yytext); return NUMBER; ++count_num;}
\+		return PLUS; ++count_op;
\-		return MINUS; ++count_op;
\*		return MULT; ++count_op;
\/		return DIV; ++count_op;
\(		return L_PAREN; ++count_para;
\)		return R_PAREN; ++count_para;
\=		return EQUAL; ++count_eq;
\n              return NEWLINE;/* ignore EOL */;
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
