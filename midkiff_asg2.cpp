//*******************************************
// COSC 1337 - Programming Fundamentals II
// Assignment 2 - Checkbook Balancing
// Programmer: Steve Midkiff
// Completed 1/24/14
// Status Complete
//
// This program accepts input from the user for intial balance
// checks and deposits and uses that input to keep track 
// of the checking account balance 
//****************************************************

#include <iostream>
#include <iomanip>
using namespace std;

int main ()
{
// initialize variables

	const float SVC_CHARGE = 0.25; // a constant for the check service charge

	double	balance = 0, // initialized account balance variable
		checkAmount, // amount of check input by the user
		depositAmount, // amount of deposit input by the user
		finalBalance, // calculated final balance after all checks and deposits
		totalSvcCharge = 0; // an accumulator variable for the check service fees

	char selection; // for the user input menu selection

// Print the program heading and get the initial account balance
	       
	cout << "Checkbook Balancing Program" << endl;
	cout << "\nEnter the beginning balance: ";
	cin >> balance;

// Print the available menu selections

	cout << "Commands:" << endl;
	cout << "C - process a check" << endl;
	cout << "D - process a deposit" << endl;
	cout << "E - End the program" << endl;

// Get the users selection

	cout << "Enter transaction type: ";
	cin >> selection;

	while (selection != 'E')
	{
		// set the numeric output formatting
		cout << fixed << showpoint << setprecision(2);

		// validate the menu selection
		if ((selection < 'C') || (selection > 'E'))
			{
			cout << "That is not a valid selection.\n";
			cout << "Selection must be a capital C, D, or E.\n";
			cout << "Please select again: ";
			cin >> selection;
			}

		else if (selection == 'C')
			{
			// Get the user input for the check
			cout << "Enter transaction amount: ";
			cin >> checkAmount;

			// deduct the value of the check from balance
			balance -= checkAmount;

			// calculate service charges
			totalSvcCharge += SVC_CHARGE;

			// print the results after the check has been processed
			cout << "Processing check for $" << checkAmount << endl;
			cout << "Balance: $" << balance << endl;
			cout << "Service charge: $" << SVC_CHARGE << " for a check" << endl;
			cout << "Total service charges: $" << totalSvcCharge << endl;

			// get another menu selection 
			cout << "\nEnter transaction type: ";
			cin >> selection;			
			}

		else if (selection == 'D')
			{
			cout << "Enter transaction amount: ";
			cin >> depositAmount;
			
			// add the value of the deposit to balance
			balance += depositAmount;

			// print the results after the deposit has been processed
			cout << "Processing deposit for $" << depositAmount << endl;
			cout << "Balance: $" << balance << endl;
			cout << "Total service charges: $" << totalSvcCharge << endl;

			// get another menu selection
			cout << "\nEnter transaction type: ";
			cin >> selection;			
			}
		


	} // end of transaction block

	// Print the final account balance after all checks, deposits 
	// and service charges have been processed
	cout << "Processing end of the month" << endl;
	// Calculate final balance
	finalBalance = balance - totalSvcCharge;
	cout << "Final Balance: $" << finalBalance << endl;

return 0;
} // end main function