// hello_world.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
inline void keepwindow_open() { char ch; cin >> ch; }


void find_roots(double a, double b, double c) {
	double D = pow(b,2)-4*a*c;
	double x1 = 0, x2 = 0;
	if (D < 0) {
		cout << "I do not exist!" << endl;
	}
	else if (D == 0) {
		x1 = -(b / (2 * a));
		cout << "one root " << x1 << endl;
	}
	else {
	
		x1 = (-b+sqrt(D)) / (2 * a);
		x2 = (-b - sqrt(D)) / (2 * a);
		cout << x1 << " " << x2 << endl;
	}
}


int main()
{
	find_roots(4, -12, 9);
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
