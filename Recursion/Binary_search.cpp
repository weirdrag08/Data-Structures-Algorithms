#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>
#include <math.h>
using namespace std;

// BINARY SEARCH USING RECURSION

int binary_Search(int *arr, int start, int end, int element)
{
    if (start > end)
    {
        return -1;
    }
    int mid = (start + end) / 2;

    if (arr[mid] == element)
    {
        return mid;
    }
    if (arr[mid] < element)
    {
        int right_find = -1;
        right_find = binary_Search(arr, mid + 1, end, element);
        if (right_find != -1)
        {
            return right_find;
        }
    }
    else
    {
        int left_find = -1;
        left_find = binary_Search(arr, start, mid - 1, element);
        if (left_find != -1)
        {
            return left_find;
        }
    }
    return -1;
}

int main()
{

    int arr[1000], size, start, end, element;
    cout << "Enter the size of the array: " << endl;
    cin >> size;
    cout << "Enter " << size << " elements in the array: " << endl;
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
    cout << "Enter the element you want to search for in the array: " << endl;
    cin >> element;
    start = 0;
    end = size - 1;
    int index = binary_Search(arr, start, end, element);
    cout << "The index of the element in the given array: " << index << endl;
}
