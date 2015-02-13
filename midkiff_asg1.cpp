//*******************************************
// COSC 1337 - Programming Fundamentals II
// Assignment 1 - Expression Review
// Programmer: Steve Midkiff
// Completed 1/15/14
// Status Complete
//
// This program accepts two integers from the user
// then performs several calculations with the numbers
//****************************************************

#include <iostream>
using namespace std;

int main()
{
	int x, y;

//	Get the user to input two integers
	cout << "Enter two integers: ";
	cin >> x >> y;

//	Output for the calculations. I could have used setw
//	but it was easier to match your output w/ the tab
	cout << "\nSum\t\tis " << (x + y) << endl;
	cout << "\nProduct\t\tis " << (x * y) << endl;
	cout << "\nAverage\t\tis " << ((x + y) / 2) << endl;
	cout << "\nQuotient\tis " << (x / y) << endl;
	cout << "\nModulus\t\tis " << (x % y) << endl;

	return 0;
}	// end main function
