#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>
#include <math.h>
using namespace std;

// TO FIND THE FIRST INDEX OF A NUMBER IN AN ARRAY

int first_index(int *arr, int size, int number)
{
    if (size == 0)
    {
        return -1;
    }
    if (arr[0] == number)
    {
        return 0;
    }
    int small_array_check = first_index(arr + 1, size - 1, number);
    if (small_array_check == -1)
    {
        return -1;
    }
    else
    {
        return 1 + small_array_check;
    }
}

int main(){
       int arr[1000], size, number;
       cout << "Enter the size of the array: " << endl;
       cin >> size;
       cout << "Enter " << size << " elements in the array: " << endl;
       for(int i = 0; i < size; i++){
           cin >> arr[i];
       }
       cout << "Enter the number whose first index you want to search for: " << endl;
       cin >> number;
       cout << "The first index of " << number << " in the given array: " << first_index(arr, size, number) << endl;
}