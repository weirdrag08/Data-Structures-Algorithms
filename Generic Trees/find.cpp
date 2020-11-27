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

bool find(Node *root, int data){
    if(root == NULL){
        return false;
    }
    if(root-> data == data){
        return true;
    }
    bool found = false;
    for(int i = 0; i < root-> children.size(); i++){
         found = find(root-> children[i], data);
        if(found == true){
            break;
        }
    }
    if(found){
        return true;
    }
    else{
        return false;
    }
}
int main()
{
    Node *root = input();
    int data;
    cin >> data;
    bool found = find(root, data);
    if(found){
        cout << "true" << '\n';
    }
    else{
        cout << "false" << '\n';
    }
}
