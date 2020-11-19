// #include <iostream>
// #include <stack>
// #include <climits>
// using namespace std;
// int main()
// {
//     int n, element, k;
//     int *arr = new int[10000000];
//     int *ngetr = new int[10000000];
//     stack<int> my_stack;
//     cin >> n;
//     for (int i = 0; i < n; i++)
//     {
//         cin >> arr[i];
//     }
//     cin >> k;

//     // * 2 9 3 8 1     stack [1, 3, 4]        ngetr[1,,3]

//     for (int i = 0; i < n; i++)
//     {
//         element = arr[i];

//         if (i == 0)
//         {
//             my_stack.push(i);
//         }

//         else if (arr[my_stack.top()] >= element)
//         {
//             my_stack.push(i);
//         }
//         else
//         {
//             while (!my_stack.empty() && arr[my_stack.top()] < element)
//             {
//                 int front = my_stack.top();
//                 ngetr[front] = i;
//                 my_stack.pop();
//             }
//             my_stack.push(i);
//         }
//     }
//     while (!my_stack.empty())
//     {
//         ngetr[my_stack.top()] = -1;
//         my_stack.pop();
//     }

//     // for(int i = 0; i < n; i++){
//     //     cout << ngetr[i] << " ";
//     // }

//     int j;
//     for (int i = 0; i < n - k + 1; i++)
//     {
//         int range = i + k - 1;
//         j = i; // * j = 1 , range = 3
//         while (j <= range && j != -1 && ngetr[j] <= range)
//         {
//             if (ngetr[j] != -1)
//             {
//                 j = ngetr[j];
//             }
//             else
//             {
//                 break;
//             }
//         }
//         cout << arr[j] << " ";
//     }
// }

#include <iostream>
#include <stack>
#include <climits>
using namespace std;
int main()
{

    int n, element, k;
    int *arr = new int[10000000];
    int *ngetr = new int[10000000];
    stack<int> *my_stack = new stack<int>;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cin >> k;

    for (int i = 0; i < n; i++)
    {
        element = arr[i];

        if (i == 0)
        {
            my_stack->push(i);
        }

        else if (arr[my_stack->top()] >= element)
        {
            my_stack->push(i);
        }
        else
        {
            while (!my_stack->empty() && arr[my_stack->top()] < element)
            {
                int front = my_stack->top();
                ngetr[front] = i;
                my_stack->pop();
            }
            my_stack->push(i);
        }
    }
    while (!my_stack->empty())
    {
        ngetr[my_stack->top()] = -1;
        my_stack->pop();
    }

    int j;
    for (int i = 0; i < n - k + 1; i++)
    {
        int range = i + k - 1;
        j = i; // * j = 1 , range = 3
        while (ngetr[j] <= range)
        {
            if (ngetr[j] != -1)
            {
                j = ngetr[j];
            }
            else
            {
                break;
            }
        }
        cout << arr[j] << " ";
    }
}