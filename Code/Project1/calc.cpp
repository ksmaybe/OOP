#include "calc.h"

Token_stream ts;
vector<Variable> var_table;
vector<string> history;


double get_value(string s)
{
	for (Variable var : var_table)
		if (var.name == s)
			return var.value;
	return 0.0;

}
void set_value(string s, double d)
{
	for (Variable& var : var_table)
		if (var.name == s)
		{
			var.value = d;
			return;
		}
	var_table.push_back(Variable{ s,d });
}

void print_vars()
{
	for (Variable var : var_table)
		cout << "Var " << var.name << "=" << var.value << endl;
}

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
	case ';': case'q': case'=': case'%': case'p': case'^':
	case '(': case ')': case'+': case '-': case'*': case'/':
		return Token{ ch };
	case 'i':
		return Token{ complex ,'i'};

	case'.': case'0': case'1': case'2': case'3': case'4': case'5':
	case'6': case'7': case'8': case'9':
	{
		cin.putback(ch);
		double val;
		cin >> val;
		return Token{ '8',val };

	}
	default:
		if (isalpha(ch))
		{
			string s;
			s += ch;
			while (cin.get(ch) && isalpha(ch)) s += ch;
			cin.putback(ch);
			return Token{ name, s };
		}
		return Token{ invalid,double(ch) };

	}
	return Token{ quit };
}



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
	case name:
	{
		string s = t.name;
		Token t = ts.get();
		if (t.kind == '=')
		{
			double d = expression();
			set_value(s, d);
			return d;
		}
		ts.putback(t);
		return get_value(s);
	}
	case 'p':
		print_vars();
		break;
	case number:
		return t.value;
	case '-':
		t = ts.get();
		if (t.kind = number)
			return (t.value*-1);
		error("primary expected");
	}
	return 0;
}
double expon()
{
	double left = primary();
	Token t = ts.get();
	while (true)
	{
		switch (t.kind)
		{
		case'^':
		{left = pow(left, primary());
		t = ts.get();
		break; }
		default:
			ts.putback(t);
			return left;
		}
	}
}
double term()
{
	double left = expon();
	Token t = ts.get();
	while (true)
	{
		switch (t.kind)
		{
		case'*':
			left *= expon();
			t = ts.get();
			break;
		case'/':
		{	double d = expon();
		if (d == 0)
			error("division by zero");
		left /= d;
		t = ts.get();
		break; }
		case'%':
		{
			double d = expon();
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
			left += term();
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