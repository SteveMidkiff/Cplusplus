/****************************************************************
* COSC 1337 - Programming Fundamentals II			*
* Assignment 3 - Checkbook Balancing Revisited			*
* Programmer: Steve Midkiff					*
* Completed 2/3/14						*
* Status Complete						*
*								*
* This program accepts input from the user for intial balance	*
* checks and deposits and uses that input to keep track 	*
* of the checking account balance and service charges		*
* uses functions for each transaction type			*
****************************************************************/

#include <iostream>
#include <iomanip>
#include <cstdlib>
using namespace std;

// function prototypes

void displayMenu();
void check(double& balance, double amount);
void deposit(double& balance, double amount);
char validate(char& selection);


int main ()
{
// initialize variables

const float SVC_CHARGE = 0.25;	// a constant for the check service charge
const int NSF_CHARGE = 25;	// a constant for the insufficient funds charge

double	balance = 0,		// initialized account balance variable
	amount = 0,			// amount of transaction input by the user
	finalBalance,		// final balance after all checks and deposits
	totalSvcCharge = 0,	// an accumulator variable for check service fees
	totalNSFCharge = 0,	// an accumulator variable for insufficient funds fees
	acctBalCharge = 0,	// initialized variable for account falling below $800
	totalChecks = 0;

char selection;			// for the user input menu selection


system("cls");  		// clear the screen	       

// Print the program heading and get the initial account balance

cout << "Checkbook Balancing Program" << endl;
cout << "\nEnter the beginning balance: ";
cin >> balance;

// display the menu selections
	
displayMenu();

// set the numeric output formatting

cout << fixed << showpoint << setprecision(2);

do{

// Get the users selection

	cout << "Enter transaction type and amount: ";
	cin >> selection;
	if (selection != 'E')
		cin >> amount;

// validate the selection

	while (selection < 'C' || selection > 'E')
		{
		cout << "That is not a valid selection.\n";
		cout << "Selection must be a capital C, D, or E.\n";
		cout << "Please select again: ";
		cin >> selection;
		}

	if (selection != 'E') 
	{
		switch	(selection)
		{
				// process a check
		case 'C' :
			check(balance, amount);

			// calculate service charges

			totalChecks += SVC_CHARGE;

			// check for insufficient funds

			if ((balance < 800) && (acctBalCharge < 5))
				acctBalCharge = 5; 

			// check for balance below $800

			if (balance < 0)
			totalNSFCharge += NSF_CHARGE;

			// print the results after the check has been processed

			cout << endl;
			cout << "Processing check for $" << amount << endl;
			cout << "Balance: $" << balance << endl;
			cout << "Service charge: $" << SVC_CHARGE << " for a check" << endl;
			if (totalNSFCharge)
				{
				cout << "Service charge: $" << totalNSFCharge << " for insufficient funds." << endl;
				}
			if (acctBalCharge)
				{
				cout << "Service charge: $" << acctBalCharge << " balance below $800.00" << endl;
				}
			totalSvcCharge = acctBalCharge + totalNSFCharge + totalChecks;
			cout << "Total service charges: $" << totalSvcCharge << endl;
			cout << endl;
			break;
				// process a deposit
		case 'D' :
			deposit(balance, amount);

			// print the results after the deposit has been processed

			cout << endl;
			cout << "Processing deposit for $" << amount << endl;
			cout << "Balance: $" << balance << endl;
			cout << "Total service charges: $" << totalSvcCharge << endl;
			cout << endl;
			break;
		}

	}
} while (selection != 'E');

// Print the final account balance after all checks, deposits 
// and service charges have been processed
cout << "Processing end of the month" << endl;

// Calculate final balance
finalBalance = balance - totalSvcCharge;
cout << "Final Balance: $" << finalBalance << endl;

return 0;
}				// end main

/************************************************************************
*	This is the function for displaying the menu			*
************************************************************************/

void displayMenu()
{
	cout << endl;
	cout << "Commands:" << endl;
	cout << "C - process a check" << endl;
	cout << "D - process a deposit" << endl;
	cout << "E - End the program" << endl;
}

/************************************************************************
*	This is the function for validating the selection		*
*	It takes the selection variable and makes sure it is viable	*
*	then passes the results back to the selection variable		*
************************************************************************/

char validate(char& selection)
{
	if (selection < 'C' || selection > 'E')
		{
		cout << endl;
		cout << "That is not a valid selection.\n";
		cout << "Selection must be a capital C, D, or E.\n";
		cout << "Please select again: ";
		cin >> selection;
		}
return selection;
}

/************************************************************************
*	This is the function for processing a check			*
*	It takes the balance variable by reference and processes	*
*	the amount passed to it		*
************************************************************************/

void check(double& balance, double amount)
{
	// deduct the value of the check from balance
	balance -= amount;
	
}

/************************************************************************
*	This is the function for processing a deposit			*
*	It takes the balance variable by reference and processes	*
*	the amount passed to it, then prints the results		*
************************************************************************/

void deposit(double& balance, double amount)
{
	// add the value of the deposit to balance
	balance += amount;
}
