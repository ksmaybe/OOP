#include "std_lib_facilities.h"

int main()
{
	cout << "Enter the name of the person you want to write to\n";
	string first_name;
	cin >> first_name;
	cout << "Enter the name of your friend\n";
	string friend_name;
	cin >> friend_name;
	cout << "Enter your age\n";
	int age;
	cin >> age;

	int lol=2;
	if (age < 0 or age>110)
		simple_error("Error age");
	else if (age < 17)
		lol = 1;
	else if (age > 65)
		lol = 3;


	cout << "Dear " << first_name << endl;
	cout << "Have you seen " << friend_name << " lately?\n";
	cout << "I heard that you had a birthday and you are now " << age << " years old!\n";
	if (lol == 1)
		cout << "You are young to be at NYU!\n";
	else if (lol = 2)
		cout << "Welcome to NYU!\n";
	else
		cout << "It's great to see senior students around campus!\n";



	keep_window_open();

}