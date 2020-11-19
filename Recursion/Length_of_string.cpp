#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>
#include <math.h>
using namespace std;

// TO FIND THE LENGTH OF A GIVEN STRING

int length(char *str)
{
    if (str[0] == '\0')
    {
        return 0;
    }
    return 1 + length(str + 1);
}

int main()
{

    char arr[1000];
    cout << "Enter a word whose length you want to find out: " << endl;
    cin >> arr;
    cout << "The length of the entered word: " << length(arr) << endl;
}
