


#include "std_lib_facilities.h"

class Name_pairs {
public:
	void read_names();
	void read_ages();
	void print();
	void sort_pairs();


	vector<string> name;
	vector<double> age;
	//bool mycomp(const string& a, const string& b);
};

ostream& operator <<(ostream& os, const Name_pairs& nm) {
	string output;
	//loop names until end or until have ended age vector
	for (int i = 0; i < nm.name.size() && i != nm.age.size(); i++)
	{
		output+= "("+nm.name.at(i) +"," + to_string(nm.age.at(i)) + ")\n" ;
	}

	return os << output;
}

int main()
{
	try
	{
		Name_pairs t;
		t.read_names();
		t.read_ages();
		t.print();
		t.sort_pairs();
		//t.print();
		cout << t;
	}
	catch (const std::exception& e)
	{
		cout << e.what() << endl;
	}
	catch (...) {
		cout << "hz" << endl;
	}

	return 0;
};

void Name_pairs::read_names()
{
	string input_name;
	cout << "insert names or write  'DONE' and enter to get out" << endl;
	while (cin >> input_name)
	{
		if (input_name == "DONE")
		{
			break;
		}
		name.push_back(input_name);
	}
}

void Name_pairs::read_ages()
//reads ages from users prompt
{
	double inputed_age = 0;
	for (size_t i = 0; i < name.size(); i++)
	{
		cout << "Enter age of this person " << name[i] << ":";
		cin >> inputed_age;
		if (!cin)
		{
			string k("at this name: '" + name[i] + "' coused error ");
			error(k,"in read ages wrong input type");
		}
		age.push_back(inputed_age);
	}
}

void Name_pairs::print()
{
	//loop names until end or until have ended age vector
	for (int i = 0; i < name.size() && i != age.size(); i++)
	{
		cout << "(" << name.at(i) << "," << age.at(i) << ")" << endl;
	}


}

void Name_pairs::sort_pairs()
//sorts name vector into alphabetecaly
{
	//actualy very bad sorting, coping vector brrr
	//out of memory easy
	vector<string> temp_names = name;
	vector<double> sort_ages;
	std::sort(name.begin(),name.end());

	for (string &n : name)
		for (int i = 0; i < temp_names.size(); ++i)
			if (temp_names[i] == n)
				sort_ages.push_back(age[i]);

	age = sort_ages;

}


