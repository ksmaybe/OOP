#include "std_lib_facilities.h"
#include <iso646.h>

class Date
{
public:
	Date(int y, int m, int d);
	void add_day(int n);
	int year();
	int month();
	int day();
private:
	int date_test(Date);
	int y, m, d;
	bool isvalid();
};
enum class Month
{
	jan=1,feb=2,mar=3,apr=4,may=5,jun=6,jul=7,aug=8,sep=9,oct=10,nov=11,dec=12
};
Date::Date(int yy, int mm,int dd)
{
	y = yy;
	m = mm;
	d = dd;
	if (!isvalid())
		throw Invalid{};
}

void Date::add_day(int n)
{
	d+=n;
	if (d == 31)
	{
		d = 1;
		m += 1;
	}
}

bool Date::isvalid()
{
	if (int(m) < 1 || int(m) > 12)
		return false;
	if (int(d) < 1 || int(d) > 30)
		return false;
	if (int(y) < 0)
		return false;
	return true;
}
int Date::year()
{
	return y;
}
int Date::month()
{
	return m;
}
int Date::day()
{
	return d;
}
int Date:: date_test(Date t)
{
	if (t.m < 1 or t.m > 12) error("Invalid month");
	if (t.d < 1 or t.d >30) error("invalid day");
	if (t.y < 0) error("Negative year");
}
int main()
{
	Date today{ 2018, 7, 20 };

	cout << " Today= " <<  today.month() << '/' << today.day() << '/' << today.year() << endl;
}