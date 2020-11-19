#include<iostream>
#include<stack>
using namespace std;
int main(){
    string s;
    getline(cin,s);
    stack<char> my_stack;
    int count = 0;
    bool duplicate = false;
    for(int i = 0; i < s.size(); i++){
        if(s[i] != ')'){
            my_stack.push(s[i]);
        }
        else if(s[i] == ')'){
            if(my_stack.top() == '('){
                duplicate = true;
                break;
            }
             while(!my_stack.empty() && my_stack.top() != '('){
                 my_stack.pop();
             }
             if(!my_stack.empty()){
                 my_stack.pop();
             }
        }
    }
    if (duplicate)
    {
        cout << "true" << endl;
    }
    else
    {
        cout << "false" << endl;
    }
    //
}