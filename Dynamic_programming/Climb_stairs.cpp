#include<iostream>
#include<unordered_map>
#include<list>
#include<vector>
#include<climits>
#include<stack>
#include<queue>
#include<algorithm>
#include<string>
#include<utility>
using namespace std;

#define mp make_pair
#define INFI 10e8
#define INF 10e7

typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef long long ll;

void climb_stairs(int start,int n, string path, vector<string> *all_paths){
    if(start == n){
        all_paths->push_back(path);
        return;
    }
    if(n - start >= 1){
        climb_stairs(start + 1, n, path + to_string(1), all_paths);
    }
    if(n - start >= 2){
        climb_stairs(start + 2, n, path + to_string(2), all_paths);
    }

    if(n - start >= 3){
        climb_stairs(start + 3, n, path + to_string(3), all_paths);
    }
    return;
}

int main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, start = 0;
    string path = "";
    vector<string> *all_paths = new vector<string>();
    cin >> n;
    climb_stairs(start, n, path, all_paths);
    cout << all_paths-> size() << '\n';
    for(int i = 0; i < all_paths-> size(); i++){
        cout << all_paths-> at(i) << '\n';
    }
}