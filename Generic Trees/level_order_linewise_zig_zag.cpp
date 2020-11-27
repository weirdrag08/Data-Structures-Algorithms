#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

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

void level_order_linewise_zig_zag(Node *root){
   vector<Node*> v;
   queue<Node*> q;
    int level = 1, order = 0;
    if(root == NULL){
        return;
    }
        q.push(root);
        order++;
        while(!q.empty()){
            Node *front = q.front();
            level--;
            for(int i = 0; i < front-> children.size(); i++){
                q.push(front-> children[i]);
                v.push_back(front-> children[i]);
            }
        if(order % 2 != 0){
            for(int i = v.size() - 1; i >= 0; i--){
                cout << v[i]-> data << ' ';
            }
        }
        else{
            for(int i = 0; i < v.size(); i++){
                cout << v[i]-> data << ' ';
            }
        }
    }
}

int main()
{
    Node *root = input();
    level_order_linewise_zig_zag(root);
}
