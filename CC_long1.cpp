#include<iostream>
using namespace std;
int main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tc;
    cin >> tc;
    for(int i = 0; i < tc; i++){
        int N, K, D, sum = 0, val;
        cin >> N >> K >> D;
        for(int j = 0; j < N; j++){
            cin >> val;
            sum += val;
        }
        if(sum/K >= D){
            cout << D << '\n';
        }
        else{
            cout << sum/K << '\n';
        }
    }
}