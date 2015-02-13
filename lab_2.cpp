#include <iostream>
using namespace std ;

// define the function

void GalToLit()
{
float gallons, liters;
cout << "Input the number of gallons to convert to kilograms: ";
cin >> gallons;
liters = gallons * 3.9;
cout << gallons << " gallons is equal to " << liters << " in liters." << endl;
}

void poundsToKg();

int main()
{
	int convert;

	cout << "Please choose what you would like to convert:" << endl;
	cout << "Select 1 to convert miles to kilometers" << endl;
	cout << "Select 2 to convert fahrenheit to celsius" << endl;
	cout << "Select 3 to convert gallons to liters" << endl;
	cout << "Select 4 to convert pounds to kilograms" << endl;
	cout << "Select 5 to convert inches to centimeters" << endl;
	cout << "Or Select 0 to exit program" << endl;
	cout << "Your selection: ";
	cin >> convert;

	while (convert != 0)
		{
		if (convert == 1)
			{
			float miles, kilometers;
			cout << "Input the number of miles to convert to kilometers ";
			cin >> miles;
			kilometers = miles * 1.6;
			cout << miles << " miles is equal to " << kilometers << " in kilometers." << endl;
			}
		else if (convert == 2)
			{
			float degrees_c, degrees_f;
			cout << "Input the number of degrees fahrenheit to convert to degrees celsius ";
			cin >> degrees_f;
			degrees_c = (degrees_f - 32) * 5/9;
			cout << degrees_f << " degrees fahrenheit is equal to " << degrees_c << " in celcius." << endl;
			}

		else if (convert == 3)
			{
			GalToLit();
			}
		else if (convert == 4)
			{
			poundsToKg();
			}
		cout << "Make another selection: ";
		cin >> convert;
		}
		
	return 0;
}


void poundsToKg()
{
float pounds, kilograms;
cout << "Input the number of pounds to convert to kilograms: ";
cin >> pounds;
kilograms = pounds * 0.45;
cout << pounds << " pounds is equal to " << kilograms << " in kilograms.\n";
}