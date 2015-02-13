/****************************************************************
* COSC 1337 - Programming Fundamentals II						*
* Assignment 8 - Test Scores									*
* Programmer: Steve Midkiff										*
* Completed 4/14/14												*
* Status Complete												*
*																*
* This program accepts input from the user for a number of 		*
* students test scores, validates the input, sorts the values  	*
* & displays them in a table with the overall average score		*
* 																*
****************************************************************/

#include<iostream>
#include<iomanip>
#include<cstdlib>
#include<string>
using namespace std;

struct student{

	string name;		// student name variable
	int score;			// student score variable

};	// end structure

// function prototypes

	void getScores(student *, int);				// prototype for getting the student scores
	void displayScores(const student *, int);	// prototype for displaying the student scores
	bool valid(int A);							// prototype for validating integer inputs

int main(){

	int numStudents;							// variable for number of students
	student *scoresPtr;							// pointer for score array

	system("cls");  							// clear the screen

					// get the number of students to process

	cout << "Please enter the number of students to be processed: ";
	cin >> numStudents;
	scoresPtr = new student[numStudents];		// allocate memory for array

					// call the get and display functions

	getScores(scoresPtr, numStudents);
	displayScores(scoresPtr, numStudents);


return 0;
}				// end main


/************************************************************************
*	This is the function for validating integers						*
************************************************************************/

bool valid(int A){

	bool isValid = true;
	int test = A;

	if ((!test) || (test < 0) || (test > 105)){
		cout << "Input must be a positive integer between 0 and 105." << endl;
		cin.clear();
		cin.ignore(100,'\n');
		isValid = false;
			}

return isValid;
}	// end integer validation


/************************************************************************
*	This is the function for getting the student scores					*
************************************************************************/

void getScores(student *array, int size){

	int max = 30;
	string name;
	int score;

	for(int i = 0; i < size; i++){
	
		cout << endl;
		cout << "Enter student #" << i+1 << "'s name: ";
		cin.ignore();			// skip the newline character
		getline(cin, name);
		
		if(name.size() > max){
			cout << "Name cannot be longer than 30 characters." << endl;
			name = name.substr(0, max);}
		(*(array + i)).name = name;

		do{
		cout << "Enter student #" << i+1 << "'s test score: ";
		cin >> (*(array + i)).score;
		}while(!valid((*(array + i)).score));


	}	// end for loop

}	// end getScores function

/************************************************************************
*	This is the function for displaying the student scores				*
************************************************************************/

void displayScores(const student *array, int size){

float average(const student *, int);

	cout << endl;
	cout << setw(30) << left << "Name" << right << "Score" << endl;
	for(int i=1; i<=35; i++)
		cout << "-";

	for(int i=0; i<size; i++){
		cout << endl;
		cout << setw(30) << left << (*(array + i)).name;
		cout << setw(5) << right << (*(array + i)).score;
		}	// end for loop

	cout << endl;
	for(int i=1; i<=35; i++)
		cout << "-";

	cout << fixed << showpoint << setprecision(1);
	cout << endl;
	cout << setw(30) << left << "Average" << setw(7) << right << average(array, size);
	cout << endl;


}	// end displayScores function

/************************************************************************
*	This is the function for averaging the student scores				*
************************************************************************/

float average(const student *array, int size){

	int total = 0;
	float average = 0;

	for(int i=0; i<size; i++)
		total += (*(array + i)).score;

	average = total / size;

return average;
}	// end average function
