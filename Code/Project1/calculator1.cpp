/*#include "std_lib_facilities.h"

class Token
{
public:
	char kind;
	double value;

};
class Token_stream
{
public:
	Token get();
	void putback(Token t);
private:
	bool full{ false };
	Token buffer;
};

void Token_stream::putback(Token t)
{
	if (full) error("putback() into a full buffer:");
	buffer = t;
	full = true;
}
Token Token_stream::get()
{
	if (full)
	{
		full = false;
		return buffer;
	}
	char ch;
	cin >> ch;
	switch (ch)
	{
	case ';': case'q': case'%':
	case '(': case ')': case'+': case '-': case'*': case'/':
		return Token{ ch };

	case'.': case'0': case'1': case'2': case'3': case'4': case'5':
	case'6': case'7': case'8': case'9':
	{
		cin.putback(ch);
		double val;
		cin >> val;
		return Token{ '8',val };

	}
	default:
		double d1 = ch;
		return Token{ 'i',d1 };
	}
}

Token_stream ts;

double expression();
double primary() {
	Token t = ts.get();
	switch (t.kind) {
	case'(':
	{
		double d = expression();
		t = ts.get();
		if (t.kind != ')') error("')' expected");
		return d;
	}
	case '8':
		return t.value;
	default:
		error("primary expected");
	}
}
double term()
{
	double left = primary();
	Token t = ts.get();
	while (true)
	{
		switch (t.kind)
		{
		case'*':
			left *= primary();
			t = ts.get();
			break;
		case'/':
		{	double d = primary();
			if (d == 0)
				error("division by zero");
			left /= d;
			t = ts.get();
		break; }
		case'%':
			{
			double d = primary();
			while (left >= d)
				left -= d;
			t = ts.get();
			break;
			}
		default:
			ts.putback(t);
			return left;
		}
	}
}
double expression()
{
	double left = term();
	Token t = ts.get();
	while (true) {
		switch (t.kind)
		{
		case'+':
			left+=term();
			t = ts.get();
			break;
		case'-':
			left -= term();
			t = ts.get();
			break;
		default:
			ts.putback(t);
			return left;
		}
	}
}





int main()
{
	double val = 0;
	cout << ">";
	while(cin)
	{
		Token t = ts.get();
		if (t.kind == 'q') break;
		if (t.kind == ';')
		{
			cout << '=' << val << endl;
			cout << '>';
		}
		else
			ts.putback(t);
		val = expression();
	}
	keep_window_open();
	return 0;
}