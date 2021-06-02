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

vector<int>* NodeToRootPath(Node *root, int &end){
    if(root == NULL)
        return NULL;
    if(root-> data == end){
        vector<int> *base_arr = new vector<int>();
        base_arr-> push_back(end);
        return base_arr;
    }
    vector<int> *left_arr = NULL, *right_arr = NULL;    
    if(root-> left != NULL)
       left_arr = NodeToRootPath(root-> left, end);
    if(root-> right != NULL)
       right_arr = NodeToRootPath(root-> right, end); 

    if(left_arr != NULL){
        left_arr-> push_back(root-> data);
        return left_arr;
    }          
    else if(right_arr != NULL){
        right_arr->push_back(root->data);
        return right_arr;
    }
    else 
        return NULL;
}

int main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Node *root = input();
    int end;
    cin >> end;
    vector<int> * result = NodeToRootPath(root, end);
    if(result != NULL){
        cout << "true" << '\n';
        cout << '[';
        for(int i = 0; i < (int) result-> size(); i++)
            i != result-> size() - 1 ? cout << result-> at(i) << ", " : cout << result-> at(i);
        cout << "]\n";    
    }
    else{
        cout << "false" << '\n';
        cout << "[]" << '\n';
    }
}