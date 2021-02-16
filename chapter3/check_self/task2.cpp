// hello_world.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
inline void keepwindow_open() { char ch; cin >> ch; }

double calc_sum_of_vector(const vector<double> vec) {

	double sum_of_vector = 0;
	for (size_t i = 0; i < vec.size(); i++)
	{
		sum_of_vector += vec[i];
	}
	return sum_of_vector;
}

void show_vector(const vector<double> vec) {
	for (size_t i = 0; i < vec.size(); i++)
	{
		cout << vec[i]<<" ";
	}
	cout << endl;
}
double biggest_distance_between(const vector<double> vec) {
	if (vec.empty())
	{
		return 0;
	}
	double distance_between=vec[0];
	double prev_city_dist = 0;
	for (size_t i = 1; i < vec.size(); i++)
	{
		if (distance_between < abs(vec[i - 1] - vec[i])) {
			distance_between = abs(vec[i - 1] - vec[i]);
		}
	}

	return distance_between;
}

double smallest_distance_between(const vector<double> vec) {
	if (vec.empty())
	{
		return 0;
	}
	double distance_between = vec[0];
	for (size_t i = 1; i < vec.size(); i++)
	{
		if (distance_between > abs(vec[i - 1] - vec[i])) {
			distance_between = abs(vec[i - 1] - vec[i]);
		}
	}

	return distance_between;
}


int main()
{
	vector<double> distances = {0.5,3.0};
	double distance = 0;
	double sum_distaance = 0;
	/*while (cin >> distance) {
		distances.push_back(distance);
	}*/
	sum_distaance = calc_sum_of_vector(distances);
	cout << "sum of distance is " << sum_distaance << endl;
	cout << "biggest distance " << biggest_distance_between(distances) << endl;
	cout << "smallest distance " << smallest_distance_between(distances) << endl;
	
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
