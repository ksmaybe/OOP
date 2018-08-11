#include "calc3.h"

Token_stream ts;
vector<Variable> var_table;
vector<string> history;


Complex get_value(string s)
{
	for (Variable var : var_table)
		if (var.name == s)
			return var.value;
	Complex comp;
	return comp;

}
void set_value(string s, Complex d)
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
	{
		Complex comp;
		comp.setComplex(0,1);
		return Token{ complex ,comp };
	}
	case'.': case'0': case'1': case'2': case'3': case'4': case'5':
	case'6': case'7': case'8': case'9':
	{
		cin.putback(ch);
		double val;
		cin >> val;
		Complex comp;
		char k = cin.get();
		if (k == 'i') comp.setComplex(0, val);
		else
		{
			cin.putback(k);
			comp.setComplex(val, 0);
		}
		return Token{ complex,comp};

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
		return Token{ invalid };

	}
	return Token{ quit };
}



Complex expression();
Complex primary() {
	Token t = ts.get();
	switch (t.kind) {
	case'(':
	{
		Complex d = expression();
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
			Complex d = expression();
			set_value(s, d);
			return d;
		}
		ts.putback(t);
		return get_value(s);
	}
	case 'p':
		print_vars();
		break;
	case complex:
		return t.value;
	case '-':
		t = ts.get();
		if (t.kind = number)
			return (t.value*-1);
		error("primary expected");
	}
	return 0;
}
Complex expon()
{
	Complex left = primary();
	Token t = ts.get();
	while (true)
	{
		switch (t.kind)
		{
		case'^':
		{
			Complex d;
			d.setComplex(1, 0);
			double n = primary().getreal();
			for (int i = 0; i < n; ++i)
			{
				d = d * left;
			}
			left = d;
			t = ts.get();
			break; }
		default:
			ts.putback(t);
			return left;
		}
	}
}
Complex term()
{
	Complex left = expon();
	Token t = ts.get();
	while (true)
	{
		switch (t.kind)
		{
		case'*':
			left =left* expon();
			t = ts.get();
			break;
		case'/':
		{	Complex d = expon();
		if (d.getreal() == 0)
			error("division by zero");
		left =left/ d;
		t = ts.get();
		break; }
		case'%':
		{
			Complex d = expon();
			while (left.getreal() >= d.getreal())
				left =left- d;
			t = ts.get();
			break;
		}
		default:
			ts.putback(t);
			return left;
		}
	}
}
Complex expression()
{
	Complex left = term();
	Token t = ts.get();
	while (true) {
		switch (t.kind)
		{
		case'+':
			left =left+ term();
			t = ts.get();
			break;
		case'-':
			left =left- term();
			t = ts.get();
			break;
		default:
			ts.putback(t);
			return left;
		}
	}
}