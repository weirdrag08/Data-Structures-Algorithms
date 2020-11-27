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

vector<int>* node_to_root_path(Node *root, int data){
    if(root == NULL){
        return NULL;
    }
    if(root-> data == data){
        vector<int> *base_arr = new vector<int>();
        base_arr-> push_back(root-> data);
        return base_arr;
    }

    vector<int> *recursive_path = NULL;

    for(int i = 0; i < root-> children.size(); i++){
        recursive_path = node_to_root_path(root-> children[i], data);
        if(recursive_path != NULL){
            break;
        }
    }
    if(recursive_path != NULL){
        recursive_path-> push_back(root-> data);
        return recursive_path;
    }
    else{
        return NULL;
    }
}

int main()
{
    Node *root = input();
    int data;
    cin >> data;
    vector<int> *final_path = node_to_root_path(root, data);
    if(final_path == NULL){
        cout << "[]" << '\n';
    }
    else{
        cout << "[";
        for (int i = 0; i < final_path->size(); i++)
        {
            if (i != final_path->size() - 1)
            {
                cout << final_path->at(i) << ", ";
            }
            else
            {
                cout << final_path->at(i);
            }
        }
        cout << "]" << '\n';
    }
}
