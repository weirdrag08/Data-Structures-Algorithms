#include<iostream>
using namespace std;

// TO CALCULATE FACTORIAL OF A NUMBER

int factorial(int number){
    if(number == 1){
        return 1;
    }
    return (number * factorial(number - 1));
}

int main(){
    int number;
    cout << "Enter a number for which you want to calculate factorial for: " << endl;
    cin >> number;
    cout << "The factorial of the given number: " << factorial(number) << endl;
}