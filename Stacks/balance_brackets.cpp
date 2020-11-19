#include <iostream>
#include <stack>
#include <string>
using namespace std;
int main()
{
    string s;
    stack<char> my_stack;
    int count = 0;
    bool balanced = true;
    getline(cin, s);
    for (int i = 0; i < s.size(); i++)
    {

        if (s[i] == '(' || s[i] == '{' || s[i] == '[')
        {
            my_stack.push(s[i]);
        }

        else
        {
            if (s[i] == ')')
            {
                while (!my_stack.empty() && my_stack.top() != '(')
                {
                    my_stack.pop();
                }
                if (!my_stack.empty())
                {
                    my_stack.pop();
                }
                else
                {
                    balanced = false;
                    break;
                }
            }

            else if (s[i] == '}')
            {
                while (!my_stack.empty() && my_stack.top() != '{')
                {
                    my_stack.pop();
                }

                if (!my_stack.empty())
                {
                    my_stack.pop();
                }
                else
                {
                    balanced = false;
                    break;
                }
            }

            else if (s[i] == ']')
            {
                while (!my_stack.empty() && my_stack.top() != '[')
                {
                    my_stack.pop();
                }

                if (!my_stack.empty())
                {
                    my_stack.pop();
                }
                else
                {
                    balanced = false;
                    break;
                }
            }
        }
    }
    if (!my_stack.empty())
    {
        balanced = false;
    }

    if (!balanced)
    {
        cout << "false" << endl;
    }
    else
    {
        cout << "true" << endl;
    }
}