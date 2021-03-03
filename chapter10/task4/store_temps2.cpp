



#include "std_lib_facilities.h"

struct Reading {
	int hour;//[0:23]
	double temperature;//farenheit
	Reading(int h, double t) :hour(h), temperature(t) {}
};

void insert_readings(vector<Reading>& v, int n) {
	
	double lower_bound = -459.97;//absolute zero
	double upper_bound = 10000;//absolute max
	std::uniform_real_distribution<double> unif(lower_bound, upper_bound);
	std::default_random_engine re;
	
	int hour = 0;
	double temp = 0;
	for (int i = 0; i < n; i++)
	{
		hour = rand() % 24;//in day you have 24 hours
		temp = unif(re);
		v.push_back(Reading(hour, temp));
	}
}

void input_temps(ofstream& ost, const vector<Reading>& v) {
	char temperature_sufix=0;
	char temp_chose = 1;//first one stands for farencheit
	int number_of_temp_signs = 2;//celsius ,farenheit
	for (int i = 0; i < v.size(); ++i) {
		temp_chose = rand() % number_of_temp_signs;
		
		if (temp_chose ==0)
		{
			temperature_sufix = 'f';//farenheit
		}
		else{
			temperature_sufix = 'c';//celsius
		}

		ost << v[i].hour << " " << v[i].temperature << temperature_sufix << '\n';
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

