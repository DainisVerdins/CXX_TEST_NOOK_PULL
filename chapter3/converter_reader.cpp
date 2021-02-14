// hello_world.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
inline void keepwindow_open() { char ch; cin >> ch; }


int smalles_num(int a, int b) {
	if (a <= b == true)return a;
	else {
		return  b;
	}
}
bool is_correct_metric(string metric) {

	if (metric == "cm" || metric == "in" || metric == "ft" || metric == "m") {
		return true;
	}
	else {
		return false;
	}
}

double convert_into_metrix(double val, string metric) {
	double meter_into_cm = 100;
	double inch_into_cm = 2.54;
	double ft_into_in = 12;

	if (metric == "cm") {
		return val/meter_into_cm;
	}
	else if (metric == "in" ) {
		return (val * inch_into_cm) / meter_into_cm;
	}
	else if (metric == "ft") {
		return (val * ft_into_in * inch_into_cm) / meter_into_cm;
	}
	else if (metric == "m") {
		return val;
	}
	else {
		return -1.0;
	}
	
}
void show_sum_of_vector(const vector<double> vec) {

	double sum_of_vector = 0;
	for (size_t i = 0; i < vec.size(); i++)
	{
		sum_of_vector += vec[i];
	}
	cout << "SUMEC " << sum_of_vector << endl;
}

void show_vector(const vector<double> vec) {
	for (size_t i = 0; i < vec.size(); i++)
	{
		cout << vec[i]<<" ";
	}
	cout << endl;
}

int main()
{
	char out_of_loop = ' ';
	double a = 0, b = 0;
	double eps = 1.0 / 10000000;
	double smallest_num = 0;
	double biggest_num = 0;
	double input_num = 0;
	string input_metrics = " ";
	vector<double> values;



	while (1) {
		cout << "Out of programme then pres | otherwise anykay to continue:";
		cin >> out_of_loop;
		if (out_of_loop == '|') {
			cout << "Biggest from inputed nums " << biggest_num << endl;
			cout << "smalest  from inputed nums " << smallest_num << endl;
			cout << "num count " << values.size() << endl;
			sort(values.begin(), values.end());
			show_sum_of_vector(values);
			show_vector(values);
			break;
		}
		cout << " length and metrics identificator(cm,in,ft,m) " << endl;
		cin >> input_num>>input_metrics;
		if (is_correct_metric(input_metrics)) {
			
			input_num = convert_into_metrix(input_num, input_metrics);
			values.push_back(input_num);
			
			if (input_num > biggest_num) {
				biggest_num = input_num;
			}
			else if (input_num < smallest_num || smallest_num == 0) {
				smallest_num = input_num;
			}
		}
		else {
			cout << "I do not understand metrics!" << endl;
		}

	}

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
