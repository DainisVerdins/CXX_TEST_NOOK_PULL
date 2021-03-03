



#include "std_lib_facilities.h"

struct Reading {
	int hour;//[0:23]
	double temperature;//farenheit
	Reading(int h, double t) :hour(h), temperature(t) {}
};


double celsius_to_faren(double temperature)
//converts temperature in celsius to farenheit
{
	//formula is celsius * 1.8 +32
	const double times_bigger = 1.8;
	const double celsius_zero_in_farenheit = 32;
	return (temperature * times_bigger) + celsius_zero_in_farenheit;
}


void get_data(ifstream& ist, vector<Reading>& v) {

	int h = 0; string temperature;
	while (ist >> h >> temperature)
	{
		if (ist.eof())
		{
			return;
		}
		//get last sign of temperature string where is prefix of what scale of temp it is
		switch (temperature.back())
		{
		case 'f':
			temperature.pop_back();//get out from temperature sign
			v.push_back(Reading(h, stod(temperature)));
			break;
		case 'c':
			temperature.pop_back();//get out from temperature sign
			v.push_back(Reading(h, celsius_to_faren(stod(temperature))));
			break;
		default:
			error("unrecognized temperature scale sign in this row ", temperature);
			break;
		}

	}
}

double avarage_temperature(const  vector<Reading>& v) {
	if (v.size() == 0)
	{
		return 0;
	}
	double avg = 0;
	for (auto& elem : v) {
		avg += elem.temperature;
	}
	return avg / v.size();
}

bool how_to_sort(const Reading& i, const Reading& j) {
	if (i.temperature < j.temperature)
	{
		return true;
	}
	else {
		return false;
	}
}

double get_median(vector<Reading>& v)
//sorts vector
{
	if (v.size() == 0)
	{
		return 0;
	}
	sort(v.begin(), v.end(), how_to_sort);

	double midle_index = v.size() / 2;

	//check if midle index is integer. means what get exatly match of median
	if (midle_index != int(midle_index)) {
		int i = int(midle_index);
		//get value from pointed and one from left of it 
		return ((v[i - 1].temperature + v[i].temperature) / 2);
	}
	else {
		return v[midle_index].temperature;
	}

}
//sorts vector
int main()
{
	try
	{
		vector<Reading>temps;
		string output = "raw_temps.txt";
		ifstream ist(output);
		get_data(ist, temps);
		cout << temps.size() << endl;
		cout << "avarage temperature is " << avarage_temperature(temps) << " F" << endl;
		cout << "Median " << get_median(temps) << endl;
	}
	catch (const std::exception& e)
	{
		cout << e.what() << endl;
	}
	
	return 0;
};

