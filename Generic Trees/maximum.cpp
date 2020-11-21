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

int get_max(Node *root)
{
    if (root == NULL || root->children.size() == 0)
    {
        return root->data;
    }
    int sub_max = INT_MIN;
    for (int i = 0; i < root->children.size(); i++)
    {
        sub_max = max(sub_max, get_max(root->children[i]));
    }
    int maximum = max(root->data, sub_max);
    return maximum;
}

int main()
{
    Node *root = input();
    cout << get_max(root) << '\n';
}
