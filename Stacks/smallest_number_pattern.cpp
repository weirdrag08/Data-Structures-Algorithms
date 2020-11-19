#include<iostream>
#include<stack>
using namespace std;
int main(){
    string s;
    stack<int> my_stack; // * hehehehehehehe my_map
    int number = 1;
    cin >> s;
    for(int i = 0; i < s.size(); i++){
        if(s[i] == 'd'){
            my_stack.push(number);
            number++;
        }
        else{
            my_stack.push(number);
            number++;
            while(!my_stack.empty()){
                cout << my_stack.top();
                my_stack.pop();
            }
        }
    }
    my_stack.push(number);
    number++;
    while(!my_stack.empty()){
       cout << my_stack.top();
       my_stack.pop();
    }
    cout << '\n'; 
}