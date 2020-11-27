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
void mirror_tree(Node *root){
    if(root == NULL || root-> children.size() ==  0){
        return;
    }
    for(int i = 0; i < root-> children.size(); i++){
        mirror_tree(root-> children[i]);
    }
    reverse(root-> children.begin(), root-> children.end());
}

void display(Node *root)
{
    cout << root->data << " ==> {";
    for (int i = 0; i < root->children.size(); i++)
    {
        cout << root->children[i]->data << ',';
    }
    cout << ".}" << '\n';
    for (int i = 0; i < root->children.size(); i++)
    {
        display(root->children[i]);
    }
}

int main()
{
    Node *root = input();
    display(root);
    mirror_tree(root);
    display(root);
}
