//forward declarations
class Program;
class Type;
//class SemanticType;
class ClassDecl;
class VarDecl;

// Level 0
struct Node {
	Node(): lineNo(yylineno), nextTok(yytext) {}
	virtual ~Node() {};
	string pos(){
		return 	"At symbol \"" + nextTok + "\" on line " + itoa(lineNo) + ",\n";
	}
	virtual void analyze() = 0;
	virtual void gen() = 0;
private:
	int lineNo;
	string nextTok;
}

// Level 1
class Type : public Node {
public: 
	string name;
	virtual 
}
