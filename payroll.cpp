// This is a program to calculate the monthly paycheck for the salespeople of SoftwarePirates Inc.

#include <iostream>
#include <string>
using namespace std;

float commission(float);
float bonus(float, int);
float addBonus(float, int);

int main()
{
int basePay = 2000, daysOff, deduct, longevity;
float sales, grossPay;
string empName;

cout << "Please enter the employee's name: ";
cin >> empName;
cout << "Enter employee's total sales for the month: ";
cin >> sales;
cout >> "Enter the number of days taken off this month: ";
cin >> daysOff;
cout >> "How many months has this employee worked for SoftwarePirates? ";
cin >> longevity;


(daysOff > 3) ? deduct = 200: deduct = 0;

grossPay = (basePay + commission(sales) + bonus(sales, longevity) + addBonus(sales, longevity
	)) - deduct;

cout << "\n" << empName << ", who has been with the company for " << longevity << " months, ";
cout << "has a base salary of $" << basePay << endl;
cout << "This month, " << empName << " earned a commission of $" << commission << endl;
cout << "This month, " << empName << " earned a bonus of $" << bonus << endl;
cout << "This month, " << empName << " earned an additional bonus of $" << addBonus << endl;
cout << "This month, " << empName << "had a deduction of $" << deduct << endl;
cout << "And " << empName << "'s total pay for this month is $" << grossPay << endl:


return 0;
}


float commission(float sales)
	{


	return total;
	}