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

void get_min_max_helper(Node *root, int left_path, int &_max, int &_min){
        if(root == NULL)
            return;
        _max = max(_max, left_path);
        _min = min(_min, left_path);
        get_min_max_helper(root-> left, left_path - 1, _max, _min);
        get_min_max_helper(root-> right, left_path + 1, _max, _min);
}

pair<int, int> get_min_max(Node *root){
    int left_path = 0, _max = INT_MIN, _min = INT_MAX;
    get_min_max_helper(root, left_path, _max, _min);
    pair<int, int> width(_min, _max);
    return width;
}

void get_vertical_order_helper(Node *root, int left_path, vvi &vertical_order, int &_min){
    if(root == NULL)
        return;
    vertical_order[left_path + _min].__emplace_back(root-> data);
    if(root-> left != NULL)
        get_vertical_order_helper(root-> left, left_path - 1, vertical_order, _min);
    if(root-> right != NULL)
        get_vertical_order_helper(root-> right, left_path + 1, vertical_order, _min);      
}

void get_vertical_order(Node *root, vvi &vertical_order, int &_min){
    if(root == NULL)
        return;
    int left_path = 0;
    get_vertical_order_helper(root, left_path, vertical_order, _min);    
}

void get_vertical_order_bfs(Node *root, vvi &vertical_order, int &_min){
    if(root == NULL)
        return;
    queue<pair<Node*, int> > q;
    q.push(mp(root, 0));
    while(!q.empty()){
        auto front = q.front();
        q.pop();
        vertical_order[front.second + _min].__emplace_back(front.first-> data);
        if(front.first-> left != NULL)
            q.push(mp(front.first-> left, front.second - 1));
        if(front.first-> right != NULL)
            q.push(mp(front.first-> right, front.second + 1));       
    }
        
}

int main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Node *root = input();
    pair<int, int> width = get_min_max(root);
    vvi vertical_order(abs(width.first) + abs(width.second) + 1);
    int _min = abs(width.first);
    get_vertical_order_bfs(root, vertical_order, _min);
    for(int i = 0; i < (int) vertical_order.size(); i++){
        cout << i << " -> ";
        for (int j = 0; j < (int)vertical_order[i].size(); j++)
            cout << vertical_order[i][j] << " ";
        cout << '\n';   
    }
}