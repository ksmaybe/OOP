#include "std_lib_facilities.h"
const char invalid = 'i';
const char name = 'a';
const char number = '8';
const char quit = 'q';
const char printl = ';';

class Token {
	char kind;
	double value;
	string name;
	Token(char ch) :kind{ ch } {}
	Token(char ch, double val) :kind{ ch }, value{ val } {}
	Token(char ch, string n) :kind{ ch }, name{ n } {}
};
class Token_stream {
	public:
		Token get();
		void putback(Token t);
		void ignore(char c);
	private:
		bool full{ false };
		Token buffer{invalid};


};

void Token_stream::putback(Token t) {
	buffer = t;
	full = true;
};
Token Token_stream::get() {
	if (full) {
		full = false;
		return buffer;
	}
	char ch;
	cin >> ch;
	switch (ch) {
	case ';':
	case 'q':
	case '(': case ')': case '+': case '-': case '/': case '*': case '%':
		return Token{ ch };
	case '.':
	case '0': case '1': case '2': case '3': case '4':
	case '5': case '6': case '7': case '8': case '9':
	{
		cin.putback(ch);
		double val;
		cin >> val;
		return Token{ '8', val };
	}
	default:
		return Token{ 'i', double(ch) };
	}
	return Token{ 'q' };
}


Token_stream ts;
double expression();

double primary() {};
double term() {};
double expression() {};



int main()
{
	Token;
	while (cin) {
		cin >> ;

	}
}