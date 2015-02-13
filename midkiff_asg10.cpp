/****************************************************************
* COSC 1337 - Programming Fundamentals II
* Assignment 10 - Payroll 3.0
* Programmer: Steve Midkiff	
* Completed 5/2/14	
* Status Complete	
*
* This program accepts input from a file, calculates payroll
* then stores that information in a payroll report
*													
****************************************************************/


#include<iostream>
#include<iomanip>
#include<fstream>
#include<cstdlib>
using namespace std;

class Employee 
{
  private:
    int id;             // employee ID
    char name[21]; 		// employee name
    double hourlyPay;   // pay per hour
    int numDeps;        // number of dependants
    int type;           // employee type
    
  public:
    Employee( int initId=0, char initName[21]='\0', 
              double initHourlyPay=0.0, 
              int initNumDeps=0, int initType=0 );  // Constructor

    bool set(int newId, char newName[], double newHourlyPay,
             int newNumDeps, int newType);

			// declare get functions for each instance variable

	int getId();
	char* getName();
	double getHourlyPay();
	int getNumDeps();
	int getType();
    
};

Employee::Employee( int initId, char initName[21], 
                    double initHourlyPay,
                    int initNumDeps, int initType )
{
  bool status = set( initId, initName, initHourlyPay, 
                     initNumDeps, initType );

  if ( !status )
  {
    id = 0;
    strcpy(name, "");
    hourlyPay = 0.0;
    numDeps = 0;
    type = 0;    
  }
}

bool Employee::set( int newId, char newName[21], double newHourlyPay,
                                 int newNumDeps, int newType )
{
  bool status = false;

  if ( newId > 0 && newHourlyPay > 0 && newNumDeps >= 0 && 
       newType >= 0 && newType <= 1 )
  {
    status = true;
    id = newId;
    strcpy(name, newName);
    hourlyPay = newHourlyPay;
    numDeps = newNumDeps;
    type = newType;
  }
  return status;
}

int Employee::getId(){
	return id;
}	// end get id function

char* Employee::getName(){
	return name;
}	// end get name function

double Employee::getHourlyPay(){
	return hourlyPay;
}	// end get hourly pay function

int Employee::getNumDeps(){
	return numDeps;
}	// end get number of dependants function

int Employee::getType(){
	return type;
}	// end get type function



// // *************************Main Program ******************************


	const int NUM_EMPS = 100;		// Number of employees
	const float TAX = 0.15;		// constant for tax rate
	const float insCost = 20.00;	// cost per dependent for insurance

struct HrsWorked{
	int empID;		// employee id
	double hours;	// hours worked
};

int main (){

	int numRecords = 0;							// variable for counting emp records

	Employee *emp = new Employee[NUM_EMPS];		// Define an array of emp structures
	HrsWorked *hrs = new HrsWorked[NUM_EMPS];	// Define an array for emp hours

	
	// function prototypes
	
	int readEmp(Employee *);	// prototype for reading employee info
	void readHrs(HrsWorked *);		// prototype for reading employee hours
	double searchList(int, const HrsWorked *, int);		// prototype for searching employee info
	void writeEmp(Employee *, HrsWorked *, int);	// prototype for writing payroll report

			// Function calls

	numRecords = readEmp(emp);
	readHrs(hrs);
	writeEmp(emp, hrs, numRecords);

return 0;
}	// end of main function


/************************************************************************
*	This is the function for reading employee info into array	
************************************************************************/

int readEmp(Employee *emp){

	fstream empFile;		// employee input file

	int id;		       			// employee ID
	char name[21];        		// employee name
	double hourlyPay;   		// pay per hour
	int numDeps;        		// number of dependants
	int type, count=0;          // employee type
	char gender;				// emp gender
	
	// Get employee master information

	empFile.open("master10.txt", ios::in);
	if(!empFile)
	{
		cout << "Can not open employee file \"master10.txt\"" << endl;
		exit(1);
	}
	int i = 0;
	do{
		empFile >> id;
		empFile.get(name, 21);
		empFile >> hourlyPay;
		empFile >> numDeps;
		empFile >> type;
		empFile >> gender;
		if(!empFile.fail()){
			(emp + i)->set(id, name, hourlyPay, numDeps, type);
			count++;}
		i++;
	}while(!empFile.fail());
	
	cout << count;
	empFile.close();
	return count;
}	// end readEmp function

/************************************************************************
*	This is the function for finding employee hours worked	
************************************************************************/

double searchList(int id, const HrsWorked * hrs, int numRecords){

			// for each emp ID find hrsworked empid and return hrs

	int i = 0; // Used as a subscript to search array
	bool found = false; // Flag to indicate if the value was found
	double value;

	while (i < numRecords && !found)
	{
	if (hrs[i].empID == id) // If the value is found
	{
	found = true; // Set the flag
	value = hrs[i].hours; // Record the employees hours
	}
	i++; // Go to the next element
	}
 return value; // Return the employee hours
}	// End search
			

/************************************************************************
*	This is the function for reading hours info into array	
************************************************************************/

void readHrs(HrsWorked *hrs){

	fstream transFile;		// transaction input file

	int transId;       		// employee ID
	double inHrs;   		// pay per hour

	
	// Get timecard information

	transFile.open("trans10.txt", ios::in);
	if(!transFile)
	{
		cout << "Can not open employee file \"trans10.txt\"" << endl;
		exit(1);
	}
	
	for (int i = 0; i < NUM_EMPS; i++)
	{
		transFile >> transId >> inHrs;
		(hrs + i)->empID = transId;
		(hrs + i)->hours = inHrs;
	}	

	transFile.close();

}	// end reading transaction file

/************************************************************************
*	This is the function for writing employee info to report	
************************************************************************/

void writeEmp(Employee *emp, HrsWorked *hrs, int numRecords){

	fstream report;			// report output file

	double grossPay,			// Define a variable for gross pay
	hours,						// Define a variable to hold emp hours
	totalGross = 0,				// Accumulator variable for total gross pay
	netPay,					// Define a variable for net pay
	insure = 0,				// Define a variable for insurance
	totalNet = 0;				// Accumulator variable for total net pay
	int numTrans = 0;			// Accumulator for number of transactions
	
// write the payroll report to file

	report.open("payroll10.txt", ios::out);
	
	report << "\nPayroll Report\n\n";
	report << left << setw(5) << "ID";
	report << setw(20) << "Name";
	report << right << setw(9) << "Gross Pay";
	report << setw(9) << "Tax";
	report << setw(10) << "Insurance";
	report << setw(9) << "Net Pay";
	report << endl;

	report << fixed << showpoint << setprecision(2);

	for (int i = 0; i < numRecords; i++){
		if((emp + i)->getId() != 0){
			hours = searchList((emp+i)->getId(), hrs, numRecords);
			if(hours > 0.0){
				numTrans++;
				if ((emp + i)->getType() == 0 && hours > 40){
					grossPay = (((emp + i)->getHourlyPay() * 1.5) * (hours - 40)) +
						((emp + i)->getHourlyPay() * 40);
				}
				else 
					grossPay = (emp + i)->getHourlyPay() * hours;
				totalGross += grossPay;
				insure = (emp + i)->getNumDeps() * insCost;

				netPay = grossPay - insure - (grossPay * TAX);
				totalNet += netPay;

				report << left << setw(4) << (emp + i)->getId();
				report << setw(20) << (emp + i)->getName();
				report << right << setw(9) << grossPay;
				report << setw(9) << grossPay * TAX;
				report << setw(10) << insure;
				report << setw(9) << netPay;
				report << endl;
			}	// end of inside if statement
			else{
			cout << "Hours worked must be greater than 0." << endl;
			cout << "Payroll not processed for " << (emp + i)->getName() << endl;
			}	// end of inside else statement
		}	// end of outside if statement
		else{
		cout << "File item #" << i + 1 << " has invalid data. Item not processed." << endl;
		}	// end of outside else statement

	}	// end of write for loop

report << "\n\nTotal Gross Pay $" << totalGross << endl;
report << "Total Net Pay $" << totalNet << endl;
cout << "Total number of transactions processed: " << numTrans;

report.close();

}	// end writeEmp function
	