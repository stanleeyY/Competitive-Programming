#include <iostream>
#include <stack>
using namespace std;
int charCheck(char s)
{
	if (s>='0' && s<='9')
		return 1;
	else
		return 0;
}
class Token
{
public:

	virtual int eval() {
		return 0;
	};

	virtual void printExp() {
    };
	virtual ~Token() {

	}
};

class Operator : public Token
{
public:
    Operator(){
    }
    virtual void printExp(int n1, char ch, int n2,int &flag) {
	}

};

class Operand : public Token
{
	int* op;
public:
	Operand() {
		op = new int;
	}
	Operand(int n)
	{
		op = new int;
		*op = n;
	}
	virtual int eval()
	{
		return *op;
	}

	virtual void printExp() {
		cout << " " << *op << " ";
	}
	~Operand() {
		delete op;
		cout << "deleted" << endl;
	}
};

class Binary : public Operator
{
public:
    Token* op1;
    Token* op2;
};

class Plus : public Binary
{

public:

	Plus() {
	}	

	Plus(Token* o1, Token* o2)
	{
		op1 = o1;
		op2 = o2;
	}

	virtual int eval()
	{
		int val1 = op1->eval();
		int val2 = op2->eval();
		return val1 + val2;
	}
	~Plus() {
		delete op1;
		delete op2;
		cout << "deleted" << endl;
	}
	virtual void printExp() {
		cout << "(";
		op1->printExp();
		cout << "+";
		op2->printExp();
		cout << ") ";
    }
};

class Minus : public Binary
{

public:

    Minus(){
    }

	Minus(Token* o1, Token* o2)
	{
		op1 = o1;
		op2 = o2;
	}

	virtual int eval()
	{
		int val1 = op1->eval();
		int val2 = op2->eval();
		return val1 - val2;
	}

	virtual void printExp() {
		cout << "(";
		op1->printExp();
		cout << "-";
		op2->printExp();
		cout << ") ";
    }
	~Minus() {
		delete op1;
		delete op2;
		cout << "deleted" << endl;
	}
};

class Multiply : public Binary
{

public:

    Multiply()  {
    }

	Multiply(Token* o1, Token* o2)
	{
		op1 = o1;
		op2 = o2;
	}

	virtual int eval()
	{
		int val1 = op1->eval();
		int val2 = op2->eval();
		return val1 * val2;
	}

	virtual void printExp() {
		cout << "(";
		op1->printExp();
		cout << "*";
		op2->printExp();
		cout << ") ";
    }
	~Multiply() {
		delete op1;
		delete op2;
		cout << "deleted" << endl;
	}
};

class Divide : public Binary
{

public:

    Divide() {
    }

	Divide(Token* o1, Token* o2)
	{
		op1 = o1;
		op2 = o2;
	}
	virtual int eval()
	{
		int val1 = op1->eval();
		int val2 = op2->eval();
		return val1 / val2;
	}

	virtual void printExp() {
		cout << "(";
		op1->printExp();
		cout << "/";
		op2->printExp();
		cout << ") ";
    }
	~Divide() {
		delete op1;
		delete op2;
		cout << "deleted" << endl;
	}
};

int Evaluate(char arr[],int &flag)
{
    stack<Token*> s;
    int position=0;
    cout<<"\nInfix of given postfix expression is\n";

    while (arr[position] != '\0')
    {
        if (charCheck(arr[position]) == 1)
        {
            Operand* op= new Operand (arr[position]-'0');//passing integer value
            s.push(op);
        }
        else
        {
            switch (arr[position]) {

            case '+': {
				Token* op1 = s.top();
                s.pop();
				Token* op2 = s.top();
                s.pop();
                Plus* plusexpr=new Plus(op2,op1);
                s.push(plusexpr);
                break;
            }
            case '-': {
				Token* op1 = s.top();
				s.pop();
				Token* op2 = s.top();
				s.pop();
                Minus* minusexpr=new Minus(op2, op1);
				s.push(minusexpr);
                break;
            }
            case '*': {
				Token* op1 = s.top();
				s.pop();
				Token* op2 = s.top();
				s.pop();
                Multiply* multiplyexpr=new Multiply(op2, op1);
                s.push(multiplyexpr);
                break;
            }
            case '/': {
				Token* op1 = s.top();
				s.pop();
				Token* op2 = s.top();
				s.pop();
                Divide* divideexpr=new Divide(op2, op1);
                s.push(divideexpr);
                break;
            }
          }
        }
        position++;
    }
	s.top()->printExp();
	cout << endl;
    cout<<"Evalulation of the postfix expression gives "<<s.top()->eval() << endl;
	delete s.top();
	s.pop();
    return 0;
}
int main() {
    char arr[50];
	cout << "Enter postfix expressions\n";
	while (cin >> arr)
	{
		int flag = 0;
		Evaluate(arr,flag);
	}
	return 0;
}