#include<iostream>
#include<stack>
using namespace std;

int evaluate_prefix(int op1, int op2, char op){
    if(op == '+'){
        return op1 + op2;
    }
    else if(op == '-'){
        return op1 - op2;
    }
    else if(op == '*'){
        return op1 * op2;
    }
    else{
        return op1 / op2;
    }
}


int prefix_eval(string exp){
    stack<int> prefix;
    for(int i = exp.size() - 1; i >= 0; i--){
        if(exp[i] >= '0' && exp[i] <= '9'){
            prefix.push((int)(exp[i] - '0'));
        }
        else{
            int first_element, second_element, result;
            first_element = prefix.top();
            prefix.pop();
            second_element = prefix.top();
            prefix.pop();
            result = evaluate_prefix(first_element, second_element, exp[i]);
            prefix.push(result);
        }
    }
    int result = prefix.top();
    prefix.pop();
    return result;
}


string infix_conversion(string exp){
    stack<string> infix;
    for(int i = exp.size() - 1; i >= 0; i--){
        if(exp[i] >= '0' && exp[i] <= '9'){
            string s = "";
            s += exp[i];
            infix.push(s);
        }
        else{
            string first_element, second_element, s = "", result = "";
            s += exp[i];
            first_element = infix.top();
            infix.pop();
            second_element = infix.top();
            infix.pop();
            result += "(" + first_element + s + second_element + ")";
            infix.push(result);
        }
    }
    string result = infix.top();
    infix.pop();
    return result;
}

string postfix_conversion(string exp){
    stack<string> postfix;
    for(int i = exp.size() - 1; i >= 0; i--){
        if(exp[i] >= '0' && exp[i] <= '9'){
            string s = "";
            s += exp[i];
            postfix.push(s);
        }
        else{
            string first_element, second_element, s = "", result = "";
            s += exp[i];
            first_element = postfix.top();
            postfix.pop();
            second_element = postfix.top();
            postfix.pop();
            result = first_element + second_element + s;
            postfix.push(result);
        }
    }
    string result = postfix.top();
    postfix.pop();
    return result;
}

int main(){
    string exp;
    getline(cin, exp);
    int result = prefix_eval(exp);
    cout << result << '\n';
    string infix = infix_conversion(exp);
    cout << infix << '\n';
    string postfix = postfix_conversion(exp);
    cout << postfix << '\n';
}