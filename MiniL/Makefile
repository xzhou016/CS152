
all: 	
	bison -v -d --file-prefix=bison  mini_l.y 
	flex mini_l.lex
	gcc -o mini_l bison.tab.c lex.yy.c -lfl 


clean:
	rm -f *.o bison.* lex.yy.c mini_l
