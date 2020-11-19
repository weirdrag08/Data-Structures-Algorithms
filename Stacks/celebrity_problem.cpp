#include<iostream>
#include<stack>
using namespace std;
int main(){
    int n, top1, top2;
    string arr[10000];
    stack<int> my_stack;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        my_stack.push(i);
    }
    while (my_stack.size() != 1 && !my_stack.empty()){
         top1 = my_stack.top();
         my_stack.pop();
         top2 = my_stack.top();
         my_stack.pop();
         bool top_1_flag = false, top_2_flag = false;
         if(arr[top2][top1] == '1' && arr[top1][top2] == '0'){
            top_1_flag = true;
         }
         if(arr[top1][top2] == '1' && arr[top2][top1] == '0'){
             top_2_flag = true;
         }
         if(top_1_flag){
             my_stack.push(top1);
         }
         if(top_2_flag){
             my_stack.push(top2);
         }
    }
    if(my_stack.empty()){
        cout << "none" << '\n';
    }
    else{
        bool celebrity = true;
        for(int i = 0; i < n; i++){
            if(i == my_stack.top()){
                continue;
            }
            else{
                if(arr[i][my_stack.top()] == '0'){
                    celebrity = false;
                    break;
                }
            }
        }
        if(celebrity){
            cout << my_stack.top() << '\n';
            my_stack.pop();
        }
        else{
            cout << "none" << '\n';
            my_stack.pop();
        }
    }
}