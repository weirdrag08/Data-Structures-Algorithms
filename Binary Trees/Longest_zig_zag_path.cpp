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

pair<int, int> longest_zig_zag_path_helper(Node *root){
    if(root == NULL){
        pair<int, int> base_pair(-1, -1);
        return base_pair;
    }
    pair<int, int> leftside = longest_zig_zag_path_helper(root-> left);
    pair<int, int> rightside = longest_zig_zag_path_helper(root-> right);

    pair<int, int> my_pair;
    my_pair.first = max(1 + leftside.second, max(leftside.first, leftside.second));
    my_pair.second = max(1 + rightside.first, max(rightside.first, rightside.second));
    return my_pair;
}

int longest_zig_zag_path(Node *root){
    pair<int, int> result = longest_zig_zag_path_helper(root);
    return max(result.first, result.second);
}

int main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Node *root = input();
    cout << longest_zig_zag_path(root) << '\n';
}