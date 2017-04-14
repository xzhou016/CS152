%{
	#include<stdio.h>
	#include<string.h>
	#include "y.tab.h"
%}

DIGIT 		[0-9]
LETTER 		[a-zA-Z]
UNDERLINE	[_]
WHITE_SPACE	[ \t]+
NUMBER {DIGIT}+
COMMENT ##.*
ID {LETTER}(({LETTER}|{NUMBER}|UNDERLINE)*({LETTER}|{NUMBER}))?
BAD_ID {NUMBER}|({ID}{UNDERLINE})+{ID}

%%
\(		printf("L_PARENT\n");
\)		printf("R_PARENT\n");
\[		printf("L_BRAC\n");
\]		printf("R_BRAC\n");
\-		printf("U_SUB\n");

\*		printf("TIMES\n");
\/		printf("DIV\n");
%			printf("MOD\n");
\+		printf("ADD\n");
-			printf("SUB\n");

\<		printf("LT\n");
\<=		printf("LTE\n");
\>		printf("GT\n");
\>=		printf("GTE\n");
\==		printf("EQ\n");
\<\>	printf("NEQ\n");

not		printf("NOT\n");
and		printf("AND\n");
or		printf("OR\n");
\:=		printf("ASSIGN\n");


function			printf("FUNCTION\n");
beginparams		printf("BEGIN_PARAMS\n");
endparams			printf("END_PARAMS\n");
beginlocals		printf("BEGIN_LOCALS\n");
endlocals			printf("END_LOCALS\n");
beginboday		printf("BEGIN_BODY\n");
endbody				printf("END_BODY\n");
interger			printf("INTERGER\n");
array					printf("ARRAY\n");
of						printf("OF\n");
if						printf("IF\n");
then					printf("THEN\n");
endif					printf("ENDIF\n");
else					printf("ELSE\n");
while					printf("WHILE\n");
do						printf("DO\n");
beginloop			printf("BEGINLOOP\n");
endloop				printf("ENDLOOP\n");
continue			printf("CONTINUE\n");
read					printf("READ\n");
write					printf("WRITE\n");
%%

int main(int argc, char* argv){
    FILE *fh;

    if(argc == 2 && (fh = fopen(argv[1], "r")))
        yyin = fh;
    yylex();

}
