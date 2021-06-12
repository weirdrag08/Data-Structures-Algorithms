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

void inorder_traversal_helper(Node *root, vector<int> &inorder){
    if(root == NULL)
        return;
    if(root-> left != NULL)
        inorder_traversal_helper(root-> left, inorder);
        inorder.pb(root-> data);
    if(root-> right != NULL)
        inorder_traversal_helper(root-> right, inorder);         
}

void inorder_traversal(Node *root){
    vector<int> inorder;
    inorder_traversal_helper(root, inorder);
     bool sorted = true;
    for(int i = 1; i < (int) inorder.size(); i++){
        if(inorder[i] < inorder[i - 1]){
            sorted = false;
            break;
        }
    }
    sorted ? cout << "true" << '\n' : cout << "false" << '\n';
}

bool inorder_traversal2(Node *root){
    static Node *prev = NULL;
    if(root == NULL)
        return true;
   bool leftside = inorder_traversal2(root-> left);
   if(!leftside)
        return false;
    if(prev != NULL){
        if(root-> data <= prev-> data)
            return false;
    }     
    prev = root;
    bool rightside = inorder_traversal2(root-> right);
    if(!rightside)
        return false;
    return true;    
}

int main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Node *root = input();
    cout << boolalpha << inorder_traversal2(root) << '\n';
   
}