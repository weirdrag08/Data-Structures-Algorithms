#include<iostream>
#include<stack>
using namespace std;


int main(){

    stack<int> my_stack, min_stack;
    string s;
    
    do{
        cin >> s;
        if(s == "push"){
            int data;
            cin >> data;
            my_stack.push(data);
            if(min_stack.empty() || min_stack.top() >= data){  
                min_stack.push(data);
            }
        }
        else if(s == "pop"){
            if(my_stack.size() == 0){
                cout << "Stack underflow" << '\n';
            }
            else{
                if (my_stack.top() == min_stack.top())
                {   
                    cout << my_stack.top() << '\n';
                    my_stack.pop();
                    min_stack.pop();
                }
                else
                {   
                    cout << my_stack.top() << '\n';
                    my_stack.pop();
                }
            }
        }
        else if(s == "top"){
            if(my_stack.size() == 0){
                cout << "Stack underflow" << '\n';
            }
            else{
                cout << my_stack.top() << '\n';
            }
        }
        else if(s == "size"){
            cout << my_stack.size() << '\n';
        }
        else if(s == "min"){
         if(min_stack.size() == 0){
             cout << "Stack underflow" << '\n';
         }
         else{
             int minimum = min_stack.top();
             cout << minimum << '\n';
         }
     
        }
    }
    while(s != "quit");
}





//*  stack -  10 2 5 2 11                                   // min_stack - 10 2 

// * PRINTED - 8 5 2  pop, pop min