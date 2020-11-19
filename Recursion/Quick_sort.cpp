#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>
#include <math.h>
using namespace std;

// PARTITION FUNCTION FOR QUICK SORT

int Partition(int arr[], int start, int end)
{
    // int pivot = arr[start];
    int count = 0;
    for (int i = start + 1; i <= end; i++)
    {
        if (arr[i] <= arr[start])
        {
            count++;
        }
    }
    int pos = start + count;
    int temp = arr[start];
    arr[start] = arr[pos];
    arr[pos] = temp;
    int pivot = arr[pos];
    int i = start;
    int j = end;
    for (; (i <= pos && j >= pos);)
    {
        if (arr[i] <= pivot)
        {
            i++;
        }
        else if (arr[j] > pivot)
        {
            j--;
        }
        else
        {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
            j--;
        }
    }
    return pos;
}
// QUICK SORT

void quick_sort(int *arr, int start, int end)
{
    if (start >= end)
    {
        return;
    }
    int pos = Partition(arr, start, end);
    quick_sort(arr, start, pos - 1);
    quick_sort(arr, pos + 1, end);
}

int main(){
       int arr[10000], size, start, end, modulus;
       cout << "Enter the size of the array: " << endl;
       cin >> size;
       cout << "Enter " << size << " elements in the array: " << endl;
       for(int i = 0; i < size; i++){
           cin >> arr[i];
       }
       start = 0;
       end = size - 1;
       quick_sort(arr, start, end);
       for(int i = 0; i < size; i++){
           cout << arr[i] << " ";
       }
       cout << endl;
}