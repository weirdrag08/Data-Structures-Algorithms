#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>
#include <math.h>
using namespace std;

// PRINT THE SUBSEQUENCES OF A GIVEN STRING

void print_subsequences(string input, string output)
{
    if (input.size() == 0)
    {
        cout << output << endl;
        return;
    }
    print_subsequences(input.substr(1), output);
    print_subsequences(input.substr(1), output + input[0]);
}

int main(){

           string str;
           string output = "";
           cout << "Enter a string: " << endl;
           cin >> str;
       print_subsequences(str, output);
}