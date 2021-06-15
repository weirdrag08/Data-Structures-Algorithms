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

    Node(int data, Node *left, Node *right){
        this-> data = data;
        this-> left = left;
        this-> right = right;
    }    
};

class triplet{
public:
    int level, col;
    Node *node;

    triplet(Node *val, int level, int col){
        this-> level = level;
        this-> col = col;
        this-> node = new Node(val-> data, val-> left, val-> right);
    }
};

bool compare(const triplet &a, const triplet &b){
    if(a.level == b.level)
        return a.node-> data < b.node-> data ? true : false;
    return a.level < b.level ? true : false;
}

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

void get_vertical_order_helper(Node *root, int &_min, int &_max, unordered_map<int, vector<triplet> > &vertical_order){
    queue<triplet> q;
    triplet root_triplet(root, 0, 0);
    q.push(root_triplet);
    while(!q.empty()){
        triplet front = q.front();
        q.pop();
        _min = min(_min, front.col);
        _max = max(_max, front.col);
        vertical_order[front.col].__emplace_back(front);
        if(front.node-> left != NULL){
            triplet left_triplet(front.node-> left, front.level + 1, front.col - 1);
            q.push(left_triplet);
        }
        if(front.node-> right != NULL){
            triplet right_triplet(front.node-> right, front.level + 1, front.col + 1);
            q.push(right_triplet);
        }
    }
}

void get_vertical_order(Node *root){
    if(root == NULL)
        return;
    int _min = INT_MAX, _max = INT_MIN;
    unordered_map<int, vector<triplet> > vertical_order;
    get_vertical_order_helper(root, _min, _max, vertical_order);  
    vector<vector<triplet> > trip_arr(1 + abs(_min) + _max);
    for(int i = _min; i <= _max; i++){
        for(int j = 0; j < (int) vertical_order[i].size(); j++)
            trip_arr[i + abs(_min)].__emplace_back(vertical_order[i][j]);
    }
    
    for(int i = 0; i < (int) trip_arr.size(); i++)
        sort(trip_arr[i].begin(), trip_arr[i].end(), compare);

    for(int i = 0; i < (int) trip_arr.size(); i++){
        cout << i << " -> ";
        for(int j = 0; j < (int) trip_arr[i].size(); j++){
            cout << trip_arr[i][j].node-> data << " ";
        }
        cout << '\n';
    }
}

int main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Node *root = input();
    get_vertical_order(root);
}