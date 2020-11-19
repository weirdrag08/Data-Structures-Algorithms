#include<iostream>
#include<stack>
using namespace std;

int eval_operators(int op1, int op2, char op){
    if(op == '+'){
        return op1 + op2;
    }
    else if(op == '-'){
        return op1 - op2;
    }
    else if(op == '*'){
        return op1 * op2;
    }
    else if(op == '/'){
        return op1 / op2;
    }
}

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
    else if(op == '/'){
        return 2;
    }
}

int main(){
    string exp;
    getline(cin, exp); // * getline is used so that it doesn't break on spaces if any, present in the input string
    stack<int> operands;
    stack<char> operators;
    int first_element, second_element, mid_result;     
    for(int i = 0; i < exp.size(); i++){
        if (exp[i] <= '9' && exp[i] >= '0')
        {
            operands.push((int)(exp[i] - '0')); // * Always remember that a character '0' is different from integer 0. Please make the necessary changes before you proceed.
        }

       else if (exp[i] == ' ')
        {
            continue;
        }

        else{
            if(exp[i] == '('){
                operators.push(exp[i]);
            }

            else if(exp[i] == ')'){
                while(operators.top() != '('){
                    char op_pop = operators.top();
                    operators.pop();
                    second_element = operands.top();
                    operands.pop();
                    first_element = operands.top();
                    operands.pop();
                    mid_result = eval_operators(first_element, second_element, op_pop);
                    operands.push(mid_result);
                }
                operators.pop();
            }

            else{
                while(!operators.empty() && operators.top() != '(' && precedence(operators.top()) >= precedence(exp[i])){
                    char op_pop = operators.top();
                    operators.pop();
                    second_element = operands.top();
                    operands.pop();
                    first_element = operands.top();
                    operands.pop();
                    mid_result = eval_operators(first_element, second_element, op_pop);
                    operands.push(mid_result);
                   // cout << first_element << ' ' << op_pop << ' ' << second_element << " = " << mid_result << '\n';
                }
               operators.push(exp[i]);
            }
        }
    }  
    while(!operators.empty()){
        char op_pop = operators.top();
        operators.pop();
        second_element = operands.top();
        operands.pop();
        first_element = operands.top();
        operands.pop();
        mid_result = eval_operators(first_element, second_element, op_pop);
        operands.push(mid_result);
    }
    cout << operands.top() << '\n';
    operands.pop();
}
