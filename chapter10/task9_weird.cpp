



#include "std_lib_facilities.h"
#include <sstream> //maybe fix

int get_sum_of_ints(ifstream& ifs) {
	int sum=0;
	if (ifs.is_open())
	{
		int val = 0;
		std::string line;
		string tmp;
		while (std::getline(ifs, line))
		{
			std::stringstream ss(line);

			while (!ss.eof())
			{
				ss >>tmp;
				if (stringstream(tmp) >> val) {
					sum += val;
				}
			}
				
		}

		ifs.close();
	}

	return sum;
}

int main()
{
	try
	{
		string input_f="input1.txt";
		ifstream ifs(input_f);
		cout << get_sum_of_ints(ifs) << endl;
	}
	catch (const std::exception& e) {
		cout << e.what() << endl;
	}

	return 0;
};

