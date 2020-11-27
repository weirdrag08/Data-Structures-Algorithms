#include <iostream>
#include <vector>
#include <stack>
#include<queue>
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

void level_order(Node *root){
    if(root == NULL){
        return;
    }
    queue<Node*> *q = new queue<Node*>;
    q-> push(root);
    while(!q-> empty()){
        Node* front = q-> front();
        q-> pop();
        cout << front-> data << ' ';
        for(int i = 0; i < front-> children.size(); i++){
            q-> push(front-> children[i]);
        }
    }
    cout << '.';
}

int main()
{
    Node *root = input();
    level_order(root);
}
