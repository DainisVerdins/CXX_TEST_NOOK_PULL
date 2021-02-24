


#include "std_lib_facilities.h"
//12
//------------------------------------------------------------------------------
/*
Hre must be discrabe of grammatics
*/
void print(const string& str, const vector<int>& numbers) {

	for (size_t i = 0; i < numbers.size(); i++)
	{
		cout << str << " " << numbers.at(i);
		if ((i + 1) == numbers.size())
		{
			cout << endl;
		}
	}

}

void fibonacci(int x, int y, vector<int>& v, int n) {
	v.push_back(x);
	v.push_back(y);

	int fib_add_count = n - 2;//because two already was pushed

	for (size_t i = 0; i < fib_add_count; i++)//
	{
		v.push_back(v[0 + i] + v[1 + i]);
	}
}

void find_max_int() {

	int first_val = 0;
	int second_val = 1;

	int fib_val = 1;
	int fib_val_prev = 0;
	while (fib_val > 0)
	{
		fib_val_prev = fib_val;

		fib_val = second_val + first_val;
		first_val = second_val;
		second_val = fib_val;

	}
	cout << fib_val << endl;
	cout << fib_val_prev << endl;
}

void reverse_vec(vector<int>& vec) {

	int last_elem_index = vec.size() - 1;
	int  middle_of_vec = vec.size() / 2;
	for (int i = 0; i < middle_of_vec; i++)
	{
		if ((i-(last_elem_index - i))!=0)
		{
			swap(vec[i], vec[last_elem_index - i]);
		}
		
	}

}


void reverse_output(const vector<int>& source, vector<int>& output) 
//fills output vector from source with reverse sequence
{	
	if (source.empty())
	{
		error("reverse_vec : source is empty");//or maybe return
	}
	output.reserve(source.size());//make it as big as source

	int last_elem_index = source.size() - 1;
	for (int i = last_elem_index; i >= 0; --i)
	{
		output.push_back(source[i]);
	}
}


int main() {
	vector<int>fibonaci_num;
	fibonacci(2, 3, fibonaci_num, 4);
	print("", fibonaci_num);
	//find_max_int();

	vector<int> reverse_v;
	reverse_output(fibonaci_num, reverse_v);
	print("", reverse_v);
	reverse_vec(fibonaci_num);
	print("rev", fibonaci_num);
	return 0;
}

//------------------------------------------------------------------------------