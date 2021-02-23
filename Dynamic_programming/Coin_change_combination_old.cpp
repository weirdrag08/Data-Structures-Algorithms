#include<iostream>
using namespace std;

int count_coin_change_combinations_helper(int *arr, int size, int index, int amount){
    if(amount < 0){
        return 0;
    }
    if(amount == 0){
        return 1;
    }
    if(arr[index] == amount && amount > 0){
        return 1;
    }
    int part_of_subset = 0;
    int repeated_part_of_subset = 0;
    int not_part_of_subset = 0;
    if(index < size - 1){

        // part_of_subset = count_coin_change_combinations_helper(arr, size, index + 1, amount - arr[index]);
         repeated_part_of_subset = count_coin_change_combinations_helper(arr, size, index, amount - arr[index]);
         not_part_of_subset = count_coin_change_combinations_helper(arr, size, index + 1, amount);
    }

    return + not_part_of_subset + repeated_part_of_subset;
}

int count_coin_change_combinations(int *arr, int size, int amount){
    int index = 0;
    return count_coin_change_combinations_helper(arr, size, index, amount);
}

int coin_change_combinations_dp(int *denominations, int size, int amount){
    int dp[amount + 1];
    for(int i = 0; i <= amount; i++){
        dp[i] = 0;
    }
    dp[0] = 1;
    for(int i = 0; i < size; i++){
        for(int j = 1; j <= amount; j++){
            if(j - denominations[i] >= 0 && dp[j - denominations[i]] != 0){
                dp[j] += 1;
            }
        }
    }
    return dp[amount];
}

int main(){
    int arr[1000], size, amount;
    cout << "Enter the size of the array: " << endl;
    cin >> size;
    cout << "Enter " << size << " elements in the array: " << endl;
    for(int i = 0; i < size; i++){
        cin >> arr[i];
    }
    cout << "Enter the total amount: " << endl;
    cin >> amount;
    int count = coin_change_combinations_dp(arr, size, amount);
    cout << "The total number of possible coin combination to sum up to total amount: " << count << endl; 
}