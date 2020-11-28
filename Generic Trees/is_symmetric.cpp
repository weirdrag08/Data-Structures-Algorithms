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

// ? Not so optimised
bool is_symmetric2(Node *root){
    if(root == NULL || root-> children.size() == 0){
        return true;
    }

    for(int i = 0, j = root-> children.size() - 1; i < j; i++, j--){
      bool similar = is_similar(root-> children[i], root-> children[j]);
      if(!similar){
          return false;
      }
    }
    bool recursive_symmetric = true;
    for(Node *child : root-> children){
        recursive_symmetric = is_symmetric2(child);
        if(!recursive_symmetric){
            return false;
        }
    }
    return true;
}

//? optimised as freak!
bool is_symmetric(Node *root)
{
    if (root == NULL || root->children.size() == 0)
    {
        return true;
    }

    for (int i = 0, j = root->children.size() - 1; i < j; i++, j--)
    {
       if(root-> children[i]-> children.size() != root-> children[j]-> children.size()){
           return false;
       }
    }
    bool recursive_symmetric = true;
    for (Node *child : root->children)
    {
        recursive_symmetric = is_symmetric(child);
        if (!recursive_symmetric)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    Node *root = input();
    bool output = is_symmetric(root);
    if(output){
        cout << "true" <<'\n';
    }
    else{
        cout << "false" << '\n';
    }
}
