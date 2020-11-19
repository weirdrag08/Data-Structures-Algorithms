#include<iostream>
#include<stack>
using namespace std;
int main(){
    int n;
    cin >> n;
    pair<int, int> arr[10000], element;
    stack<pair<int, int> > my_stack;
    for(int i = 0; i < n; i++){
        cin >> element.first >> element.second;
        arr[i] = element;
    }

    sort(arr, arr + n);
    // for(int i = 0; i < n; i++){
    //     cout << arr[i].first << "     " << arr[i].second << '\n';
    // }

    element.first = -1;
    element.second = -1;
    for(int i = 0; i < n; i++){
        element = arr[i];
        if(my_stack.empty() || (my_stack.top().first <= element.first &&  my_stack.top().second >= element.second)){
            if(my_stack.empty()){
                my_stack.push(element);
            }
            else{
                continue;
            }
            // cout << "Case" << i << ": " << my_stack.top().first << ' ' << my_stack.top().second << '\n';
        }

       else if(my_stack.empty() || (my_stack.top().first <= element.first && my_stack.top().second >= element.first)){
           if(my_stack.empty()){
               my_stack.push(element);
           }
           else{
               pair<int, int> top = my_stack.top();
               my_stack.pop();
               top.second = element.second;
               my_stack.push(top);
           }
        //    cout << "Case" << i << ": " << my_stack.top().first << ' ' << my_stack.top().second << '\n';
       }
                                                    
       else if(my_stack.empty() || (my_stack.top().first <= element.second && my_stack.top().second >= element.second)){
           if(my_stack.empty()){
               my_stack.push(element);
           }
           else{
               pair<int, int> top = my_stack.top();
               my_stack.pop();
               top.first = element.first;
               my_stack.push(top);
           }
        //    cout << "Case" << i << ": " << my_stack.top().first << ' ' << my_stack.top().second << '\n';
       }

       else{
           my_stack.push(element);
        //    cout << "Case" << i << ": " << my_stack.top().first << ' ' << my_stack.top().second << '\n';
       }
    }

pair<int, int> result[10000];
int size = my_stack.size();
for(int i = 0; !my_stack.empty(); i++){
    result[i] = my_stack.top();
    my_stack.pop(); 
}

sort(result, result + size);

for(int i = 0; i < size; i++){
    cout << result[i].first << ' ' << result[i].second << '\n';
}

}

// * 1 9    2 4     4 7     6 8