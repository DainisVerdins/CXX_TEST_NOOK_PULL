// hello_world.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
inline void keepwindow_open() { char ch; cin >> ch; }

bool is_prime(int n) {
	vector<int>primes = { 2,3,5,7 };
	for (auto prime : primes) {
		if (prime == n) {
			return true;
		}
		else if (n % prime == 0)return false;
	}
	return true;
}

void primesn(int n) {
	vector<int>primes = { 2,3,5,7 };

	int ouputed_count = 0;
	int num = 2;
	while (ouputed_count <= n)
	{
		if (is_prime(num))
		{
			cout << num << " ";
			++ouputed_count;
		}
		++num;
	}
}

void estafor(int n) {
	vector<bool>A(n + 1, true);
	for (size_t i = 2; (i * i) <= n; i++)
	{
		if (A[i] == true) {
			for (size_t j = (i * i); j <= n; j += i)
			{
				A[j] = false;
			}
		}
	}
	for (size_t i = 2; i <= n; i++)
	{
		if (A[i]) {
			cout << i << " ";
		}

	}
}


int main()
{
	int rice = 100;
	//estafor(rice);
	cout << endl;
	primesn(30);
	return 0;
	//TODO need to make smoother output
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
