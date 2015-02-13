/****************************************************************
* COSC 1337 - Programming Fundamentals II			*
* Assignment 5 - Payroll version 1.0				*
* Programmer: Steve Midkiff					*
* Completed 3/18/14						*
* Status Complete						*
*								*
* This program uses an array of structures to hold payroll	*
* data and then print a report for each employee.	 	*
****************************************************************/

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

struct EmpInfo{
	int empID;	// employee id
	string name;	// employee name
	double payRate; // Hourly pay rate
	int empType;	// type of employee - management or union
};

int main (){
	const int NUM_EMPS = 4;		// Number of employees
	const float TAX = 0.15;		// constant for tax rate
	EmpInfo employee[NUM_EMPS];	// Define an array of emp structures
	float hours[NUM_EMPS];		// Define an array for hours worked
	double grossPay,		// Define a variable for gross pay
	totalGross = 0,			// Accumulator variable for total gross pay
	netPay,				// Define a variable for net pay
	totalNet = 0;			// Accumulator variable for total net pay

	bool valid(int A);		// prototype for validating integer inputs
	bool valid(double A);		// prototype for validating double inputs	
	bool validHours(double A);	// prototype for validating timecard hours

	// Get employee master information


	for (int i = 0; i < NUM_EMPS; i++){
		cout << "\nEnter information for employee " << (i + 1) << endl;

			// get and validate the employee ID
		do{
			cout << "Employee id: ";
			cin >> employee[i].empID;
		} while (!valid(employee[i].empID));

			// get the employee name	
		cout << "Employee name: ";
		cin.ignore();			// skip the newline character
		getline(cin, employee[i].name);	

			// get and validate the payrate
		do{
		cout << "Pay rate: ";
		cin >> employee[i].payRate;
		} while (!valid(employee[i].payRate));

			// get and validate the employee type
		do{
		cout << "Employee Type (0 or 1): ";
		cin >> employee[i].empType;
		} while (employee[i].empType < 0 || employee[i].empType > 1);

	}

	// Get timecard information

	cout << "\nEnter timecard information for each employee:" << endl;

	for (int i = 0; i < NUM_EMPS; i++){
		do{
		cout << "Hours worked for " << employee[i].name;
		cout << ": ";
		cin >> hours[i];
		} while (!validHours(hours[i]));

	}	// end timecard info

	

	// Display the payroll report

	cout << "\nPayroll Report\n\n";
	cout << left << setw(4) << "ID";
	cout << setw(25) << "Name";
	cout << right << setw(9) << "Gross Pay";
	cout << setw(9) << "Tax";
	cout << setw(9) << "Net Pay";
	cout << endl;

	cout << fixed << showpoint << setprecision(2);

	for (int i = 0; i < NUM_EMPS; i++){
	if (employee [i].empType == 0 && hours[i] > 40){
		grossPay = ((employee[i].payRate * 1.5) * (hours[i] - 40)) +
			(employee[i].payRate * 40);
	}
	else 
		grossPay = employee[i].payRate * hours[i];
	totalGross += grossPay;

	netPay = grossPay - (grossPay * TAX);
	totalNet += netPay;

	cout << left << setw(4) << employee[i].empID;
	cout << setw(25) << employee[i].name;
	cout << right << setw(9) << grossPay;
	cout << setw(9) << grossPay * TAX;
	cout << setw(9) << netPay;
	cout << endl;
	}	// end of display for loop

cout << "\n\nTotal Gross Pay $" << totalGross << endl;
cout << "Total Net Pay $" << totalNet << endl;

return 0;
}	// end of main function

/************************************************************************
*	This is the function for validating integers			*
************************************************************************/

bool valid(int A){

bool isValid = true;
int test = A;

if ((!test) || (test <= 0)){
	cout << "Input must be a positive integer." << endl;
	cin.clear();
	cin.ignore(100,'\n');
	isValid = false;
		}

return isValid;
}	// end integer validation


/************************************************************************
*	This is the function for validating doubles			*
************************************************************************/

bool valid(double A){

bool isValid = true;
double test = A;

if ((!test) || (test <= 0)){
	cout << "Input must be a positive non-zero numeric value." << endl;
	isValid = false;
	cin.clear();
	cin.ignore(100,'\n');
		}

return isValid;


}	// end double validation

/************************************************************************
*	This is the function for validating doubles			*
************************************************************************/

bool validHours(double A){

bool isValid = true;
double test = A;

if ((!test) || (test < 0)){
	cout << "Input must be a positive numeric value or zero." << endl;
	isValid = false;
	cin.clear();
	cin.ignore(100,'\n');
		}

return isValid;


}	// end hours validation