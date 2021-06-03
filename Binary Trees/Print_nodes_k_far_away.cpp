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

vector<Node*>* find_path(Node *root, int &target){
    if(root == NULL)
        return NULL;

    if(root-> data == target){
        vector<Node*> *base_arr = new vector<Node*>(1, root);
        return base_arr;
    }    
    vector<Node*> *left = NULL, *right = NULL;
    if(root-> left != NULL)
        left = find_path(root-> left, target);
        if(left != NULL){
            left-> pb(root);
            return left;
        }
    if(root-> right != NULL)
        right = find_path(root-> right, target);  
    if(right != NULL){
        right-> pb(root);
        return right;
    }
    return NULL;          
}

void print_k_far_away_helper(Node *root, int k, Node *blocker){
    queue<Node*> q;
    q.push(root);
    int level = 0, size = q.size();
    while(!q.empty()){
        Node *front = q.front();
        q.pop();
        size--;
        if(level == k){
            cout << front-> data << '\n';
        }
        if(front-> left != NULL && front-> left != blocker)
            q.push(front-> left);
        if(front-> right != NULL && front-> right != blocker)
            q.push(front-> right);
        if(size == 0){
            size = q.size();
            level++;
        }
    }
}

void print_k_far_away(vector<Node*> *path, int &k){
    for(int i = 0; i < (int) path-> size(); i++){
        if(i == 0)
            print_k_far_away_helper(path-> at(i), k, NULL);
        else
            print_k_far_away_helper(path-> at(i), k - i, path-> at(i - 1));
    }
}

int main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Node *root = input();
    int target, k;
    cin >> target >> k;
    vector<Node*> *path = find_path(root, target);
    print_k_far_away(path, k);
}