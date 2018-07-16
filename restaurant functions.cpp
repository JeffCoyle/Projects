//Jeff Coyle
// 11/4/2017
//Resteraunt functions */

#include <iostream>
#include <iomanip>

using namespace std;

const double HAMBURGER = 6, HOTDOGS = 4.5, PEANUTS = 3.75, POPCORN = 5.5, SODA = 2.8, CHIPS = 1, WATER = 2, TAX=.065, TIP=.2;

void menu();  //Menu items
void billComponents(double bill, double &totalBill, double &tax, double &tip); //Gives total bill 
void changeDue(double totalBill, double &amntTendered); // Gives the change due

int main(){
	int choice;
	double totalBill, total=0, taxAmount, tipAmount, pay, due;
	cout << setprecision(2) << fixed;
	menu();
	cout << endl << endl << "Enter the item number: ";
	cin >> choice;
	while (choice != 8){
		switch (choice){
		case 1: total += HAMBURGER;
			break;
		case 2: total += HOTDOGS;
			break;
		case 3: total += PEANUTS;
			break;
		case 4: total += POPCORN;
			break;
		case 5: total += SODA;
			break;
		case 6: total += CHIPS;
			break;
		case 7: total += WATER;
			break;
		default: cout << "Enter a valid item. \n";
			menu();
			cout << endl << endl << "Enter the item number: ";
			cin >> choice;
			break;
		}
		menu();
		cout << endl << endl << "Enter the item number: ";
		cin >> choice;
	}
	billComponents(total, totalBill, taxAmount, tipAmount);
	cout << endl << "\t\t<<==-Invoice-==>> \n";
	cout << endl << "Food cost:   $" << total;
	cout << endl << "Tax amount:  $" << taxAmount;
	cout << endl << "Tip amount:  $" << tipAmount;
	cout << endl << "Total Amout: $" << totalBill;
	cout << endl << endl << "Enter payment amount: ";
	cin >> pay;
	while (pay < totalBill){
		cout << endl <<  "ERROR: Payment cannot be less than total bill: "<<totalBill<<"\n Enter payment amount: ";
		cin >> pay;
	}
	due = pay;
	changeDue(totalBill, due);
	cout << "\nAmout paid: $" << pay << " \nAmout returned: $" << due << endl;
	system("pause");
	return 0;
}

void menu(){
	cout << "Enter choices from the menu below: ";
	cout << "\n1. Hamburger   $" << HAMBURGER;
	cout << "\n2. Hotdog      $" << HOTDOGS;
	cout << "\n3. Peanuts     $" << PEANUTS;
	cout << "\n4. Popcorn     $" << POPCORN;
	cout << "\n5. Soda        $" << SODA;
	cout << "\n6. Chips       $" << CHIPS;
	cout << "\n7. Water       $" << WATER;
	cout << "\n8. End Order";
}
void billComponents(double bill, double &totalBill, double &tax, double &tip){
	
	tip = bill*TIP;
	tax = bill*TAX;
	totalBill = bill+tax+tip;
}
void changeDue(double totalBill, double &amntTendered){
	amntTendered -= totalBill;
}