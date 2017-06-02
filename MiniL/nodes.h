// -*- c++ -*-
// nodes.h

// #include "heading.H"  // for tesing only.  Else comment this out

// Definitions of node classes, i.e., translation records.
// A work in progress


// External global variables
extern ostringstream code;                            // Where target code goes
extern ostringstream init;             // Where target initialization code goes
extern ostringstream decs;                      // Where target declarations go
extern int yylineno;                           // defined & maintained in lex.c
extern char* yytext;                           // defined & maintained in lex.c
extern string compilerName;               // initialized from argv[0] in main()
class Var;
extern map<string, Var*> vartab;

// Obsolete stuff:
// extern SemanticType* theIntType;    // global entity for MiniJava's Int type
// extern SemanticType* theIntArrayType;       // ... for MiniJava's Int[] type
// extern SemanticType* theBooleanType;      // ... for MiniJava's Boolean type
// extern SemanticType* theVoidPtrType;        
// extern SemanticType* theWordPtrType;        
// extern Program* root;                      // pointer to root of syntax tree


class BoolExpr;

class Function;
typedef list<Function*>     Functions;

class Declaration;
typedef list<Declaration*>  Declarations; 

class Statement;
typedef list<Statement*>    Statements;

class Var;
typedef list<Var*>          Vars;

class Expression;
typedef list<Expression*>   Expressions;

struct Node {
public:
  Node() : lineNo(yylineno), nextTok(yytext) {}
  virtual ~Node() {};

  string code, place, before, after;  // attributes for node classes here.

  string pos() {      // for reporting errors, which we do only from nodes
    return "At symbol \"" + nextTok + "\" on line " + itoa(lineNo) +",\n";
  }  

// These should create a name and install it into the appropriate table.
// It's attributes can be filled in later.

  bool newVar( string name ) {
    // install into symbol table and report collisions
  }

  bool newArry()  {
    // install into symbol table and report collisions
  }

  bool newParam() {
    // install into symbol table and report collisions
  }

  bool newFunct() {
    // install into symbol table and report collisions
  }

  string newTemp()  {
    static int counter = 0;
    return "Temp" + itoa(counter++);
  }

  string newLabel() {
    static int counter = 0;
    return "Label" + itoa(counter++);
  }

private:
  int lineNo;             // lineNo at Node's construction is used in pos()
  string nextTok;        // nextTok at Node's construction is used in pos()
};  


class BoolExpr    : public Node {
public:   
  BoolExpr( Expression* c1, int c2, Expression* c3 ) {}
  BoolExpr( BoolExpr* c1,   int c2, BoolExpr* c3 ) {}
  BoolExpr( int c1, BoolExpr* c2 ) {}
  BoolExpr( int c1 ) {}
  BoolExpr( int c1, BoolExpr* c2, int c3 ) {}
  BoolExpr( int c1, int c2, int c3 ) {}
};

class Var         : public Node {
public:
  Var( string* c1 ) {
    // check symbol table for collision
    place = *c1;
  }
  Var( string* c1, int c2, Expression* c3, int c4 ) {} 
};

class Expression  : public Node {
public:   
  Expression( Var* c1 ) { 
    // check to see that it has been declared
    place = c1->place;    // Var
  }
  Expression( int c1 ) {}   // NUMBER 
  Expression( int c1, Expression* c2, int c3 ) {} // '(" Expression ')'
  Expression( string* c1, int c2, Expressions* c3, int c4 ) {} 
  Expression( Expression* c1, int c2, Expression* c3 ) {}
  Expression( int c2, Expression* c3 ) {}
};

class Declaration : public Node {
public:
  int size;  // size of array; size == 0 for scalars.
  Declaration( list<string*>* c1, int c2, int c3 ) 
  { for( auto it : *c1 ) {
      // install *it into var table unless it causes a collision
      // var table contains both scalars and arrays.
      // should construct a Var and add it to the symbol table.
      vartab[*it] = new Var( it );
      code += ( ". " + *it + "\n" );
    }
  }

  Declaration( list<string*>* c1, int c2, int c3, int c4, int c5, int c6,
	       int c7, int c8 )
  { }

};

class Statement : public Node {
public:
  virtual ~Statement(){};
};

class AssignmentStmt : public Statement {
public:   
  AssignmentStmt( Var* c1, int c2, Expression* c3 ) {
    code += ( "= " + c1->place + "," + c3->place + "\n" );  
  }
};

class IfThenStmt : public Statement {
public:   
public:   
  IfThenStmt( int c1, BoolExpr* c2, int c3, Statements* c4, int c5 ) {}
};

class IfThenElseStmt : public Statement {
public:    
  IfThenElseStmt( int c1, BoolExpr* c2, int c3, Statements* c4, int c5,
		  Statements* c6, int c7 ) {}
};

class WhileStmt : public Statement {
public:   
  WhileStmt( int c1, BoolExpr* c2, int c3, Statements* c4, int c5) {}
};

class DoWhileStmt : public Statement {
public:   
  DoWhileStmt( int c1, int c2, Statements* c3, int c4, int c5,
	       BoolExpr* c6 ){}
};

class ReadStmt : public Statement {
public:   
  ReadStmt( int c1, Vars* c2 ) {}
};

class WriteStmt : public Statement {
public:   
  WriteStmt( int c1, Vars* c2 ) {
    for ( auto it : *c2 ) {
      code  += ( ".> " + it->place + "\n" );
    }
  }
};

class ContinueStmt : public Statement {
public:
  ContinueStmt( int c1 ) {}
};

class ReturnStmt : public Statement {
public:   
  ReturnStmt( int c1, Expression* c2 ) {}
};

class Function    : public Node {
public:
  Function(int c1, string* c2, int c3, int c4, Declarations* c5, int c6,
      int c7, Declarations* c8, int c9, int c10, Statements* c11, int c12)
  {
    // add *c2 to function symbol table
    
    ( code += "func ") += *c2 += "\n";
    for( auto it : *c5  ) {  
      // add each param to symbol table
    };   
    for( auto it : *c8  ) { 
      // add each local to symbol table
      code += it->code;
    };   
    for( auto it : *c11 ) { 
      // add each statement's code to this function's code
      code += it->code;
    };   
    code += "endfunc\n";
  }
};


class Program     : public Node {    
public:
  Program(Functions *c1) 
  { for( Function* it : *c1 ) { 
      code += it->code;  // May need to insert a newline here.
    } 
    // May need to do an analysis here.
    cout << code;
  }  
};



 


