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

int get_size(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int sub_tree = 0;
    for (int i = 0; i < root->children.size(); i++)
    {
        sub_tree += get_size(root->children[i]);
    }
    return 1 + sub_tree;
}

int main()
{
    Node *root = input();
    cout << get_size(root) << '\n';
}
