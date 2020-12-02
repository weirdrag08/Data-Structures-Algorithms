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

int height = 0;
int maximum = INT_MIN;
int minimum = INT_MAX;
int tree_size = 0;

void multisolver(Node *root, int depth){
    if(root == NULL){
        return;
    }

    tree_size++;
    maximum = max(root-> data, maximum);
    minimum = min(root-> data, minimum);
    height = max(depth, height);

    for(int i = 0; i < root-> children.size(); i++){
        multisolver(root-> children[i], depth + 1);
    }
}

int main()
{    
    Node *root = input();
    cout << "Enter the depth: " << '\n';
    int depth;
    cin >> depth;
    multisolver(root, depth);
    cout << "Size of the given tree: " << tree_size << '\n';
    cout << "Maximum data in the given tree: " << maximum << '\n';
    cout << "Minimum data in the given tree: " << minimum << '\n';
    cout << "Height of the given tree: " << height << '\n';
}
