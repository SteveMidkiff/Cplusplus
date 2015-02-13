/****************************************************************
* COSC 1337 - Programming Fundamentals II			*
* Assignment 4 - Date Class					*
* Programmer: Steve Midkiff					*
* Completed 2/16/14						*
* Status Complete						*
*								*
* This program creates a class called Date with functions to	*
* set the date and print the date in different formats.	 	*
* It also has a function that returns the month of the date.	*
* The main function tests each of the class member functions	*
****************************************************************/

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <string>
using namespace std;

// Date class declaration
class Date
{
private:
	int day;		// a variable for the day of the month	
	int month;		// a variable for the month
	int year;		// a variable for the year

	string getMonthName();		// prototype for getMonthName function

public:
	Date();					// constructor
	void setDate(int, int, int);		// prototype for for setdate function
	void printDate1();			// prototype for first print date format
	void printDate2();			// prototype for second print date format
	void printDate3();			// prototype for third print date format



};	// end of class definition

/************************************************************************
*	Date::date							*
*	This function is the class constructor function			*
************************************************************************/

Date::Date()
{
	day = 1;
	month = 1;
	year = 2001;
}


/************************************************************************
*	Date::setDate							*
*	This function sets the new date to be stored in the Date object *
************************************************************************/

void Date::setDate(int newMonth, int newDay, int newYear)
{
	// validate the new entered date

	if ((newMonth >= 1) && (newMonth <= 12) &&
	(newDay >= 1) && (newDay <= 31) &&
	(newYear >= 1950) && (newYear <= 2020))
	{
		// set the new date
		day = newDay;
		month = newMonth;
		year = newYear;	
	}
	else
	{
		cout << "That is not a valid date." << endl;
	}		
}


/************************************************************************
*	Date::printDate1						*
*	This function prints the date in mm/dd/yyyy format		*
************************************************************************/

void Date::printDate1()
{
	cout << month << "/" << day << "/" << year;
}

/************************************************************************
*	Date::printDate2						*
*	This function prints the date in month day, year format		*
************************************************************************/

void Date::printDate2()
{
	cout << getMonthName() << " " << day << ", " << year;
	
}


/************************************************************************
*	Date::printDate3						*
*	This function prints the date in day month year format		*
************************************************************************/

void Date::printDate3()
{
	cout << day << " " << getMonthName() << " " << year;
}


/************************************************************************
*	Date::printDate3						*
*	This function prints the date in day month year format		*
************************************************************************/

string Date::getMonthName()
{
	string monthName;

	switch(month)
	{
		case 1: monthName = "January";
			break;
		case 2: monthName = "February";
			break;
		case 3: monthName = "March";
			break;
		case 4: monthName = "April";
			break;
		case 5: monthName = "May";
			break;
		case 6:	monthName = "June";
			break;
		case 7: monthName = "July";
			break;
		case 8: monthName = "August";
			break;
		case 9: monthName = "September";
			break;
		case 10: monthName = "October";
			break;
		case 11: monthName = "November";
			break;
		case 12: monthName = "December";
	}
	return monthName;
}

//************************** main ********************************

int main()	
{
	Date myDate;		// Declare a date object

	int month;		// a variable for the input month
	int day;		// a variable for the input day
	int year;		// a variable for the input year


	system("cls");  	// clear the screen
	myDate.printDate1();	// Print the new date object

	// get input and set a new date
	cout << "\nPlease enter a month 1-12: ";
	cin >> month;
	cout << "\nPlease enter a day 1-31: ";
	cin >> day;
	cout << "\nPlease enter a year from 1950 through 2020: ";
	cin >> year;

	myDate.setDate(month, day, year);

	// print the new date in the remaining formats
	myDate.printDate2();
	cout << endl;
	myDate.printDate3();
	cout << endl;

return 0;
}		// end of main function


