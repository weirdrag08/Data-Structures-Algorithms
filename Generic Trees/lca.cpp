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

// bool find(Node *root, int data)
// {
//     if (root == NULL)
//     {
//         return false;
//     }
//     if (root->data == data)
//     {
//         return true;
//     }
//     bool found = false;
//     for (int i = 0; i < root->children.size(); i++)
//     {
//         found = find(root->children[i], data);
//         if (found == true)
//         {
//             break;
//         }
//     }
//     if (found)
//     {
//         return true;
//     }
//     else
//     {
//         return false;
//     }
// }

// int lca(Node *root, int data1, int data2){
//     if(root == NULL){
//         return -1;
//     }
//     bool output1 = find(root, data1);
//     bool output2 = find(root, data2);
//     if(root-> data == data1 || root-> data == data2){
//         if(root-> data == data1){
//             bool found2 = false;
//                 for(int i = 0; i < root-> children.size(); i++){
//                     if(root-> children[i]-> data == data2){
//                         found2 = true;
//                         break;
//                     }
//                 }
//                 if(found2){
//                     return root-> data;
//                 }
//         }

//         else{
//             bool found1 = false;
//             for(int i = 0; i < root-> children.size(); i++){
//                 if(root-> children[i]-> data == data1){
//                     found1 = true;
//                 }
//             }
//             if (found1)
//             {
//                 return root->data;
//             }
//         }
//     }
//     else{
//         if ((output1 && !output2) || (!output1 && output2) || (!output1 && !output2))
//         {
//             return -1;
//         }
//         else{
//            for(int i = 0; i < root-> children.size(); i++){
//                if(root-> children[i]-> data == data1 || root-> children[i]-> data == data2){
//                    return root-> data;
//                }
//            }
//         } 
//     }
//     bool found1 = false;
//     bool found2 = false;
//     for(int i = 0; i < root-> children.size(); i++){
//         if(root-> children[i]-> data == data1){
//             found1 = true;
//         }
//         if(root->children[i]-> data == data2){
//             found2 = true;
//         }
//     }

//     if(found1 && found2){
//         return root-> data;
//     }

//     int output = -1;
//     for(int i = 0; i < root-> children.size(); i++){
//         output = lca(root-> children[i], data1, data2);
//         if(output != -1){
//             break;
//         }
//     }
//     if(output != -1){
//         return output;
//     }
//     else{
//         return -1;
//     }
// }

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

int lca(Node *root, int data1, int data2){
    vector<int> *path1 = node_to_root_path(root, data1);
    vector<int> *path2 = node_to_root_path(root, data2);
  
//    for(int i : *path1){
//        cout << i << ' ';
//    }
//    cout << '\n';
//    for(int i : *path2){
//        cout << i << ' ';
//    }
//    cout << '\n';

    int i = path1-> size() - 1, j = path2-> size() - 1;
    while (i >= 0 && j >= 0 && path1->at(i) == path2->at(j))
    {
        i--;
        j--;
    }
    return path1-> at(i + 1);

}

int main()
{
    Node *root = input();
    int data1, data2;
    cin >> data1 >> data2;
    cout << lca(root, data1, data2);
    cout << '\n';
}
