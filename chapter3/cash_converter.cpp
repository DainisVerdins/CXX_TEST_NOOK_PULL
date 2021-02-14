// hello_world.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
inline void keepwindow_open() { char ch; cin >> ch; }

int main()
{
	double dollar_to_yen_koef = 104.96;
	double dollar_to_euro_koef = 0.98;
	double dollar_to_pound_koef = 0.72;
	double Krone_to_yen_koef = 17.105;


	double amount_of_cash = 0;
	char output_currency = ' ';
	char input_currency = ' ';
	cout << "Please input cash, input type of valuta(k or d)  and output currency(y,e,p)" << endl;
	cin >> amount_of_cash >> input_currency>>output_currency;
	
	//for crons 
	if (input_currency=='k')
	{
		switch (output_currency)
		{
		case 'y':
			cout << "kron into yen is " << amount_of_cash * Krone_to_yen_koef << endl;
			break;
		default:
			cout << "I do not know" << endl;
			break;
		}
	}
	else {
		//for dollars 
		switch (output_currency)
		{
		case 'y':
			cout << amount_of_cash * dollar_to_yen_koef << output_currency << endl;
			break;
		case 'e':
			cout << amount_of_cash * dollar_to_euro_koef << output_currency << endl;
			break;
		case 'p':
			cout << amount_of_cash * dollar_to_pound_koef << output_currency << endl;
			break;
		default:
			cout << "I do not know" << endl;
			break;
		}
	}
	//cout << "";
	return 0;
	//TODO need to make smoother output
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
