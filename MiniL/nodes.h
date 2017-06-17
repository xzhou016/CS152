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

//don't touch
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
	  return vartab.find(name);
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

//done
class BoolExpr    : public Node {
public:   
  BoolExpr( Expression* c1, int c2, Expression* c3 ) {
	 Node * temp_c1 = (Node*)c1;
	 Node * temp_c3 = (Node*)c3;
	 code += temp_c1->code;
	 code += temp_c3->code;

	 place = newTemp();
	 code += ". " + place + "\n";

	//comps can be find in tab.h
	 //print out c2
	 switch (c2)
	 {
	 case 287: code += "!= ";
		 break;
	 case 288: code += "== ";
		 break;
	 case 289: code += ">= ";
		 break;
	 case 290: code += "> ";
		 break;
	 case 291: code += "<= ";
		 break;
	 case 292: code += "< ";
	     break;
	 default: code += "unrecognized arithmetic symbol at " + itoa(c2);
		 break;
	 }
	 code += " " + place + ", " + temp_c1->place + ", " + temp_c3->place + "\n";
  }
  BoolExpr( BoolExpr* c1,   int c2, BoolExpr* c3 ) {
	  Node * temp_c1 = (Node*)c1;
	  Node * temp_c3 = (Node*)c3;

	  code += temp_c1->code;
	  code += temp_c3->code;

	  place = newTemp();
	  code += ". " + place + "\n";

	  switch (c2)
	  {
	  case 283: code += "|| ";
		  break;
	  case 284: code += "&& ";
		  break;
	  case 285: code += "! ";
		  break;
	  default: code += "unrecognized arithmetic symbol at " + itoa(c2);
		  break;
	  }
	  code += place + ", " + temp_c1->place + ", " + temp_c3->place + "\n";

  }
  BoolExpr( int c1, BoolExpr* c2 ) {
	  Node * temp_c2 = (Node*)c2;
	  place = newTemp();
	  code += ". " + place + "\n";
	  code += "! " + temp_c2->place + '\n';
  }
  BoolExpr( int c1 ) {
	  place = newTemp();
	  code += ". " + place + "\n";
	  code += "= " + place + ", " + itoa(c1) + "\n";
  }
  BoolExpr( int c1, BoolExpr* c2, int c3 ) {
	  Node * temp_c2 = (Node*)c2;
	  code += temp_c2->code;
  }
  BoolExpr( int c1, int c2, int c3 ) {
	  place = newTemp();
	  code += ". " + place + "\n";
	  code += "= " + place + ", " + itoa(c2) + "\n";
  }
};

//done
class Var : public Node {
public:
 string id;
  Var( string* c1 ) {

	id = *c1;
    // check symbol table for collision
    place  = newTemp();
	code += "= " + place + ", " + *c1 + "\n";

  }
  Var( string* c1, int c2, Expression* c3, int c4 ) {
	  Node * temp_c3 = (Node*)c3; //dealing with forward declaration
    //for arrary
	  id = *c1;
	  place = newTemp();
	  code += temp_c3->code; 
	  code += "=[] " + place +", " + *c1 + ", "+ temp_c3->place + "\n";
  }
};

//done
class Expression  : public Node {
public:   
  Expression( Var* c1 ) { 
    // check to see that it has been declared
	place = c1->place;    // Var
	code += ". " + place + "\n";
	code += c1->code;
  }
  Expression( int c1 ) {
	  place = newTemp();
	  code += ". " + place + "\n";
	  code += "= " + place + ", " + itoa(c1) + "\n";
  }   // NUMBER 
  Expression( int c1, Expression* c2, int c3 ) {
	  code += c2->code;
  } // '(" Expression ')'
  Expression( string* c1, int c2, Expressions* c3, int c4 ) { 
	  for (auto it : *c3){
		  code += it->code;
		  code += "param " + it->place + "\n";
	  }
	  place = newTemp();
	  code += ". " + place + "\n" ;
	  code += "call " + *c1 + ", " + place + "\n";
  } //parameter
  Expression( Expression* c1, int c2, Expression* c3 ) {
	 // string arth_symbol = c2;
	  place = newTemp();

	  code += c1->code + c3->code;
	  code += ". " + place + "\n";
	  switch (c2)
	  {
	  case 43: code += "+ ";
		  break;
	  case 45: code += "- ";
		  break;
	  case 42: code += "* ";
		  break;
	  case 47: code += "/ ";
		  break;
	  case 37: code += "% ";
		  break;
	  default: code += "unrecognized arithmetic symbol";
		  break;
	  }
	  code +=   place + ", " + c1->place + ", " + c3->place + "\n";
  }
  Expression( int c2, Expression* c3 ) {
	  place = newTemp();
	  code += ". " + place + "\n";
	  code += "- " + c3->place + "\n";
  }
};

//done
class Declaration : public Node {
public:
  int size;  // size of array; size == 0 for scalars.
  string id ;

  Declaration( list<string*>* c1, int c2, int c3 ) 
  { for( auto it : *c1 ) {
      // install *it into var table unless it causes a collision
      // var table contains both scalars and arrays.
      // should construct a Var and add it to the symbol table.
      vartab[*it] = new Var( it );
      
      code += ( ". " + *it + "\n" );
      id = *it;
    }
  }

  Declaration( list<string*>* c1, int c2, int c3, int c4, int c5, int c6,
	       int c7, int c8 )
  { for( auto it : *c1 ) {
      // install *it into var table unless it causes a collision
      // var table contains both scalars and arrays.
      // should construct a Var and add it to the symbol table.
      vartab[*it] = new Var( it );
      
      code += ( ".[] " + *it + ", " + itoa(c5)+ "\n" );
      id = *it;
    }
  }
};
//done
class Statement : public Node {
public:
  virtual ~Statement(){};
};

//done
class AssignmentStmt : public Statement {
public:   
  AssignmentStmt( Var* c1, int c2, Expression* c3 ) {
	  code += c1->code;
	  code += c3->code;
	  code += ("= " + c1->id + "," + c3->place + "\n");
  }
};

//done
class IfThenStmt : public Statement {
public:   
  IfThenStmt( int c1, BoolExpr* c2, int c3, Statements* c4, int c5 ) {
    before =  newLabel();
    after  =  newLabel();
	
	code += c2->code;
	code += "?:= " + before + ", " + c2->place + "\n";
    code += ":= " + after + "\n" ;
	code += ": " + before + "\n"; 
	//print statement
    for(auto it : *c4){
      code += it->code;
    }
    code += ": " + after + "\n";
    
  }

};

//done
class IfThenElseStmt : public Statement {
public:    
  IfThenElseStmt( int c1, BoolExpr* c2, int c3, Statements* c4, int c5,
		  Statements* c6, int c7 ) {
	  before = newLabel(); after = newLabel();

	  code += c2->code;
	  code += "?:= " + before + ", " + c2->place + "\n";
	  code += ":= " + after + "\n";
	  code += ": " + before + "\n";
	  //print statement
	  for (auto it : *c4) {
		  code += it->code;
	  }
	  for (auto it : *c6){
		  code += it->code;
	  }
	  code += ": " + after + "\n";
	}

};

//done
class WhileStmt : public Statement {
public:   
  WhileStmt( int c1, BoolExpr* c2, int c3, Statements* c4, int c5) {
	before = newLabel(); after = newLabel();
    code   += c2->code;
	//code += "Begin While loop \n";
	code += "?:= " + before + ", " + c2->place + "\n";
	code += ":= " + after + "\n";
	code += ": " + before + "\n";
    for(auto it : *c4){
      code += it->code;
    }
	before = newLabel();
	code += ":= " + before + "\n";
	code += ": " + after + "\n";
	//code += "Finished While loop \n";
  }
};

//done?
class DoWhileStmt : public Statement {
public:   
  DoWhileStmt( int c1, int c2, Statements* c3, int c4, int c5,
	       BoolExpr* c6 ){
	  before = newLabel(); after = newLabel();
	  //code += "Begin While loop \n";
	  code += "?:= " + before + ", " + c2->place + "\n";
	  code += ":= " + after + "\n";
	  code += ": " + before + "\n";
	  code += c6->code;
	  for (auto it : *c3) {
		  code += it->code;
	  }
	  before = newLabel();
	  code += ":= " + before + "\n";
	  code += ": " + after + "\n";
  }
};

//done
class ReadStmt : public Statement {
public:   
  ReadStmt( int c1, Vars* c2 ) {
    for (auto it : *c2){
      code += (".< " + it->id + "\n");
	  //code += ". " + it->place + "\n";
		
    }
  }

};

//done
class WriteStmt : public Statement {
public:   
  WriteStmt( int c1, Vars* c2 ) {
    for ( auto it : *c2 ) {
      code  += ( ".> " + it->id + "\n" );
    }
  }

};

//not done
class ContinueStmt : public Statement { // very hard check all 
public:
  ContinueStmt( int c1 ) {
	
  }

};

//done
class ReturnStmt : public Statement {
public:   
  ReturnStmt( int c1, Expression* c2 ) {
	  //place = newTemp();
	  code += c2->code;
	  code += "ret " + c2->place + "\n";
  }

};

//done
class Function    : public Node {
public:
  Function(int c1, string* c2, int c3, int c4, Declarations* c5, int c6,
      int c7, Declarations* c8, int c9, int c10, Statements* c11, int c12)
  {
    // add *c2 to function symbol table
    int param_counter = 0;
    ( code += "func ") += *c2 += "\n";
    for( auto it : *c5  ) {  
      // add each param to symbol table
		code += it->code;
		code += "= " + it->id + ", $" + itoa(param_counter++) + "\n";
    };   
    for( auto it : *c8  ) { 
      // add each local to symbol table
      code += it->code;
    };   
    for( auto it : *c11 ) { 
      // add each statement's code to this function's code
      code += it->code;
    };   
    code += "endfunc\n\n";
  }
};

//done
class Program     : public Node {    
public:
  Program(Functions *c1) 
  { 
    for( Function* it : *c1 ) { 
      code += it->code;  // May need to insert a newline here.
    } 
    // May need to do an analysis here.
    cout << code;
  }  
};



 

