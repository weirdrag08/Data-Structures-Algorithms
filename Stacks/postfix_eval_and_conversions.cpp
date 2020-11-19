#include<iostream>
#include<stack>
using namespace std;

int evaluate_postfix(int op1, int op2, char op){
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

string prefix_conversion(string exp){
    stack<string> prefix;
    for(int i = 0; i < exp.size(); i++){
        if(exp[i] >= '0' && exp[i] <= '9'){
            string s = "";
            s += exp[i];
            prefix.push(s);
        }
        else{
            string first_element, second_element, s = "", result = "";
            s += exp[i];
            second_element = prefix.top();
            prefix.pop();
            first_element = prefix.top();
            prefix.pop();
            result += s + first_element + second_element;
            prefix.push(result);
        }
    }
    string result = prefix.top();
    prefix.pop();
    return result;
}

string infix_conversion(string exp){
    stack<string> infix;
    for(int i = 0; i < exp.size(); i++){

        if(exp[i] >= '0' && exp[i] <= '9'){
            string s = "";
            s += exp[i];
            infix.push(s);
        }

        else{
            string first_element, second_element, s = "", result = "";
            s += exp[i];
            second_element = infix.top();
            infix.pop();
            first_element = infix.top();
            infix.pop();
            result += "(" + first_element + s + second_element + ")";
            infix.push(result);
        }
    }
    string result = infix.top();
    infix.pop();
    return result;
}

int postfix_eval(string exp){
    stack<int> postfix;
    for(int i = 0; i < exp.size(); i++){
        if(exp[i] >= '0' && exp[i] <= '9'){
            postfix.push((int)(exp[i] - '0')); //* To convert a character '0' to integer 0 (REMEMBER PLEASE!)
        }
        else{
            int first_element, second_element;
            second_element = postfix.top();
            postfix.pop();
            first_element = postfix.top();
            postfix.pop();
            int result = evaluate_postfix(first_element, second_element, exp[i]);
            postfix.push(result);
        }
    }
    int result = postfix.top();
    postfix.pop();
    return result;
}

int main(){
    string exp;
    getline(cin, exp);
    int result = postfix_eval(exp);
    cout << result << '\n';
    string infix = infix_conversion(exp);
    cout << infix << '\n';
    string prefix = prefix_conversion(exp);
    cout << prefix << '\n';
}