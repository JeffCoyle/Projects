/* Jeff Coyle
CIS 1111
10/10/17
Mid term Project
*/

/* This program collects data from the user then calculates said data through the
Henderson Hasslebach equation with an added variable for activity level. It differentiates
between male and female to determine which version to use. Anything other than male will trigger female.*/

// Pre-processor directives
#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
using namespace std;

//Initiate Main Function
int main()
{
	//Declare variables which values require input from user.(height and weight in lbs)
	int height;
	int weight;
	int age;
	string name;
	char sex;
	char activity;

	//Promt the user to enter values, store values in memory.
	cout << "Hello.Today we will calculate your caloric intake needs based on a few questions first, what is your name?  ";
	getline(cin, name);
	cout << "How tall are you, in inches  :";
	cin >> height;
	cout << "How much do you currently weigh in pounds  :";
	cin >> weight;
	cout << "How old are you, in years? :";
	cin >> age;
	cout << "How active are you? (N)one? (L)ight? (M)oderate? (H)eavy? (Only type first letter or it will not work)  :";
	cin >> activity;
	cout << "Are you male or female :";
	cin >> sex;

	//Use declared variables to set up logarithmic equations,
	//assigns values to a variable and stores the value in memory
	//Uses the Hinderson Hasslebach equation with an added variable for activity level
	int bmr;
	if (sex == 'm' || sex == 'M') {
		bmr = (88.3 + (13.4 * (weight / 2.2)) + (4.8 * (height / .39)) - (5.7 * age)); // activity here is not implemented fully. goodluck
	}
	else {
		bmr = (88.3 + (9.2 * (weight / 2.2)) + (3.1 * (height / .39)) - (4.3 * age));
	}

	if (activity == 'N' || activity == 'n')
		bmr *= 1.2;
	else if (activity == 'L' || activity == 'l')
		bmr *= 1.375;
	else if (activity == 'M' || activity == 'm')
		bmr *= 1.55;
	else if (activity == 'H' || activity == 'h')
		bmr *= 1.75;

	//Print Event details and calculations
	cout << "___________" << " Hello " << name << " Here are some healthy guidelines to help you meet any weight goals you may have." << "_____________" << endl;
	cout << "_________________________________________" << "Your Adjusted Basal Metabolic Rate is " << bmr << "____________________________________" << endl;
	cout << "Gain weight at a healthy rate-  " << bmr * 1.1 << " Calories Daily " << endl;
	cout << "_______________________________|" << endl;
	cout << "_______________________________|" << (bmr * 1.1) * .5 << "Calories should come from carbs" << endl;
	cout << "_______________________________|" << (bmr * 1.1) * .333334 << "Calories should come from protien" << endl;
	cout << "_______________________________|" << (bmr * 1.1) * .166667 << "Calories should come from fats" << endl;
	cout << "____________________________________________________________________________________________________" << endl;
	cout << "Maintain weight-                " << bmr << " Calories Daily " << endl;
	cout << "_______________________________|" << endl;
	cout << "_______________________________|" << bmr * .5 << "Calories should come from carbs" << endl;
	cout << "_______________________________|" << bmr * .333334 << "Calories should come from protien" << endl;
	cout << "_______________________________|" << bmr * .166667 << "Calories should come from fats" << endl;
	cout << "____________________________________________________________________________________________________" << endl;
	cout << "Lose weight at a healthy rate-  " << bmr * .9 << " Calories Daily to lose weight at a healthy rate, " << endl;
	cout << "_______________________________|" << endl;
	cout << "_______________________________|" << (bmr * .9) * .5 << "Calories should come from carbs" << endl;
	cout << "_______________________________|" << (bmr * .9) * .333334 << "Calories should come from protien" << endl;
	cout << "_______________________________|" << (bmr * .9) * .166667 << "Calories should come from fats" << endl;
	cout << "____________________________________________________________________________________________________" << endl;

	//Freezes the screen and waits for further input from user to close program
	system("pause");
	return 0;


}