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

class Node
{
public:
    int data;
    vector<Node *> children;

    Node(int data)
    {
        this->data = data;
    }
};

Node *input()
{
    stack<Node *> *stk = new stack<Node *>;
    int element, root_data, size;
    cin >> size >> root_data;
    Node *root = new Node(root_data);
    stk->push(root);
    while (!stk->empty())
    {
        cin >> element;
        if (element == -1)
        {
            stk->pop();
        }
        else
        {
            Node *new_node = new Node(element);
            stk->top()->children.push_back(new_node);
            stk->push(new_node);
        }
    }
    return root;
}

int calc_diameter(Node *root, int &diameter){
    if(root == NULL)
        return 0;
    int _max = 0, _max2 = 0;
    for(Node* child : root-> children){
        int recursive_ans = calc_diameter(child, diameter);
        if(recursive_ans > _max){
            _max2 = _max;
            _max = recursive_ans;
        }
        else if(_max >= recursive_ans && _max2 < recursive_ans)
            _max2 = recursive_ans;
    }
    diameter = max(diameter, _max + _max2);
    return 1 + _max;
}

int main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Node *root = input();
    int diameter = 0;
    calc_diameter(root, diameter);
    cout << diameter << '\n';
}