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
    char friend_sex = 0;
    int reciever_age = 0;
    cout << "Enter reciever adress\n";
    string first_name;
    cin >> first_name;
    cout << "Enter reciever age\n";
    cin >> reciever_age;
    if (reciever_age <= 0 || reciever_age >= 110) {
        cout << "You are joking!\n";
    }
    cout << "Enter another friend\n";
    string friend_name = "John Doe";
    cin >> friend_name;
    cout << "Please enter m - if he is a male or f if woman\n";
    cin >> friend_sex;
    cout << "Dear " << first_name << ",\n";
    cout << "How are you? ";
    cout << "I am in lifes tourmoil ";
    cout << "I missing you. ";
    cout << "Have you seen " << friend_name << "? ";
    if (friend_sex == 'm') {
        cout << "If you see "<< friend_name<<" please say him to call me ";
    }
    if (friend_sex=='f') {
        cout << "If you see " << friend_name << " please say her to call me ";
    }
    cout << "\nI hear you have just otmetil birthday and now you have " << reciever_age << " old! ";
    if (reciever_age < 12) {
        cout << " On next year you will be " << reciever_age + 1 << " let ";
    }
    else if (reciever_age==18) {
        cout << "On next year you can vote. ";
    }
    else if(reciever_age>60){
        cout << "How it is on pension huh? ";
    }
    else {
        
    }
    cout << "\n Sincirerly yours, \n\n Dainis ";
    return 0;
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
