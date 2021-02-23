#include<iostream>
using namespace std;

int coin_change_permutations(int *denominations, int size, int amount){
    int dp[amount + 1];
    for(int i = 0; i <= amount; i++){
        dp[i] = 0;
    }
    dp[0] = 1;
    int count;
    for(int i = 1; i <= amount; i++){
        count = 0;
        for(int j = 0; j < size; j++){
            if(i - denominations[j] < 0){
                continue;
            }
            else{
               count += dp[i - denominations[j]];
            }
        }
        dp[i] = count;
    }
    return dp[amount];
}

int main(){
    int denominations[1000], size, amount;
    cout << "Enter the number of denominations: " << endl;
    cin >> size;
    cout << "Enter " << size << " denominations in the array: " << endl;
    for(int i = 0; i < size; i++){
        cin >> denominations[i];
    }
    cout << "Enter the amount: " << endl;
    cin >> amount;

    int total_count = coin_change_permutations(denominations, size, amount);
    cout <<  "The total number of combinations: " << total_count << endl;
}