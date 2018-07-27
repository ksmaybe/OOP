#include "std_lib_facilities.h"
int main() {
	cout << 1234.56789 << '\t' << fixed << 1234.56789 << '\t' << scientific << 1234.56789 << endl;
	cout << defaultfloat << setprecision(5) << 1234.56789 << '\t' << fixed << 1234.56789 << '\t' << scientific << 1234.56789 << endl;
	cout << defaultfloat << setprecision(8) << 1234.56789 << '\t' << fixed << 1234.56789 << '\t' << scientific << 1234.56789 << endl;
}