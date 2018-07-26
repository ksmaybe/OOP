#include "std_lib_facilities.h"
#include "date.h"


int main()
{
	int xx;
	int yy;
	int zz;
	string input;
	cout << "Enter a date in format (YYYY,MM,DD): ";
	cin >> input;
	istringstream ss(input);
	string token_y;
	string token_m;
	string token_d;
	getline(ss, token_y, ',');
	stringstream y(token_y);
	y >> xx;
	getline(ss, token_m, ',');
	stringstream m(token_m);
	m >> yy;
	getline(ss, token_d, ',');
	stringstream d(token_d);
	d >> zz;
	f(xx, yy, zz);
	keep_window_open();
	return 0;
}