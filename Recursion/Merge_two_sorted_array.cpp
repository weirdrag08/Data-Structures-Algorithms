#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>
#include <math.h>
using namespace std;

// TO MERGE TWO SORTED ARRAY

int* merge_two_sorted_array(int *arr1, int *arr2, int start1, int end1, int start2, int end2)
{
    if (start1 > end1 || start2 > end2)
    {
        return NULL;
    }
    int size1 = end1 + 1, size2 = end2 + 1;
    int *arr = new int[size1 + size2];
    int i = 0, j = 0, k = 0;
    for (; (i < size1 && j < size2); k++)
    {
        if (arr1[i] < arr2[j])
        {
            arr[k] = arr1[i];
            i++;
        }
        else
        {
            arr[k] = arr2[j];
            j++;
        }
    }
    if (i >= size1)
    {
        for (int l = k; j < size2; l++)
        {
            arr[l] = arr2[j];
            j++;
        }
    }
    else if (j >= size2)
    {
        for (int l = k; i < size1; l++)
        {
            arr[l] = arr1[i];
            i++;
        }
    }
    return arr;
}

int main()
{

    int arr1[1000], arr2[1000], size1, size2, start1, start2, end1, end2;
    cout << "Enter the size of array1: " << endl;
    cin >> size1;
    cout << "Enter the size of array2: " << endl;
    cin >> size2;
    cout << "Enter " << size1 << " elements in array1: " << endl;
    for (int i = 0; i < size1; i++)
    {
        cin >> arr1[i];
    }
    cout << "Enter " << size2 << " elements in array2: " << endl;
    for (int i = 0; i < size2; i++)
    {
        cin >> arr2[i];
    }
    start1 = 0;
    start2 = 0;
    end1 = size1 - 1;
    end2 = size2 - 1;
    int *final_array = merge_two_sorted_array(arr1, arr2, start1, end1, start2, end2);
    for (int i = 0; i < (size1 + size2); i++)
    {
        cout << final_array[i] << " ";
    }
    cout << endl;
}
