#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>
#include <math.h>
using namespace std;

//  TO FIND THE LAST INDEX OF A GIVEN NUMBER---------->(RECURSION TRAVERSING THE ARRAY FROM LEFT TO RIGHT)

int last_index(int *arr, int size, int number)
{
    if (size == 0)
    {
        return -1;
    }
    int small_array_check = last_index(arr + 1, size - 1, number);
    if (small_array_check == -1)
    {
        if (arr[0] == number)
        {
            return 0;
        }
        return -1;
    }
    return 1 + small_array_check;
}

// TO FIND THE LAST INDEX OF A NUMBER----------------->(RECURSION TRAVERSING THE ARRAY FROM RIGHT TO LEFT)-------------> VERY IMPORTANT

int last_index_right_to_left(int *arr, int size, int number)
{
    if (size == 0)
    {
        return -1;
    }
    if (arr[size - 1] == number)
    {
        return size - 1;
    }
    int small_array_check = last_index_right_to_left(arr, size - 1, number);
    if (small_array_check == -1)
    {
        return -1;
    }
    return small_array_check; // NOTICE WE DIDN'T DO ANY (+ or -) IN THIS CASE, AS THE ARRAY WAS PASSED FROM THE BEGINNING AND HENCE NUMBERING REMAINED THE SAME
}

int main()
{

       int arr[1000], size, number;
       cout << "Enter the size of the array: " << endl;
       cin >> size;
       cout << "Enter " << size << " elements in the array: " << endl;
       for(int i = 0; i < size; i++){
           cin >> arr[i];
       }
       cout << "Enter the number whose last index you want to search for: " << endl;
       cin >> number;
       cout << "The last index of " << number << " in the given array: " << last_index(arr,size,number) << endl;
}