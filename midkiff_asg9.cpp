
#include<iostream>
#include<iomanip>
#include<fstream>
#include<string>
using namespace std;

class Employee 
{
  private:
    int id;             // employee ID
    string name;        // employee name
    double hourlyPay;   // pay per hour
    int numDeps;        // number of dependants
    int type;           // employee type
    
  public:
    Employee( int initId=0, string initName="", 
              double initHourlyPay=0.0, 
              int initNumDeps=0, int initType=0 );  // Constructor

    bool set(int newId, string newName, double newHourlyPay,
             int newNumDeps, int newType);

			// declare get functions for each instance variable

	int getId();
	string getName();
	double getHourlyPay();
	int getNumDeps();
	int getType();
    
};

Employee::Employee( int initId, string initName, 
                    double initHourlyPay,
                    int initNumDeps, int initType )
{
  bool status = set( initId, initName, initHourlyPay, 
                     initNumDeps, initType );

  if ( !status )
  {
    id = 0;
    name = "";
    hourlyPay = 0.0;
    numDeps = 0;
    type = 0;    
  }
}

bool Employee::set( int newId, string newName, double newHourlyPay,
                                 int newNumDeps, int newType )
{
  bool status = false;

  if ( newId > 0 && newHourlyPay > 0 && newNumDeps >= 0 && 
       newType >= 0 && newType <= 1 )
  {
    status = true;
    id = newId;
    name = newName;
    hourlyPay = newHourlyPay;
    numDeps = newNumDeps;
    type = newType;
  }
  return status;
}

int Employee::getId(){
	return id;
}	// end get id function

string Employee::getName(){
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


	const int NUM_EMPS = 6;		// Number of employees
	const float TAX = 0.15;		// constant for tax rate
	const float insCost = 20.00;	// cost per dependent for insurance

struct HrsWorked{
	int empID;		// employee id
	double hours;	// hours worked
};

int main (){

	Employee *emp = new Employee[NUM_EMPS];		// Define an array of emp structures
	HrsWorked *hrs = new HrsWorked[NUM_EMPS];	// Define an array for emp hours

	
	// function prototypes
	
	void readEmp(Employee *);	// prototype for reading employee info
	void readHrs(HrsWorked *);		// prototype for reading employee hours
	int searchList(int);		// prototype for searching employee info
	void writeEmp(Employee *, HrsWorked *);	// prototype for writing payroll report

			// Function calls

	readEmp(emp);
	readHrs(hrs);
	writeEmp(emp, hrs);

return 0;
}	// end of main function


/************************************************************************
*	This is the function for reading employee info into array	
************************************************************************/

void readEmp(Employee *emp){

	fstream empFile;		// employee input file

	int id;		       		// employee ID
	string name;        		// employee name
	double hourlyPay;   		// pay per hour
	int numDeps;        		// number of dependants
	int type;           		// employee type
	
	// Get employee master information

	empFile.open("master9.txt", ios::in);
	if(!empFile)
	{
		cout << "Can not open employee file \"master9.txt\"" << endl;
		//return 1;
	}
	
	for (int i = 0; i < NUM_EMPS; i++)
	{
		empFile >> id;
		getline(empFile, name, '#');
		empFile >> hourlyPay;
		empFile >> numDeps;
		empFile >> type;
		(emp + i)->set(id, name, hourlyPay, numDeps, type);
	}	

	empFile.close();
	
}	// end readEmp function


/************************************************************************
*	This is the function for reading hours info into array	
************************************************************************/

void readHrs(HrsWorked *hrs){

	fstream transFile;		// transaction input file

	int transId;       		// employee ID
	double inHrs;   		// pay per hour

	
	// Get timecard information

	transFile.open("trans9.txt", ios::in);
	if(!transFile)
	{
		cout << "Can not open employee file \"trans9.txt\"" << endl;
		//return 1;
	}
	
	for (int i = 0; i < NUM_EMPS; i++)
	{
		transFile >> transId >> inHrs;
		(*(hrs + i)).empID = transId;
		(*(hrs + i)).hours = inHrs;
	}	

	transFile.close();

}	// end reading transaction file

/************************************************************************
*	This is the function for writing employee info to report	
************************************************************************/

void writeEmp(Employee *emp, HrsWorked *hrs){

	fstream report;			// report output file

	double grossPay,			// Define a variable for gross pay
	totalGross = 0,				// Accumulator variable for total gross pay
	netPay,					// Define a variable for net pay
	insure = 0,				// Define a variable for insurance
	totalNet = 0;				// Accumulator variable for total net pay
	int numTrans = 0;			// Accumulator for number of transactions
	
// write the payroll report to file

	report.open("payroll9.txt", ios::out);
	
	report << "\nPayroll Report\n\n";
	report << left << setw(5) << "ID";
	report << setw(20) << "Name";
	report << right << setw(9) << "Gross Pay";
	report << setw(9) << "Tax";
	report << setw(10) << "Insurance";
	report << setw(9) << "Net Pay";
	report << endl;

	report << fixed << showpoint << setprecision(2);

	for (int i = 0; i < NUM_EMPS; i++){
		if((*(emp + i)).getId() != 0){
			if((*(hrs + i)).hours > 0.0){
				numTrans++;
				if ((*(emp + i)).getType() == 0 && (*(hrs + i)).hours > 40){
					grossPay = (((*(emp + i)).getHourlyPay() * 1.5) * ((*(hrs + i)).hours - 40)) +
						((*(emp + i)).getHourlyPay() * 40);
				}
				else 
					grossPay = (*(emp + i)).getHourlyPay() * (*(hrs + i)).hours;
				totalGross += grossPay;
				insure = (*(emp + i)).getNumDeps() * insCost;

				netPay = grossPay - insure - (grossPay * TAX);
				totalNet += netPay;

				report << left << setw(4) << (*(emp + i)).getId();
				report << setw(20) << (*(emp + i)).getName();
				report << right << setw(9) << grossPay;
				report << setw(9) << grossPay * TAX;
				report << setw(10) << insure;
				report << setw(9) << netPay;
				report << endl;
			}	// end of inside if statement
			else{
			cout << "Hours worked must be greater than 0." << endl;
			cout << "Payroll not processed for " << (*(emp + i)).getName() << endl;
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
	