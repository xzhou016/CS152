%{
#include <stdio.h>
%}

%%

[0-9]+		printf("NUMBER %s", yytext);
\+		printf("PLUS");
\-		printf("MINUS");
\*		printf("MULT");
\/		printf("DIV");
\(		printf("L_PAREN");
\)		printf("R_PAREN");
\=		printf("EQUAL");
\n                      /* ignore EOL */;
[ \t]+                  /* ignore whitespace */;
%%
