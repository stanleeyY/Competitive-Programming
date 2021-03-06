#include <iostream>
#include <stack>
using namespace std;
int charcheck(char s)
{
	if (s>='0' && s<='9')
		return 1;
	else
		return 0;
}
class token
{
public:

	virtual int eval() {
		return 0;
	};

	virtual void printexp() {
    };
	virtual ~token() {

	}
};

class operator : public token
{
public:
    operator(){
    }
    virtual void printexp(int n1, char ch, int n2,int &flag) {
	}

};

class operand : public token
{
	int* op;
public:
	operand() {
		op = new int;
	}
	operand(int n)
	{
		op = new int;
		*op = n;
	}
	virtual int eval()
	{
		return *op;
	}

	virtual void printexp() {
		cout << " " << *op << " ";
	}
	~operand() {
		delete op;
		cout << "deleted" << endl;
	}
};

class binary : public operator
{
public:
    token* op1;
    token* op2;
};

class plus : public binary
{

public:

	plus() {
	}	

	plus(token* o1, token* o2)
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
	~plus() {
		delete op1;
		delete op2;
		cout << "deleted" << endl;
	}
	virtual void printexp() {
		cout << "(";
		op1->printexp();
		cout << "+";
		op2->printexp();
		cout << ") ";
    }
};

class minus : public binary
{

public:

    minus(){
    }

	minus(token* o1, token* o2)
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

	virtual void printexp() {
		cout << "(";
		op1->printexp();
		cout << "-";
		op2->printexp();
		cout << ") ";
    }
	~minus() {
		delete op1;
		delete op2;
		cout << "deleted" << endl;
	}
};

class multiply : public binary
{

public:

    multiply()  {
    }

	multiply(token* o1, token* o2)
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

	virtual void printexp() {
		cout << "(";
		op1->printexp();
		cout << "*";
		op2->printexp();
		cout << ") ";
    }
	~multiply() {
		delete op1;
		delete op2;
		cout << "deleted" << endl;
	}
};

class divide : public binary
{

public:

    divide() {
    }

	divide(token* o1, token* o2)
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

	virtual void printexp() {
		cout << "(";
		op1->printexp();
		cout << "/";
		op2->printexp();
		cout << ") ";
    }
	~divide() {
		delete op1;
		delete op2;
		cout << "deleted" << endl;
	}
};

int evaluate(char arr[],int &flag)
{
    stack<token*> s;
    int position=0;
    cout<<"\ninfix of given postfix expression is\n";

    while (arr[position] != '\0')
    {
        if (charcheck(arr[position]) == 1)
        {
            operand* op= new operand (arr[position]-'0');//passing integer value
            s.push(op);
        }
        else
        {
            switch (arr[position]) {

            case '+': {
				token* op1 = s.top();
                s.pop();
				token* op2 = s.top();
                s.pop();
                plus* plusexpr=new plus(op2,op1);
                s.push(plusexpr);
                break;
            }
            case '-': {
				token* op1 = s.top();
				s.pop();
				token* op2 = s.top();
				s.pop();
                minus* minusexpr=new minus(op2, op1);
				s.push(minusexpr);
                break;
            }
            case '*': {
				token* op1 = s.top();
				s.pop();
				token* op2 = s.top();
				s.pop();
                multiply* multiplyexpr=new multiply(op2, op1);
                s.push(multiplyexpr);
                break;
            }
            case '/': {
				token* op1 = s.top();
				s.pop();
				token* op2 = s.top();
				s.pop();
                divide* divideexpr=new divide(op2, op1);
                s.push(divideexpr);
                break;
            }
          }
        }
        position++;
    }
	s.top()->printexp();
	cout << endl;
    cout<<"evalulation of the postfix expression gives "<<s.top()->eval() << endl;
	delete s.top();
	s.pop();
    return 0;
}
int main() {
    char arr[50];
	cout << "enter postfix expressions\n";
	while (cin >> arr)
	{
		int flag = 0;
		evaluate(arr,flag);
	}
	return 0;
}