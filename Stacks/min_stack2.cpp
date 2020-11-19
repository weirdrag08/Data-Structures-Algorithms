#include <iostream>
#include <stack>
#include<climits>
using namespace std;
int main()
{
    stack<int> my_stack;
    string s;
    int minimum = INT_MAX;

    do
    {
        cin >> s;
        if (s == "push")
        {
            int data;
            cin >> data;
            if (my_stack.empty() || data >= minimum)
            {
                if (my_stack.empty())
                {
                    minimum = data;
                }
                my_stack.push(data);
            }
            else
            {
                my_stack.push(data + (data - minimum));
                minimum = data;
            }
        }
        else if (s == "pop")
        {
            if (my_stack.size() == 0)
            {
                cout << "Stack underflow" << '\n';
            }
            else
            {
                if (my_stack.top() >= minimum)
                {
                    cout << my_stack.top() << '\n';
                    my_stack.pop();
                }
                else
                {
                    int result = my_stack.top();
                    int curr_min = minimum;
                    minimum = (2 * curr_min) - result;
                    cout << curr_min << '\n';
                    my_stack.pop();
                }
            }
        }
        else if (s == "top")
        {
            if (my_stack.size() == 0)
            {
                cout << "Stack underflow" << '\n';
            }
            else
            {
                if (my_stack.top() < minimum)
                {
                    cout << minimum << '\n';
                }
                else
                {
                    cout << my_stack.top() << '\n';
                }
            }
        }
        else if (s == "size")
        {
            cout << my_stack.size() << '\n';
        }
        else if (s == "min")
        {
            cout << minimum << '\n';
        }
    } while (s != "quit");
}

// ? 10 20 5 8 2 4 11

// *   Stack -  10 20 0 8 -1                            min - 2

// * PRINTED     11 2 11 4 2 4