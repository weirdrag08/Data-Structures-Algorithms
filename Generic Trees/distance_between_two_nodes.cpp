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
        base_arr-> push_back(data);
        return base_arr;
    }
    // * When you are done with the code, do this by the vector size constraint!
    vector<int> *recursive_path = NULL;
    for(Node *child : root-> children){
        recursive_path = node_to_root_path(child, data);
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


int distance(Node *root, int data1, int data2){
    if(root == NULL){
        return -1;
    }
    vector<int> *distance1 = node_to_root_path(root, data1);
    vector<int> *distance2 = node_to_root_path(root, data2);
    if(distance1 == NULL || distance2 == NULL){
     return -1;
    }
    int i = distance1-> size() - 1, j = distance2-> size() - 1;
    while(i >= 0 && j >= 0 && distance1-> at(i) == distance2-> at(j)){
        distance1-> erase(distance1-> begin() + i);
        distance2-> erase(distance2-> begin() + j);
        i--;
        j--;
    }
    return distance1-> size() + distance2-> size();
}

int main()
{
    Node *root = input();
    int data1, data2;
    cin >> data1 >> data2;
    cout << distance(root, data1, data2) << '\n'; 
}


