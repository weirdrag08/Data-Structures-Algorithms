#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>
#include <math.h>
using namespace std;

// FUNCTION TO GET THE Nth FIBONACCI NUMBER

int fibonacci_series(int n)
{
    if (n == 1)
    {
        return 0;
    }
    if (n == 2)
    {
        return 1;
    }
    int fibonacci_number;
    return fibonacci_number = fibonacci_series(n - 1) + fibonacci_series(n - 2);
}

int main()
{

    int nth_num;
    cout << "Enter the nth number which you want from fibonacci series: " << endl;
    cin >> nth_num;
    int fibonacci_number = fibonacci_series(nth_num);
    cout << "The " << nth_num << "th fibonacci number: "<<fibonacci_number << endl;
}
