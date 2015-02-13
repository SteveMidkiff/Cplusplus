/****************************************************************
* COSC 1337 - Programming Fundamentals II			*
* Assignment 7 - Postal Packages				*
* Programmer: Steve Midkiff					*
* Completed 4/10/14						*
* Status Complete						*
*								*
* This program accepts input from the user for a package to	*
* deliver, validates the input before accepting the package	*
* then calculates the shipping charges for the package		*
* 								*
****************************************************************/

#include<iostream>
#include<iomanip>
#include<cstdlib>
#include<string>
using namespace std;

// function prototypes

double shippingCosts(int weight);
int searchList(int myValue);
bool validPackage(int weight, int dimA, int dimB, int dimC);

int main(){

// initialize variables


	int acceptCount = 0;		// declare variable for tracking accepted
	int rejectCount = 0;		// declare variable for tracking rejected
	int transactNum = 0;		// declare variable for tracking tranactions
	int weight = 0;			// declare variable for weight
	int dimA, dimB, dimC;		// variables for dimensions
	double cost;
	string status;			// variable for package status


system("cls");  		// clear the screen

	cout << "For each transaction, enter package weight and 3 dimensions." << endl;
	cout << "Weight should be in pounds and dimensions should be in inches." << endl;
	cout << "Enter -1 to quit." << endl;

				// get user input

	while (weight != -1){
		transactNum++;
		cost = 0;
		cout << "\nEnter package weight and 3 dimensions: ";
		cin >> weight;
		if(weight != -1){
			cin >> dimA >> dimB >> dimC;
			if(validPackage(weight, dimA, dimB, dimC)){
				status = "accepted";
				acceptCount++;
				cost = shippingCosts(weight);

				}	//	end if for valid package
			else{
				status = "rejected";
				rejectCount++;
				cost = '-';
				}	//	end else for invalid package

			// print package cost details

		cout << endl;	
		cout << left << setw(11) << "Transaction" << ":" << right << setw(11) << transactNum << endl;
		cout << left << setw(11) << "Status" << ":" << right << setw(11) << status << endl;
		cout << left << setw(11) << "Weight" << ":" << right << setw(11) << weight << endl;
		cout << fixed << showpoint << setprecision(2);
		cout << left << setw(11) << "Cost" << ":";

		if(status == "rejected")
			cout << right << setw(11) << "-" << endl;
		else
			cout << right << setw(11) << cost << endl;
		}; 	// end if statement for checking quit
	};	//end while statement

			// print final package counts

	cout << "\nNumber of accepted packages: " << acceptCount << endl;
	cout << "Number of rejected packages: " << rejectCount << endl;

return 0;
}		// end main


/************************************************************************
*	This is the function for searching the weight array		*
************************************************************************/

int searchList(int myValue){
	
	int index = 0;				// declare index variable
	int position = -1;			// declare position variable
	bool found = false;			// declare variable for found
	int weightArray[] = {1, 2, 3, 5, 7, 10, 13, 16, 20, 25, 30, 35, 40, 45, 50};

			// find closest weight without going over 
	while (index < 15 && !found){
		if (myValue > weightArray[index])
			index++;
		else{
		position = index;
		found = true;
		}
	}	// end while loop

	return position;
}	// end searchList


/************************************************************************
*	This is the function for validating the package input		*
************************************************************************/

bool validPackage(int weight, int dimA, int dimB, int dimC){
	bool valid = true;		// declare variable for package validity
	int largest = dimA;		// declare variable for finding largest
	int girth;			// declare variable for finding girth

	if(dimB > largest)
		largest = dimB;
	if(dimC > largest)
		largest = dimC;
	girth = 2 * (dimA + dimB + dimC - largest);
	if(weight > 50 || dimA > 36 || dimB > 36 || dimC > 36 || girth > 60)
		valid = false;


return valid;
}	//	end validPackage function

/************************************************************************
*	This is the function for calculating shipping costs		*
************************************************************************/

double shippingCosts(int weight){

	double cost = 0;				// declare variable for cost
	float chargeArray[] = {1.50, 2.10, 4.00, 6.75, 9.90, 14.95, 19.40, 24.20, 27.30,
				31.90, 38.50, 43.50, 44.80, 47.40, 55.20};

			// calculate cost based on weight
	cost = chargeArray[searchList(weight)];


return cost;
}	// end shippingCosts function