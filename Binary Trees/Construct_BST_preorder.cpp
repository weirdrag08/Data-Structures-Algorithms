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
    stack<pair<Node*, int> > my_stack;
    int size, root_data;
    cin >> size >> root_data;
    Node *root = new Node(root_data);
    my_stack.push(mp(root, 0));
    while(!my_stack.empty()){
        auto top = my_stack.top();
        my_stack.pop();
        if(top.second == 0){
            top.second++;
            int element;
            cin >> element;
            if(element != -1){
                Node *child = new Node(element);
                top.first-> left = child;
                my_stack.push(top);
                my_stack.push(mp(child, 0));
            }
            else
                my_stack.push(top);
        }
        else if(top.second == 1){
            top.second++;
            int element;
            cin >> element;
            if(element != -1){
                Node *child = new Node(element);
                top.first-> right = child;
                my_stack.push(top);
                my_stack.push(mp(child, 0));
            }
            else
                my_stack.push(top);
        }
    }
    return root;
}

void display(Node *root){
    if(root == NULL)
        return;
    queue<Node*> q;
    q.push(root);
    int size = q.size();
    while(!q.empty()){
        Node *front = q.front();
        q.pop();
        size--;
        cout << front-> data << " ";
        if(front-> left != NULL)
            q.push(front-> left);
        if(front-> right != NULL)
            q.push(front-> right);
        if(size == 0){
            size = q.size();
            cout << '\n';
        }       
    }    
}

Node* construct_BST(int s, int e, vi &preorder){
    if(s > e)
        return NULL;
    if(s == e){
        Node *leaf = new Node(preorder[s]);
        return leaf;
    }    
    int root_data = preorder[s];
    Node *root = new Node(root_data);
    int left_subtree = INT_MIN;
    for(int i = s + 1; i <= e; i++){
        if(root_data < preorder[i]){
            left_subtree = i - 1;
            break;
        }
    }
    Node *left_tree = NULL, *right_tree = NULL;
    if(left_subtree == INT_MIN){
        left_tree = construct_BST(s + 1, e, preorder);
    }
    else if(left_subtree == s){
        right_tree = construct_BST(s + 1, e, preorder);
    }
    else{
        left_tree = construct_BST(s + 1, left_subtree, preorder);
        right_tree = construct_BST(left_subtree + 1, e, preorder); 
    }
    root-> left = left_tree;
    root-> right = right_tree;
    return root;
}

void display_preorder(Node *root){
    if(root == NULL)
        return;
    if(root-> left != NULL)
        cout << root-> left-> data;
    else
        cout << ".";
    cout << " -> " << root-> data << " <- ";
    if(root-> right != NULL)
        cout << root-> right-> data << '\n';
    else
        cout << "." << '\n';
    if(root-> left != NULL)
        display_preorder(root-> left);
    if(root-> right != NULL)
        display_preorder(root-> right);                         
}

int main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vi preorder(n);
    for(int i = 0; i < n; i++)
        cin >> preorder[i];        
    Node *root = construct_BST(0, n - 1, preorder);
    display_preorder(root);
}