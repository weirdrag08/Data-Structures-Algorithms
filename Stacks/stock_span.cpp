#include<iostream>
#include<stack>
using namespace std;
using namespace std::chrono;

int random_n(){
    return (rand()%100000);
}

int main(){
    int arr[100000], n, output[100000], element;
    stack<int> my_stack;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    my_stack.push(0);
    output[0] = 1;

    for(int i = 1; i < n; i++){
        element = arr[i];
        if (element <= arr[my_stack.top()])
        {
            output[i] =  1;
            my_stack.push(i);
        }
        else{
            while (!my_stack.empty() && arr[my_stack.top()] < element)
            {
                my_stack.pop();
            }
            if(my_stack.empty()){
                output[i] = i + 1;
                my_stack.push(i);
            }
            else{
                output[i] = i - (my_stack.top());
                my_stack.push(i);
            }
        }
    }

    for(int i = 0; i < n; i++){
        cout << output[i] << endl;
    }
    
}