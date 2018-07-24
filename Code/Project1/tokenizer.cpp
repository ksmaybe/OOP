#include "std_lib_facilities.h"
class Token
{
public:
	char kind;
	double value;
};
vector<Token> tok;
Token get_token()
{
	Token token;
	double d;
	cin >> d;
	if (!cin) {
		cout << "We received an invalid token of value " << endl;
	}
	else {
		cout << "A number of token with val = " << d << endl;
		token.value = d;
	}

	char t;
	cin >> t;
	switch(t)
	{
	case '+':
	case '-':
	case '*':
	case '/':
	case '(':
	case ')':
	case 'q':
		{
		token.kind = t;
		return token;
		}
	default:
		error("We received an invalid token kind ", t);
		return token;
	}
}



int main()
{	
	cout << "Please enter an expression: \n";
	double res = 0;
	for(Token t=get_token(); t.kind!='q'; t=get_token())
	{	
		tok.push_back(t);

	}
	cout << "Hello" << endl;
	res += tok[0].value;
	for (Token t: tok)
		cout << t.value <<t.kind <<endl;
	
	for(int i=0;i<=tok.size();++i)
	{
		cout << tok[i].kind <<endl;
		cout << tok[i].value << endl;
		cout << tok[i+1].kind << endl;
		cout << tok[i+1].value << endl;
		if (tok[i].kind == '+')
			res += tok[i + 1].value;
		else if (tok[i].kind == '-')
			res -= tok[i + 1].value;		
		else if (tok[i].kind == '*')
			res *= tok[i + 1].value;		
		else if (tok[i].kind == '/')
			res /= tok[i + 1].value;
		cout << endl;
	}
	cout << "The result is: " << res << endl;
	keep_window_open();
	return 0;
}
