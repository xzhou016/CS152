%{
    #include<stdio.h>

%}

%%

%%

int main(int argc, char* argv){
    FILE *fh;

    if (argc == 2 && (fh = fopen(argv[1], "r")))
        yyin = fh;
    yylex();

}