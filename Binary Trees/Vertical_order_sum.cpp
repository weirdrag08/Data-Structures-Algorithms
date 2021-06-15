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

void get_vertical_order_sum_helper(Node *root, int &_min, int &_max, unordered_map<int, int> &vertical_order_sum){
    if(root == NULL)
        return;
    queue<pair<Node*, int> > q;    
    q.push(mp(root, 0));
    while(!q.empty()){
        pair<Node*, int> front = q.front();
        q.pop();

        _min = min(_min, front.second);
        _max = max(_max, front.second);

        vertical_order_sum[front.second] += front.first-> data;
        if(front.first-> left != NULL)
            q.push(mp(front.first-> left, front.second - 1));
        if(front.first-> right != NULL)
            q.push(mp(front.first-> right, front.second + 1));    
    }
}

int get_vertical_order_sum(Node *root){
    int _min = INT_MAX, _max = INT_MIN;
    unordered_map<int, int> vertical_order_sum;
    get_vertical_order_sum_helper(root, _min, _max, vertical_order_sum);
    for(int i = _min; i <= _max; i++)
        cout << vertical_order_sum[i] << '\n';
}

int main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Node *root = input();
    get_vertical_order_sum(root);
}