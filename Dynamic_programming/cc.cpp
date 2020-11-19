#include<iostream>
using namespace std;
int main(){
    int tc;
    cin >> tc;
    for(int i = 0; i < tc; i++){
        int N, K, X, Y;
        cin >> N >> K >> X >> Y;
        if (K == 1)
        {
            cout << "YES" << endl;
            continue;
        }
        if((K % 2 != 0) || (N % 2 != 0)){
            cout << "YES" << endl;
            continue;
        }
        if((K % 2 == 0) && (N % 2 == 0)){
            if (((X % 2 == 0) && (Y % 2 == 0)) || ((X % 2 != 0) && (Y % 2 != 0)))
            {
                cout << "YES" << endl;
            }
            else{
                cout << "NO" << endl;
            }
                continue;
        }

    }
}