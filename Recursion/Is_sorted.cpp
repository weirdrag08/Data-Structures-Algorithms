#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>
#include <math.h>
using namespace std;

// TO CHECK WHETHER A GIVEN ARRAY IS SORTED OR NOT

bool check_sorted_array(int *arr, int size)
{
    if (size == 0 || size == 1)
    {
        return true;
    }
    if (arr[0] > arr[1])
    {
        return false;
    }
    bool sorted = check_sorted_array(arr + 1, size - 1);

    return sorted;
}

int main()
{

    int arr[1000];
    int size;
    cout << "Enter the size of the array: " << endl;
    cin >> size;
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
    bool is_sorted = check_sorted_array(arr, size);
    if (is_sorted)
    {
        cout << "The array is sorted: " << is_sorted << endl;
    }
    else
    {
        cout << "The array is not sorted: " << is_sorted << endl;
    }
}
