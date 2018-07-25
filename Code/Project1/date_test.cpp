#include "std_lib_facilities.h"

vector<int> non_leap_day{ 0,31,28,31,30,31,30,31,31,30,31,30,31 };
vector<int> leap_day{ 0,31,29,31,30,31,30,31,31,30,31,30,31 };
vector<int> last_day;
vector<string> mons{ "haha","January","Feburary","March","April","May","June","July","August","September","Ocotober","November","December" };

class Date
{
public:
	class Invalid{};
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
	jan=1,feb,mar,apr,may,jun,jul,aug,sep,oct,nov,dec
};

Month operator++(Month& m)
{
	m = (m == Month::dec) ? Month::jan : Month(int(m) + 1);
	return m;
}

Date::Date(int yy, int mm,int dd)
	:y{yy},m{mm},d{dd}
{
	if (y % 4 == 0) last_day = leap_day;
	else
		last_day = non_leap_day;
	if (!isvalid())
		throw Invalid{};
}
ostream& operator <<(ostream& os,  Date d)
{
	return os << '(' << mons[d.month()]  << " " << d.day() << "," << d.year() << ")" << endl;
}
void f(int x,int y,int z)
try
{
	Date dxy{ x,y,z };
	cout << dxy << endl;
	dxy.add_day(2);
	cout << dxy << endl;
}
catch(Date::Invalid)
{
	error("invalid date");
}

void Date::add_day(int n)
{
	if (n > 10)
	{
		add_day(10);
		add_day(n - 10);
	}
	else
	{
		d += n;
	}
}

bool Date::isvalid()
{
	if (int(m) < 1 || int(m) > 12)
		return false;
	if (int(d) < 1 || int(d) > last_day[m])
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
	if (t.m < 1 || t.m > 12) error("Invalid month");
	if (t.d<1 || t.d > last_day[t.m]) error("invalid day");
	if (t.y < 0) error("Negative year");
	return 0;
}

int main()
{
	int x;
	int y;
	int z;
	cout << "Enter Year_Month_Day: ";
	cin >> x >> y >> z;
	f(x, y, z);
	
}