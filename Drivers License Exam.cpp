/*Jeff Coyle	
12/10/2018
CIS 1111 - Final Project
Driver's License Exam */

#include <iostream>
#include <fstream>
#include <string>

using namespace std;
// ######################## 1   2    3    4    5    6    7     8    9    10   11   12   13   14   15   16   17   18   19   20
const char ANSWERS[20] = { 'A', 'D', 'B', 'B', 'C', 'B', 'A', 'B', 'C', 'D', 'A', 'C', 'D', 'B', 'D', 'C', 'C', 'A', 'D', 'B' };
void userAnswers(string);
int main(){
	string fileName;
	char arAnswers[20];
	int a = 0, c = 0, answerNum[20];
	cout << "\nEnter file name to read from and write to (with extension): ";
	cin >> fileName;
//	userAnswers(fileName);
	ifstream fileIn;		//Used to read in from sequential data file. 
	fileIn.open(fileName);  //Honestly was having a lot of issues getting the sequential data to work on my laptop for some reason. Spent a few hours trying to figure it out. The registry on my laptop is a wreck and that may attribute to it.
	if (fileIn.is_open()){
		while (fileIn >> arAnswers[a]){
			a++;
		}
	}
	else
		cout << "\nERROR: Unable to locate file!";  //Validates whether or not file is found
	fileIn.close();
	a = 0;
	for (int b = 0; b < 20; b++){
		if (arAnswers[b] == ANSWERS[b]){
			answerNum[a] = b + 1;
			a++;
		}
		else
			c++;
	}//Outputs:
	if (a>14)cout << endl << "Congratulations, you passed the test!";
	else cout << endl << "Sorry you failed the test!";
	cout << "\ncorrect answers: " << a;
	cout << "\nTincorrect answers: " << c << endl << "Correct answers are: ";
	for (int b = 0; b < a; b++){ 
		cout << endl <<  answerNum[b] << endl;
	}
	system("pause");
	return 0;
}
void userAnswers(string fileName){
	char ans[20];
	ofstream fileOut; //Sends the output to file
	fileOut.open(fileName);
	for (int a = 0; a < 20; a++){
		if (fileOut.is_open()){
			cout << "\nEnter the answer for question #" << a + 1 << ": ";
			cin >> ans[a];
			while (ans[a] < 65 || ans[a] > 68){  //Answers validations
				cout << endl << "ERROR: Wrong Answer! \nTry Again!";
				cout << "\nEnter the answer for question #" << a << ": ";
				cin >> ans[a];
			}
			fileOut << ans[a]<<" ";
		}
	} 
}
