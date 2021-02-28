


#include "std_lib_facilities.h"
#include"timer.h"//time measurement

struct Reading {
	int hour;//[0:23]
	double temperature;//farenheit
	Reading(int h, double t) :hour(h), temperature(t) {}
};

void fill_vector(istream& ist, vector<int>& v, char terminator) {

	int i = 0;
	while (ist>>i)
	{
		v.push_back(i);
	}
	if (ist.eof())//end of file found
	{
		return;
	}
	ist.clear();
	char c;
	ist >> c;
	if (c!=terminator)//check if its terminator string
	{
		ist.unget();//need to call fail()
		ist.clear(ios_base::failbit);//set status fail()
	}
}

int main()
{
	cout << "Please enter number brtween 1 to 10\n";
	int n = 0;
	while (true)
	{
		cin >> n;
		if (cin)
		{
			if (1 <= n && n <= 10)break;
			cout << "sorry try again\n";
		}
		else if (cin.fail())//in case wrong input
		{
			cin.clear();
			cout << "Sorry not that number try again\n";//part to try again
			char ch;
			while (cin >> ch && !isdigit(ch));
			if (!cin)
			{
				error("no output");
			}
			cin.unget();
		}
		else {
			error("no inout");
		}
	}

	return 0;
};