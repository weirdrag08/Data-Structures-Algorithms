#include <iostream>
#include <unordered_map>
#include <list>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <string>
#include <climits>
#include <utility>
using namespace std;

#define mp make_pair
#define pb push_back
#define INFI 10e8
#define INF 10e7
#define mod 1000000007
#define sieve_limit 10e6

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<long> vl;
typedef vector<long long> vll;
typedef vector<long long int> vlli;
typedef vector<bool> vb;
typedef vector<vector<int> > vvi;
typedef vector<vector<long long> > vvll;
typedef vector<vector<long long int> > vvlli;
typedef vector<vector<bool> > vvb;

class SegmentTree{
public:
    vi tree;

    SegmentTree(vi &v){
        tree = vi(4 * v.size());
    }

private:

    void build_tree_helper(int s, int e, vi &v, vi &tree, int index){
        if(s == e){
            tree[index] = v[s];
            return;
        }

        int mid = s + (e - s)/2;
        build_tree_helper(s, mid, v, tree, 2 * index);
        build_tree_helper(mid + 1, e, v, tree, (2 * index) + 1);
        tree[index] = tree[2 * index] + tree[(2 * index) + 1];
    }

    void point_update_helper(int s, int e, vi &v, vi &tree, int index, int val, int point){
        if(s == point && e == point){
            tree[index] = val;
            return;
        }
        int mid = s + (e - s) / 2;
        point > mid ? point_update_helper(mid + 1, e, v, tree, (2 * index) + 1, val, point) : point_update_helper(s, mid, v, tree, 2 * index, val, point);
        tree[index] = tree[2 * index] + tree[(2 * index) + 1];
    }

    int query_helper(int s, int e, vi &v, vi &tree, int index, int L, int R){
        if(s == L && e == R)
            return tree[index];
        int mid = s + (e - s)/2;
        if(R <= mid)
            return query_helper(s, mid, v, tree, 2 * index, L, R);
        else if(L > mid)
            return query_helper(mid + 1, e, v, tree, (2 * index) + 1, L, R);
        else{
            return query_helper(s, mid, v, tree, 2 * index, L, mid) + query_helper(mid + 1, e, v, tree, (2 * index) + 1, mid + 1, R);
        }        
    }

public:

    void build_tree(vi &v){
        int index = 1;
        build_tree_helper(0, (int) v.size() - 1, v, tree, index);
    }

    void point_update(vi &v, int val, int point){
        int index = 1;
        point_update_helper(0, (int) v.size() - 1, v, tree, index, val, point);
    }  
     
    int query(vi &v, int L, int R){
        int index = 1;
       return query_helper(0, (int) v.size() - 1, v, tree, index, L, R);
    }

    void display(){
        for(int i = 1; i < (int) tree.size(); i++)
            cout << tree[i] << " ";
        cout << '\n';    
    }  
};

int main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vi v(n);
    for(int i = 0; i < n; i++)
        cin >> v[i];

    SegmentTree s(v);
    s.build_tree(v);
}