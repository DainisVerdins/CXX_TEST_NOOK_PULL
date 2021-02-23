
//
// This is example code from Chapter 6.7 "Trying the second version" of
// "Software - Principles and Practice using C++" by Bjarne Stroustrup
//

/*
	This file is known as calculator02buggy.cpp

	I have inserted 5 errors that should cause this not to compile
	I have inserted 3 logic errors that should cause the program to give wrong results

	First try to find an remove the bugs without looking in the book.
	If that gets tedious, compare the code to that in the book (or posted source code)

	Happy hunting!

*/

#include "std_lib_facilities.h"
//12
//------------------------------------------------------------------------------
 

int factorial(int n) {
	if (n == 0)return 1;
	int output = 1;

	while (n!=0) {
		output *= n;
		--n;
	}
	return output;
}

int perestanovka(int a, int b) {
	return(factorial(a) / factorial(a-b));
}

int combinacija(int a, int b) {
	return perestanovka(a, b) / factorial(b);
}

int main() {
	try
	{
		int a = 0;
		int b = 0;
		int output = 0;
		cout << "Please enter two numbers for calculations" << endl;
		cin >> a >> b;
		if (a == 0 || b == 0) { error("bad inputs they must be integers and positive"); }
		//here must be num check
		if (b>a)
		{
			error("rigth number must be same size as left or smaller!");
		}
		char chose = ' ';
		cout << "Please chose what to calc Perestanovka 'p' or Kombinacii 'c' or 'q' for exit" << endl;
		cin >> chose;
		if (chose == 'q') { return 0; }
		else if (chose == 'p')
		{
			output = perestanovka(a, b);

		}
		else if (chose == 'c') {
			output = combinacija(a, b);

		}
		else {
			error("i do not understand what chose! QUIT");
		}
		cout<<"Result is "<<output<<endl;
	}
	catch (const std::exception& e) 
	{
		cout << e.what() << endl;
	}
	
	
}

//------------------------------------------------------------------------------