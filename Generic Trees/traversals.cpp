#include <iostream>
#include <vector>
#include <stack>
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

void traversals(Node *root){
    if(root == NULL){
        return;
    }
    if (root->children.size() == 0){
        cout << "Node Pre " << root-> data << '\n';
        cout << "Node Post "  << root-> data << '\n';
        return;
    }
    cout << "Node Pre " << root-> data << '\n';
    for(int i = 0; i < root-> children.size(); i++){
        cout << "Edge Pre " << root-> data << "--" << root-> children[i]-> data << '\n';
        traversals(root-> children[i]);
        cout << "Edge Post " << root-> data << "--" << root-> children[i]-> data << '\n';
    }
    cout << "Node Post " << root-> data << '\n';
}

int main()
{
    Node *root = input();
    traversals(root);
}
