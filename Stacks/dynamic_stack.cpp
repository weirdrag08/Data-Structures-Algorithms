#include <iostream>
#include <stack>
using namespace std;

class Stack
{

    int *arr;
    int curr_size;
    int capacity;

public:
    int size()
    {
        return curr_size;
    }

    int top()
    {
        if (curr_size == 0)
        {
            cout << "Stack underflow" << '\n';
            return -1;
        }
        else
        {
            return arr[curr_size - 1];
        }
    }

    int pop()
    {
        if (curr_size == 0)
        {
            cout << "Stack underflow" << '\n';
            return -1;
        }
        else
        {
            int element = arr[curr_size - 1];
            curr_size--;
            return element;
        }
    }

    void push(int data)
    {
        if (curr_size == capacity)
        {
            int * new_arr = new int[2*capacity];
            for(int i = 0; i < curr_size; i++){
                new_arr[i] = arr[i];
            }
            new_arr[curr_size] = data;
            curr_size++;
            int * temp = arr;
            arr = new_arr;
            new_arr = temp;
            delete [] new_arr;
        }
        else
        {
            arr[curr_size] = data;
            curr_size++;
        }
    }

    void display()
    {
        for (int i = curr_size - 1; i >= 0; i--)
        {
            cout << arr[i] << ' ';
        }
        cout << '\n';
    }

    Stack(int size)
    {
        curr_size = 0;
        capacity = size;
        arr = new int[size];
    }
};

int main()
{
    int size;
    cin >> size;
    Stack my_stack(size);
    string s;
    int value;
    do
    {
        cin >> s;
        if (s == "push")
        {
            cin >> value;
            my_stack.push(value);
        }
        else if (s == "pop")
        {
            int result = my_stack.pop();
            if (result != -1)
            {
                cout << result << '\n';
            }
        }
        else if (s == "top")
        {
            int result = my_stack.top();
            if (result != -1)
            {
                cout << result << '\n';
            }
        }
        else if (s == "display")
        {
            my_stack.display();
        }
        else if (s == "size")
        {
            int result = my_stack.size();
            cout << result << '\n';
        }

    } while (s != "quit");
}