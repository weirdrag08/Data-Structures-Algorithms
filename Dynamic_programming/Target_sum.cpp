#include <iostream>
#include <vector>
using namespace std;

vector<int> *target_sum_helper(int *arr, int size, int index, int target)
{
    if (arr[index] == target)
    {
        vector<int> *base_arr = new vector<int>();
        base_arr->push_back(arr[index]);
        return base_arr;
    }
    vector<int> *part_of_subset = new vector<int>();
    vector<int> *not_part_of_subset = new vector<int>();
    vector<int> *final_array = new vector<int>();
    if (index < size - 1)
    {
        part_of_subset = target_sum_helper(arr, size, index + 1, target - arr[index]);
        not_part_of_subset = target_sum_helper(arr, size, index + 1, target);
    }
    // int size = part_of_subset-> size() + not_part_of_subset-> size();
    for (int i = 0; i < not_part_of_subset->size(); i++)
    {
        final_array->push_back(not_part_of_subset->at(i));
    }
    int current = 0;
    for (int i = current; i < part_of_subset->size(); i++)
    {
        int sum = 0;
        for (int j = current; sum != (target - arr[index]); j++)
        {
            final_array->push_back(part_of_subset->at(current));
            sum += part_of_subset->at(current);
            current++;
        }
        final_array->push_back(arr[index]);
        sum = 0;
    }

    // int current_sum = 0;
    // for(int i = 0; i < part_of_subset->size(); i++){
    //     if (current_sum == target - arr[index])
    //     {
    //         current_sum = 0;
    //         final_array->push_back(arr[index]);
    //     }
    //cout << result_array->at(i) << " ";
    //     final_array-> push_back(part_of_subset-> at(i));
    //     current_sum += part_of_subset-> at(i);
    // }

    return final_array;
}

vector<int> *target_sum(int *arr, int size, int target)
{
    int index = 0;
    return target_sum_helper(arr, size, index, target);
}

int main()
{
    int arr[1000], size, target;
    cout << "Enter the size of the array: " << endl;
    cin >> size;
    cout << "Enter " << size << " elements in the array: " << endl;
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
    cout << "Enter the target value: " << endl;
    cin >> target;
    vector<int> *result_array = target_sum(arr, size, target);
    int current_sum = 0;
    for (int i = 0; i < result_array->size(); i++)
    {
        if (current_sum == target)
        {
            current_sum = 0;
            cout << endl;
        }
        cout << result_array->at(i) << " ";
        current_sum += result_array->at(i);
    }
}