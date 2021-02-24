
int main(){
    
    return 0;
}


#include "std_lib_facilities.h"
//12
//------------------------------------------------------------------------------
/*
Hre must be discrabe of grammatics
*/
void print(const string& str, const vector<int> &numbers) {

	for (size_t i = 0; i < numbers.size(); i++)
	{
		cout <<str<<" "<<numbers.at(i);
		if ((i+1)==numbers.size())
		{
			cout << endl;
		}
	}

}

void fibonacci(int x, int y, vector<int> &v, int n) {
	v.push_back(x);
	v.push_back(y);
	
	int fib_add_count=n-2;//because two already was pushed

	for (size_t i = 0; i < fib_add_count; i++)//
	{
		v.push_back(v[0+i]+v[1+i]);
	}
}

void find_max_int() {

	int first_val = 0;
	int second_val = 1;

	int fib_val = 1;
	int fib_val_prev =0 ;
	while (fib_val>0)
	{
		fib_val_prev = fib_val;

		fib_val =  second_val+ first_val ;
		first_val = second_val;
		second_val = fib_val;

	}
	cout << fib_val << endl;
	cout << fib_val_prev << endl;
}


int main() {
	vector<int>fibonaci_num;
	fibonacci(2, 3, fibonaci_num, 5);
	print("", fibonaci_num);
	find_max_int();

	return 0;
}

//------------------------------------------------------------------------------