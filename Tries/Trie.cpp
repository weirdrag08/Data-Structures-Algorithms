#include <iostream>
#include <unordered_map>
#include <list>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <string>
#include <climits>
#include <utility>
using namespace std;

#define mp make_pair
#define pb push_back
#define INFI 10e8
#define INF 10e7
#define mod 1000000007
#define sieve_limit 10e6

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<long> vl;
typedef vector<long long> vll;
typedef vector<long long int> vlli;
typedef vector<bool> vb;
typedef vector<vector<int>> vvi;
typedef vector<vector<long long>> vvll;
typedef vector<vector<long long int>> vvlli;
typedef vector<vector<bool>> vvb;

class Node{
 public:

    pair<char, bool> alphabet;
    vector<Node*> *children;
   
    Node(char alphabet){
        this-> alphabet.first = alphabet;
        this-> alphabet.second = false;
        children = new vector<Node*>(26, NULL);
    }
};

class Trie{
 public:    
    Node *root = NULL;

    Trie(){
        root = new Node ('#');
    }
private:
    void addWord_helper(Node *root, string &word, int index){
        if(index == (int) word.size()){
            root-> alphabet.second = true;
        }
          
            if(root-> children-> at(word[index] - 'a') != NULL){
                addWord_helper(root-> children-> at(word[index] - 'a'), word, index + 1);
            }
            else{
                Node *child = new Node(word[index]);
                root-> children-> at(word[index] - 'a') = child;
                addWord_helper(root-> children-> at(word[index] - 'a'), word, index + 1);
            }
    }
public:
    void addWord(string &word){
        int index = 0;
        addWord_helper(root, word, index);
    }

    Node* get_root(){
        return root;
    }
};

int main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Trie t();
    
}