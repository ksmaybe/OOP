#include "std_lib_facilities.h"

int main() {
	cout << "Please enter your name\n";
	string first_name;
	int age;
	cin >> first_name;
	cin >> age;
	cout << first_name + "\n" << age <<" years old" <<endl;
	keep_window_open();
}