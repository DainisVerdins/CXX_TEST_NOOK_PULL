



#include "std_lib_facilities.h"

struct Reading {
	int hour;//[0:23]
	double temperature;//farenheit
	Reading(int h,double t):hour(h),temperature(t){}
};

void insert_readings(vector<Reading> &v, int n) {

	int hour = 0;
	int temp = 0;
	int lowest_t = -459.97;//absolute zero
	int highest_t = 10000;//absolute max
	for (int i = 0; i < n; i++)
	{
		hour = rand() % 24;
		temp = rand() % highest_t + lowest_t;
		v.push_back(Reading(hour, temp));
	}
}

void input_temps( ofstream& ost, const vector<Reading>& v) {

		for (int i = 0; i < v.size(); ++i) {
			ost << v[i].hour << " " << v[i].temperature << '\n';
		}


	
}

int main()
{
	int n = 50;
	vector<Reading>temps;
	insert_readings(temps, n);
	cout << temps.size() << endl;

	string output = "raw_temps.txt";
	ofstream ost(output);
	input_temps(ost, temps);
	

	return 0;
};

