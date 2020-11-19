#include<iostream>
#include<stack>
using namespace std;

int precedence(char op){
    if(op == '+'){
        return 1;
    }
    else if(op == '-'){
        return 1;
    }
    else if(op == '*'){
        return 2;
    }
    else if (op == '/'){
        return 2;
    }
}


string eval_postfix(string exp){
    stack<string> postfix;
    stack<char> operators;
    for (int i = 0; i < exp.size(); i++)
    {
        if (exp[i] >= 'a' && exp[i] <= 'z')
        {
            string s = "";
            s += exp[i];
            postfix.push(s);
        }

        else if (exp[i] == ' ')
        {
            continue;
        }

        else
        {
            if (exp[i] == '(')
            {
                operators.push(exp[i]);
            }

            else if (exp[i] == ')')
            {
                while (operators.top() != '(')
                {
                    string first_element, second_element, s = "", result = "";
                    char op_pop = operators.top();
                    s += op_pop;
                    operators.pop();
                    second_element = postfix.top();
                    postfix.pop();
                    first_element = postfix.top();
                    postfix.pop();
                    result += first_element + second_element + s;
                    postfix.push(result);
                }
               operators.pop();
            }

            else
            {
                while (!operators.empty() && operators.top() != '(' && precedence(operators.top()) >= precedence(exp[i]))
                {
                    string first_element, second_element, s = "", result = "";
                    char op_pop = operators.top();
                    s += op_pop;
                    operators.pop();
                    second_element = postfix.top();
                    postfix.pop();
                    first_element = postfix.top();
                    postfix.pop();
                    result += first_element + second_element + s;
                    postfix.push(result);
                }
                operators.push(exp[i]);
            }
        }
    }

    while (!operators.empty())
    {
        string first_element, second_element, s = "", result = "";
        char op_pop = operators.top();
        s += op_pop;
        operators.pop();
        second_element = postfix.top();
        postfix.pop();
        first_element = postfix.top();
        postfix.pop();
        result += first_element + second_element + s;
        postfix.push(result);
    }
       string result = postfix.top();
       postfix.pop();
       return result;
}

string eval_prefix(string exp)
{
    stack<string> prefix;
    stack<char> operators;
    for (int i = 0; i < exp.size(); i++)
    {
        if (exp[i] >= 'a' && exp[i] <= 'z')
        {
            string s = "";
            s += exp[i];
            prefix.push(s);
        }
        else if (exp[i] == ' ')
        {
            continue;
        }
        else
        {
            if (exp[i] == '(')
            {
                operators.push(exp[i]);
            }
            else if (exp[i] == ')')
            {
                while (operators.top() != '(')
                {
                    string first_element, second_element, s = "", result = "";
                    char op_pop = operators.top();
                    s += op_pop;
                    operators.pop();
                    second_element = prefix.top();
                    prefix.pop();
                    first_element = prefix.top();
                    prefix.pop();
                    result += s + first_element + second_element;
                    prefix.push(result);
                }
                operators.pop();
            }
            else
            {
                while (!operators.empty() && operators.top() != '(' && precedence(operators.top()) >= precedence(exp[i]))
                {
                    string first_element, second_element, s = "", result = "";
                    char op_pop = operators.top();
                    s += op_pop;
                    operators.pop();
                    second_element = prefix.top();
                    prefix.pop();
                    first_element = prefix.top();
                    prefix.pop();
                    result += s + first_element + second_element;
                    prefix.push(result);
                }
            operators.push(exp[i]);
            }
        }
    }
    while (!operators.empty())
    {
        string first_element, second_element, s = "", result = "";
        char op_pop = operators.top();
        s += op_pop;
        operators.pop();
        second_element = prefix.top();
        prefix.pop();
        first_element = prefix.top();
        prefix.pop();
        result += s + first_element + second_element;
        prefix.push(result);
    }
    string result = prefix.top();
    prefix.pop();
    return result;
}

int main(){
    string exp, postfix_exp, prefix_exp;
    getline(cin, exp);
    postfix_exp = eval_postfix(exp);
    prefix_exp = eval_prefix(exp);
    cout << postfix_exp << '\n';
    cout << prefix_exp << '\n';
}