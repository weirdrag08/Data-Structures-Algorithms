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

class ans{
public:
    int data, nodes, _min, _max;
    bool bst;

    ans(){
        this-> data = -1;
        this-> bst = true;
        this-> nodes = 0;
        this-> _min = INT_MAX;
        this-> _max = INT_MIN;
    }
};

ans* largest_BST_helper(Node *root, pair<int, int> *result){
    if(root == NULL){
        ans *base_pair = new ans();
        return base_pair;
    }
        ans *leftside = NULL, *rightside = NULL;
        leftside = largest_BST_helper(root-> left, result);
        rightside = largest_BST_helper(root-> right, result); 
        ans *curr_pair = new ans();
        if(leftside-> bst && rightside-> bst && root-> data > leftside-> _max && root-> data < rightside-> _min){
            curr_pair-> data = root-> data;
            curr_pair-> nodes = 1 + leftside-> nodes + rightside-> nodes;
            curr_pair-> _min = min(root-> data, min(leftside-> _min, rightside-> _min));
            curr_pair-> _max = max(root-> data, max(leftside-> _max, rightside-> _max));
        }
        else{
            curr_pair-> bst = false;
            curr_pair-> data = root-> data;
            curr_pair-> nodes = 1 + leftside-> nodes + rightside-> nodes;
            curr_pair->_min = min(root->data, min(leftside->_min, rightside->_min));
            curr_pair->_max = max(root->data, max(leftside->_max, rightside->_max));
        }
        if(curr_pair-> bst && result-> second < curr_pair-> nodes){
            result-> first = curr_pair-> data;
            result-> second = curr_pair-> nodes;
        }
        return curr_pair;   
}

pair<int, int>* largest_BST(Node *root){
    pair<int, int> *result = new pair<int, int>(-1, 0);
    largest_BST_helper(root, result);
    return result;
}

int main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Node *root = input();
    pair<int, int> *result = largest_BST(root);
    cout << result-> first << "@" << result-> second << '\n';
}