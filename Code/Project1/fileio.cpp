#include "std_lib_facilities.h"

struct Reading
{
	int hour;
	double temperature;
};

int main()
{
	cout << "Please input file name: ";
	string iname;
	cin >> iname;
	ifstream ist{ iname };
	if (!ist) error("can't open input file ", iname);

	string oname;
	cout << "Please enter name of output file: ";
	cin >> oname;
	ofstream ost{ oname };
	if (!ost) error("can't open out put file ", oname);

	vector<Reading> temps;
	string input;
	int hour;
	double temperature;
	while(ist >> input)
	{
		istringstream ss(input);
		string token;
		getline(ss, token, ',');
		stringstream d(token);
		d >> hour;
		string token1;
		getline(ss, token1, '\n');
		stringstream k(token1);
		k >> temperature;
		if (hour < 0 || 23 < hour) error("hour out of range");
		temps.push_back(Reading{ hour,temperature });
	}
	for (int i = 0; i < temps.size(); ++i)
		ost << '(' << temps[i].hour << '	' << temps[i].temperature << ')' << endl;
}
