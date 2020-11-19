#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>
#include <math.h>
using namespace std;

int length(char *str)
{
    if (str[0] == '\0')
    {
        return 0;
    }
    return 1 + length(str + 1);
}

// TO REMOVE A PARTICULAR LETTER FROM A STRING

void remove_char(char *str, char letter)
{
    if (str[0] == '\0')
    {
        return;
    }
    if (str[0] != letter)
    {
        remove_char(str + 1, letter);
    }
    else
    {
        int i = 1;
        for (; str[i] != '\0'; i++)
        {
            str[i - 1] = str[i];
        }
        str[i - 1] = str[i]; // FOR COPYING THE NULL CHARACTER TO JUST A POSITION BEFORE
        remove_char(str, letter);
    }
}

int main()
{

    char arr[1000], letter;
    cout << "Enter a string: " << endl;
    cin >> arr;
    cout << "Enter the letter you want to remove from the string: " << endl;
    cin >> letter;
    cout << "The length of the string before removing the letter: " << length(arr) << endl;
    remove_char(arr, letter);
    cout << "The new string after the removal of the letter: " << arr << endl;
    cout << "The length of the string after removing the letter " << length(arr) << endl;
}
