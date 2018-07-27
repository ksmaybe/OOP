
#include "std_lib_facilities.h"
#include "date.h"

Date f();
ostream& operator <<(ostream& os, Date d);

int main()
{
	
	Date today= f();
	cout << "Today is: " << today << endl;
	int n;
	cout << "Number of days to add: ";
	cin >> n;
	today.add_day(n);
	cout << today << endl;
	keep_window_open();
	return 0;
}