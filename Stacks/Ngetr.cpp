#include<iostream>
#include<stack>
using namespace std;

void ngetr(int *arr, int size){
    stack<int> my_stack;
    int output[size], element;
    for(int i = size - 1; i >= 0; i--){
        element = arr[i];
        for(int j = 0; !my_stack.empty(); j++){
            if(element < my_stack.top()){
                break;
            }
            my_stack.pop();
        }
        if(my_stack.empty()){
            output[i] = -1;
            my_stack.push(element);
        }
        else{
            output[i] = my_stack.top();
            my_stack.push(element);
        }
    }
    for(int i = 0; i < size; i++){
        cout << output[i] << endl;
    }
}

int main(){
    int arr[100000], size;
    cout << "Enter the size of the array: " << endl;
    cin >> size;
    cout << "Enter " << size << " elements in the array: " << endl;
    for(int i = 0; i < size; i++){
        cin >> arr[i];
    } 
    ngetr(arr, size);
}

// ? SECOND SOLUTION

// #include <iostream>
// #include <stack>
// using namespace std;
// int main()
// {
//     int arr[100000], n, element, output[100000];
//     cin >> n;
//     stack<int> my_stack;
//     for (int i = 0; i < n; i++)
//     {
//         cin >> arr[i];
//     }

//     my_stack.push(arr[n - 1]);
//     output[n - 1] = -1;
//     for (int i = n - 2; i >= 0; i--)
//     {
//         element = arr[i];
//         if (my_stack.top() > element)
//         {
//             output[i] = my_stack.top();
//         }
//         else
//         {
//             while (!my_stack.empty() && my_stack.top() < element)
//             {
//                 my_stack.pop();
//             }
//             if (my_stack.empty())
//             {
//                 output[i] = -1;
//             }
//             else
//             {
//                 output[i] = my_stack.top();
//             }
//         }
//         my_stack.push(element);
//     }

//     for (int i = 0; i < n; i++)
//     {
//         cout << output[i] << '\n';
//     }
// }
