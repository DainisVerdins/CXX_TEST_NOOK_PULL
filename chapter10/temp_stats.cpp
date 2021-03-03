



#include "std_lib_facilities.h"

struct Reading {
	int hour;//[0:23]
	double temperature;//farenheit
	Reading(int h,double t):hour(h),temperature(t){}
};



void get_data(ifstream& ist,  vector<Reading>& v) {

	int h = 0; double temperature = 0;
	while (ist>>h>>temperature)
	{
		if (ist.eof())
		{
			return;
		}
		v.push_back(Reading(h, temperature));
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
	if (i.temperature<j.temperature)
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
	if (v.size()==0)
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
	int n = 50;
	vector<Reading>temps;
	string output = "raw_temps.txt";
	ifstream ist(output);
	get_data(ist, temps);
	cout << temps.size() << endl;
	cout << "avarage temperature is "<<avarage_temperature(temps)<<" F" << endl;
	cout << "Median "<<get_median(temps) << endl;
	return 0;
};

