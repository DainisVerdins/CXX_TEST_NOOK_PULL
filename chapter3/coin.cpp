// hello_world.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
inline void keepwindow_open() { char ch; cin >> ch; }

int main()
{
    int one_coin_val = 0;
    int five_coin_val = 0;
    int ten_coin_val = 0;
    int twentyfive_coin_val = 0;
    int fifty_coin_val = 0;

    cout << "enter one_coin_val " << endl;
        cin >> one_coin_val;
    cout << "enter five_coin_val " << endl;
    cin >> five_coin_val;
    cout << "enter ten_coin_val " << endl;
    cin >> ten_coin_val;
    cout << "enter twentyfive_coin_val " << endl;
    cin >> twentyfive_coin_val;
    cout << "enter fifty_coin_val " << endl;
    cin >> fifty_coin_val;

    cout << "You have one_coin_val "<< one_coin_val <<" coins"<<endl;
    cout << "You have  five_coin_val "<< five_coin_val <<" coins" << endl;
    cout << "You have ten_coin_val "<< ten_coin_val <<" coins" << endl;
    cout << "You have twentyfive_coin_val "<< twentyfive_coin_val <<" coins" << endl;
    cout << "You have fifty_coin_val "<< fifty_coin_val <<" coins" << endl;
    double sum = (double)one_coin_val*1+five_coin_val*5+(double)ten_coin_val*10+(double)twentyfive_coin_val*25+ (double)fifty_coin_val*50;
    cout << "Total amount is "<<sum/100<<" dolars"<<endl;
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
