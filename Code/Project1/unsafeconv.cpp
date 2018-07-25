#include "std_lib_facilities.h"

int main()
{
	double d = 20.123445356345356;
	cout << "double: " << d << endl;
	int d1 = d;
	cout << "double to int: " << d1 << endl;
	double d1a = d1;
	cout << "int back to double: " << d1a <<endl;
	char d2 = d;
	cout << "double to char: " << d2 << endl;
	double d2a = d2;
	cout << "char back to double: " << d2a << endl;
	bool d3 = d;
	cout << "double to bool: " << d3 << endl;
	double d3a = d3;
	cout << "bool back to double: " << d3a << endl;
	int i = 20;
	cout << "int: " << i << endl;
	char i1 = i;
	cout << "int to char: " << i1 << endl;
	int i1a = i1;
	cout << "char back to int: " << i1a << endl;
	bool i2 = i;
	cout << "int to bool: " << i2 << endl;
	int i2a = i2;
	cout << "bool back to int: " << i2a << endl;
	char c = 'x';
	cout << "char: " << c << endl;
	bool c1 = c;
	cout << "char to bool: " << c1 << endl;
	char c1a = c1;
	cout << "bool back to char: " << c1a << endl;
	keep_window_open();
}