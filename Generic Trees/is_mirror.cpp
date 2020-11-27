#include <iostream>
#include <vector>
#include <stack>
#include<algorithm>
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

void mirror(Node *root){
    if (root == NULL || root-> children.size() == 0)
    {
        return;
    }
   for(Node *child : root-> children){
       mirror(child);
   }
    reverse(root-> children.begin(), root-> children.end());
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

// ? More optimised way 
bool is_mirror(Node *root1, Node *root2){
    if(root1 == NULL && root2 == NULL){
        return true;
    }
    if(root1-> children.size() != root2-> children.size()){
        return false;
    }
    bool mirror = true;
    for(int i = 0, j = root2-> children.size() - 1; i < j; i++, j--){
         mirror = is_similar(root1-> children[i], root2-> children[j]);
       if(!mirror){
           break;
       }
    }
    if(!mirror){
        return false;
    }
    else{
        return true;
    }
}

// ? Not so optimised
bool is_mirror2(Node *root1, Node *root2){
    if(root1 == NULL && root2 == NULL){
        return true;
    }
    mirror(root1);
    return is_similar(root1, root2);
}



int main()
{
    Node *root1 = input();
    Node *root2 = input();
    bool mirror = is_mirror(root1, root2);
    if(mirror){
        cout << "true" << '\n';
    }
    else{
        cout << "false" << '\n';
    }
}
