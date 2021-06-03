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

class Node{
public:

    int data;
    Node *left, *right;
    Node(int data){
        this-> data = data;
        this-> left = NULL;
        this-> right = NULL;
    }
};

Node* input(){
    int size; 
    cin >> size;
    vector<string> v(size);
    for(int i = 0; i < size; i++){
        cin >> v[i];
    }

    int root_data = stoi(v[0]);
    Node *root = new Node(root_data);
    stack<pair<Node*, int> > my_stack;
    my_stack.push(mp(root, 0));
    int index = 0;
    while(!my_stack.empty()){
        auto top = my_stack.top();
        my_stack.pop();
        if(top.second == 0 && index < size){
            index++;
            top.second++;
            my_stack.push(top);
            if(v[index] == "n")
                top.first-> left = NULL;
            else{
                int val = stoi(v[index]);
                Node *left_child = new Node(val);
                top.first-> left = left_child;
                my_stack.push(mp(left_child, 0));
            }      
        }
        else if(top.second == 1 && index < size){
            index++;
            top.second++;
            my_stack.push(top);
            if(v[index] == "n")
                top.first-> right = NULL;
            else{
                int val = stoi(v[index]);
                Node *right_child = new Node(val);
                top.first-> right = right_child;
                my_stack.push(mp(right_child, 0));
            }  
        }
    }
    return root;
}

pair<int, int> is_BST_helper(Node *root, bool &bst){
    if(root == NULL){
        pair<int, int> base_p(INT_MAX, INT_MIN);
        return base_p;
    }  
    if(!bst){
        pair<int, int> base_p(INT_MIN, INT_MAX);
        return base_p;
    }
        pair<int, int> leftside(INT_MAX, INT_MIN), rightside(INT_MAX, INT_MIN);
    if(root-> left != NULL)
        leftside = is_BST_helper(root-> left, bst);
    if(root-> right != NULL)
        rightside = is_BST_helper(root-> right, bst);
    if(root-> data < leftside.second || root-> data > rightside. first){
        bst = false;
        pair<int, int> base_p(INT_MIN, INT_MAX);
    }
    else{
        pair<int, int> node_pair(min(root-> data, min(leftside.first, rightside.first)), max(root-> data, max(leftside.second, rightside.second)));
        return node_pair;
    }
}
 
bool is_BST(Node *root){
    bool bst = true;
    is_BST_helper(root, bst);
    return bst;
}

int main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Node *root = input();
    cout << boolalpha << is_BST(root) << '\n';
}