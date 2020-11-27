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

bool is_similar(Node *root1, Node *root2){
    if(root1 == NULL && root2 == NULL){
        return true;
    }

    if(root1-> children.size() != root2-> children.size()){
        return false;
    }
    bool similar = true;
    for(int i = 0; i < root1-> children.size(); i++){
       similar = is_similar(root1-> children[i], root2-> children[i]);
       if(!similar){
           break;
       }
    }
    if(!similar){
        return false;
    }
    else{
        return true;
    }
}

int main()
{
    Node *root1 = input();
    Node *root2 = input();
    bool output = is_similar(root1, root2);
    if(output){
        cout << "true" <<'\n';
    }
    else{
        cout << "false" << '\n';
    }
}
