%{
	#include<stdio.h>
	#include<string.h>
	#include "y.tab.h"
%}

DIGIT 		[0-9]
LETTER 		[a-zA-Z]
UNDERLINE	[_]
WHITE_SPACE	[ \t]+

%%
\(	return L_PARENT;
\)	return R_PARENT;
\[	return L_BRAC;
\]	return R_BRAC;


%%

int main(int argc, char* argv){
    FILE *fh;

    if(argc == 2 && (fh = fopen(argv[1], "r")))
        yyin = fh;
    yylex();

}
