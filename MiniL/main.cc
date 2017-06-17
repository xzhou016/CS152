// -*- c++ -*- 
// main.cc


#include "heading.H"
#include "nodes.h"

map<string, Var*> vartab;
string compilerName; // initialized by main() for use in error messages

int yyparse();          // prototype of bison-generated parser function

int main( int argc, char* argv[] ) {  
  // yydebug = 1;          // uncomment to enable parser debugging
  // Allow for command-line specification of MiniJava source file
  if ( argc > 1  &&  freopen( argv[1], "r", stdin) == NULL ) {
    cerr << argv[0] << ": file " << argv[1]; 
    cerr << " cannot be opened.\n";
    exit( 1 ); 
  }
  compilerName = argv[0];           // For use in error messages
  yyparse();                                // build syntax tree
}






