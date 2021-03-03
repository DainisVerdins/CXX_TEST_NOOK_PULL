



#include "std_lib_facilities.h"


void calc_file_val(istream& ist) {
	
	int i = 0;
	//only works if integers are inside text file
	//no double or other junk
	int sum = 0;
	while (ist >> i)
	{
		
		sum += i;
	}
	cout << sum << endl;
}



int main()
{
	
	string first_input="input1.txt";
	//cout << "ENter first input file name\n";
	//cin >> first_input;
	std::ifstream ist(first_input);
	if (!ist)
	{
		error("Can not open file ", first_input);
	}
	calc_file_val(ist);


	return 0;
};

