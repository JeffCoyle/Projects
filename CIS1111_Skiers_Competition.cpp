//Nathan Dotson
//4-15-2016
//Skiers Competition
//This program will determine the fastest skier, calculate the average time, 
//find the time of the skier, display the skiers and their times
//The program will display the fastest skier, average times, and the skiers times.

#include <iostream>				
#include <string>			//string headerfile for names
#include <iomanip>			//setprecision

using namespace std;
//functions
double FastSkier(double[], string[], int);     //fastest skier
double AvgTime(double[], int);                  //finding Average
int SpecTime(double[], string[], int);          //finding the time of the name entered
int NameAndTime(double[], string[], int);        //list Skiers and their times

int main()
{
	const int Size = 5.0;															//size of arrays
	double time[Size] = { 2.03, 2.40, 1.85, 1.90, 2.50 };							//array for times
	string name[Size] = { "Leela", "Sarah", "Anna", "Keesha", "Heidi" };			//array for names									
	int select;

	for (int count = 1;; count++)
	{
		//Menu
		cout << "Enter 1 to find the fastest Skier";
		cout << "\nEnter 2 for the average time of the Skiers";
		cout << "\nEnter 3 to find the time of a specific Skier";
		cout << "\nEnter 4 to display all Skiers and their times" << endl;
		cout << "To exit enter any other number" << endl;
		cout << "\n";
		cin >> select;

		switch (select)
		{
		case 1:

			FastSkier(time, name, Size - 1);
			break;
		case 2:

			AvgTime(time, Size);
			break;
		case 3:

			SpecTime(time, name, Size - 1);
			break;
		case 4:
			
			NameAndTime(time, name, Size - 1);
			break;
		}
	}

	system("pause");
	return 0;
}



double FastSkier(double time[], string name[], int Size)
{
	int Loc;											//location of data in array, value determined by for-loop
	int index;											
	double fastest = time[0];							//variable to find fastest time for Skier, initialized at first value of time
	for (Loc = 0; Loc < Size; Loc++)					//cycles through all values of time comparing each one to find the lowest value
	{
		if (time[Loc] < fastest)
			fastest = time[Loc];
			index = Loc;
	}
	cout << "The fastest Skier is " << name[index - 1] << " with a time of " << time[index - 1] << endl;
	cout << endl;

	return 0;
}


double AvgTime(double time[], int Size)
{
	int Loc;												//location of data within array, acts as a counter in this function 
	double Avg;												//Average vairiable
	double sum = 0;											 //sum of all values within time[]

	for (Loc = 0; Loc < Size; Loc++)
		sum += time[Loc];
	Avg = sum / Size;

	cout << "The average time for Skiers is " << fixed << setprecision(3) << Avg << endl;
	cout << "\n";
	return 0;
}


int SpecTime(double time[], string name[], int Size)
{
	string Skier;
	cout << "Skiers \n";
	cout << "    " << name[0] << endl;
	cout << "    " << name[1] << endl;
	cout << "    " << name[2] << endl;
	cout << "    " << name[3] << endl;
	cout << "    " << name[4] << endl;

	cout << "Enter the name of the Skier to find their time \n";
	cin >> Skier;
	
	
	for (int count = 0; count < Size; count++)
		if (Skier == name[count])
		{
			cout << Skier << " has the time " << time[count] << endl;
			break;
		}
		else if (Skier != name[count])
		{
			cout << "The name you entered is not a current competitor in this competition \n";
			cout << "Please enter a name from the list \n";
			cin >> Skier;
			break;
		}
	
	return 0;
}


int NameAndTime(double time[], string name[], int Size)
{
	cout << fixed << setprecision(2) << endl;
	cout << endl;
	cout << "Skiers and there times" << endl;
	cout << name[0] << "           " << time[0] << endl;
	cout << name[1] << "           " << time[1] << endl;
	cout << name[2] << "           " << time[2] << endl;
	cout << name[3] << "           " << time[3] << endl;
	cout << name[4] << "           " << time[4] << endl;
	return 0;
}