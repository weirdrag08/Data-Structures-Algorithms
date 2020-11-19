#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>
#include <math.h>
using namespace std;

// CONVERTING A STRING TO INTEGER

int string_to_integer(string s)
{

    if (s.size() == 1)
    {
        int integer = s[0] - '0';
        return integer;
    }
    int size = (s.substr(1)).size();
    int small_integer = string_to_integer(s.substr(1));
    int first_digit = s[0] - '0';
    return first_digit * pow(10, size) + small_integer;
}

int main()
{
    string num_string;
    cout << "Enter the string which you want to convert into a number: " << endl;
    cin >> num_string;
    int number = string_to_integer(num_string);
    cout << "The number is outputed as: " << number << endl;
}
