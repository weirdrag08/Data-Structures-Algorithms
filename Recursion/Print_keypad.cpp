#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>
#include <math.h>
using namespace std;

// PRINT THE KEYPAD QUESTION

void print_keypad(string *arr, int number, string output)
{
    if (number == 0)
    {
        cout << output << endl;
        return;
    }
    int last_digit = number % 10;
    string last_digit_string = arr[last_digit];
    for (int i = 0; i < last_digit_string.size(); i++)
    {
        print_keypad(arr, number / 10, output + last_digit_string[i]);
    }
    return;
}

int main(){
    string arr[10000] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    string output = "";
    int number;
    cout << "Enter a number: " << endl;
    cin >> number;
    print_keypad(arr, number, output);
}