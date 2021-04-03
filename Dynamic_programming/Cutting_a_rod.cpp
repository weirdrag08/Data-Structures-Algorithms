#include<iostream>
using namespace std;

int cutting_rod(int *arr, int size){
    int *dp = new int[size + 1];
    dp[0] = 0;
    dp[1] = arr[1];
    int maximum;
    for(int i = 2; i <= size; i++){
         maximum = INT_MIN;
        for(int j = 1; j < i; j++){
          maximum = max(maximum, (dp[j] + arr[i - j]));
        }
        if(maximum < arr[i]){
            maximum = arr[i];
        }
        dp[i] = maximum;
    }
    return dp[size];
}
 
int main(){
    int arr[1000], size;
    cout << "Enter the size of the array: " << endl;
    cin >> size;
    arr[0] = 0;
    cout << "Enter " << size << " elements in the array: " << endl;
    for(int i = 1; i <= size; i++){
        cin >> arr[i];
    }
    int maximum_cost = cutting_rod(arr, size);
    cout << "The maximum value of by cutting a rod: " << maximum_cost << endl;
}