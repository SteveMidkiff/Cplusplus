/****************************************************************
* COSC 1337 - Programming Fundamentals II			*
* Assignment 6 - Monkey Food					*
* Programmer: Steve Midkiff					*
* Completed 3/21/14						*
* Status Complete						*
*								*
* This program uses a two-dimensional array to store info	*
* on weekly eating habits of three monkeys. The program	 	*
* will use the info to calculate important eating habit info.	*
****************************************************************/

#include <iostream>
#include <iomanip>
using namespace std;

const int NUM_MONKEYS = 3;			// constant for num of monkeys
const int NUM_DAYS = 7;			// constant for num of days

void getInfo(float [][NUM_DAYS], int);	// Define fuction for getting info
void showInfo(float [][NUM_DAYS], int);	// Define function for showing info
string weekday(int);			// Define function for day of the week
float avgFood(float [][NUM_DAYS], int);	// Define function for averaging food eaten
float leastFood(float [][NUM_DAYS], int);	// Define function for least food
float mostFood(float [][NUM_DAYS], int);	// Define function for most food
bool valid(float A);			// prototype for validating integer inputs

int main(){

	float monkeyFood[NUM_MONKEYS][NUM_DAYS];	// Define array for monkey food

	getInfo(monkeyFood, NUM_MONKEYS);
	showInfo(monkeyFood, NUM_MONKEYS);
	
return 0;
}	// end main


/************************************************************************
*	This is the function for getting info into the array		*
************************************************************************/


void getInfo(float myArray[][NUM_DAYS], int NUM_MONKEYS){
	for(int i = 0; i < NUM_MONKEYS; i++){
		for(int j = 0; j < NUM_DAYS; j++){
			do{
			cout << "Enter pounds of food eaten by monkey ";
			cout << i+1 << " on " << weekday(j+1) << ": ";
			cin >> myArray[i][j];
			} while(!valid(myArray[i][j]));
		}	// end inside for loop
	}	// end outside for loop
}	// end getInfo function


/************************************************************************
*	This is the function for showing the required report		*
************************************************************************/

void showInfo(float myArray[][NUM_DAYS], int NUM_MONKEYS){

		// displaying report headings

	cout << "\nPounds of Food Eaten by Monkey and Day of Week" << endl;
	cout << endl;
	cout << fixed << showpoint << setprecision(1);
	cout << "Monkey";
	for(int i=1; i<=NUM_DAYS; i++)
		cout << setw(6) << weekday(i);
	cout << endl;

		// loop for displaying data in array

	for(int i=0; i < NUM_MONKEYS; i++){
		cout << setw(6) << i+1;
		for(int j=0; j < NUM_DAYS; j++){
			cout << setw(6) << myArray[i][j];}
		cout << endl;}
	cout << endl;

		// Average food eaten per day

	cout << "The average food eaten per day by all monkeys\t:";
	cout << setw(7) << avgFood(myArray, NUM_MONKEYS) << "pounds" << endl;

		// least amount of food eaten by any monkey

	cout << "The least amount of food eaten by any monkey\t:";
	cout << setw(7) << leastFood(myArray, NUM_MONKEYS) << "pounds" << endl;

		// largest amount of food eaten by any monkey

	cout << "The largest amount of food eaten by any monkey\t:";
	cout << setw(7) << mostFood(myArray, NUM_MONKEYS) << " pounds" << endl;

}	// end showInfo function


/************************************************************************
*	This is the function for showing the day of the week		*
************************************************************************/

string weekday(int day){
	string weekday;		// declare variable for day of the week

	switch(day){
	case 1:
		weekday = "Sun";
		break;
	case 2:
		weekday = "Mon";
		break;
	case 3:
		weekday = "Tue";
		break;
	case 4:
		weekday = "Wed";
		break;
	case 5:
		weekday = "Thu";
		break;
	case 6:
		weekday = "Fri";
		break;
	case 7:
		weekday = "Sat";
		break;
	default: 
		weekday = "weekday";
	}	// end switch

return weekday;
}	// end weekday function

/************************************************************************
*	This is the function for getting the average food eaten		*
************************************************************************/

float avgFood(float myArray[][NUM_DAYS], int NUM_MONKEYS){
	double total;	// declare variable for totaling food eaten
	float average;	// declare variable for average
	int count = 0;	// declare variable for count

		// loop for finding total
	for(int i=0; i<NUM_MONKEYS; i++){
		for(int j=0; j<NUM_DAYS; j++){
			total += myArray[i][j];
			count++;
		}	// end inside loop
	}	// end outside loop

	average = total/count;

return average;
}	// end average food function

/************************************************************************
*	This is the function for getting the least food eaten		*
************************************************************************/

float leastFood(float myArray[][NUM_DAYS], int NUM_MONKEYS){
	float least = myArray[0][0];	// declare variable for least food eaten

		// loop for finding least
	for(int i=0; i<NUM_MONKEYS; i++){
		for(int j=0; j<NUM_DAYS; j++){
			if(myArray[i][j] < least)
				least = myArray[i][j];
		}	// end inside loop
	}	// end outside loop

return least;
}	// end least food function

/************************************************************************
*	This is the function for getting the most food eaten		*
************************************************************************/

float mostFood(float myArray[][NUM_DAYS], int NUM_MONKEYS){
	float most = myArray[0][0];	// declare variable for most food eaten

		// loop for finding most
	for(int i=0; i<NUM_MONKEYS; i++){
		for(int j=0; j<NUM_DAYS; j++){
			if(myArray[i][j] > most)
				most = myArray[i][j];
		}	// end inside loop
	}	// end outside loop

return most;
}	// end most food function


/************************************************************************
*	This is the function for validating the data inputs		*
************************************************************************/

bool valid(float A){

bool isValid = true;
float test = A;

if ((!test) || (test < 0)){
	cout << "Input must be a positive integer." << endl;
	cin.clear();
	cin.ignore(100,'\n');
	isValid = false;
		}

return isValid;
}	// end integer validation
