#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>
#include <math.h>
using namespace std;
//  TO GENERATE RANDOM NUMBER
void random_number(int *arr, int size, int modulus)
{
    for (int i = 0; i < size; i++)
    {
        int num = (int) (rand() % modulus);
        arr[i] = num;
    }
}
// TO MERGE TWO ARRAYS(MERGE SORT PART)

void merge(int *arr, int start, int end)
{
    if (start >= end)
    {
        return;
    }
    int output[100000];
    int mid = (start + end) / 2;
    int i = start, j = mid + 1, c = start;
    for (; (i <= mid && j <= end); c++)
    {
        if (arr[i] < arr[j])
        {
            output[c] = arr[i];
            i++;
        }
        else
        {
            output[c] = arr[j];
            j++;
        }
    }

    for (; i <= mid; c++)
    {
        output[c] = arr[i];
        i++;
    }

    for (; j <= end; c++)
    {
        output[c] = arr[j];
        j++;
    }

    for (int x = start; x <= end; x++)
    {
        arr[x] = output[x];
    }
}
// MERGE SORT

void merge_sort(int *arr, int start, int end)
{
    if (start >= end)
    {
        return;
    }
    int mid = (start + end) / 2;
    merge_sort(arr, start, mid);
    merge_sort(arr, mid + 1, end);
    merge(arr, start, end);
}

int main()
{
    int arr[10000], size, start, end, modulus;
    cout << "Enter the size of the array: " << endl;
    cin >> size;
    cout << "Enter the value of modulus: " << endl;
    cin >> modulus;
    random_number(arr, size, modulus);
    cout << "Enter " << size << " elements in the array: " << endl;
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
    start = 0;
    end = size - 1;
    merge_sort(arr, start, end);
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
