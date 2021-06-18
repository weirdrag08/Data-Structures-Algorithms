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
typedef vector<vector<int> > vvi;
typedef vector<vector<long long> > vvll;
typedef vector<vector<long long int> > vvlli;
typedef vector<vector<bool> > vvb;

class Node{
public:
    char data;
    int prefix;
    vector<Node*> children;
    bool terminal;

    Node(char data){
        this-> data = data;
        this-> prefix = 1;
        this-> children = vector<Node*>(26, NULL);
        this-> terminal = false;
    }    
};

class Trie{
public:
    Node *root;

    Trie(){
        root = new Node('#');
    }    
private:
   void add_helper(Node *root, string word){
       if(word.size() == 0){
           root-> terminal = true;
           return;
       }
       if(root-> children[word[0] - 'a'] == NULL){
           Node *child = new Node(word[0]);
           root-> children[word[0] - 'a'] = child;
       }
       else
            root-> children[word[0] - 'a']-> prefix += 1;
       add_helper(root-> children[word[0] - 'a'], word.substr(1));
   } 

    int find_helper(Node *root, string word){
        if(root == NULL)
            return 0;
        if (word.size() == 0){
            return root->prefix;
        }
        if(root-> children[word[0] - 'a'] == NULL)
            return 0;
        return find_helper(root-> children[word[0] - 'a'], word.substr(1)); 
    }

    void display_helper(Node *root, string path){
        if(root-> data != '#')
            path += root-> data;
        if(root-> terminal)
            cout << path << "prefix: " << root-> prefix << '\n';    
        for(int i = 0; i < (int) root-> children.size(); i++){
            if(root-> children[i] != NULL)
                display_helper(root-> children[i], path);
        }
    }

public:
    void add(string &word){
        add_helper(root, word);
    }

    int find(string &word){
        return find_helper(root, word);
    }

    void display(){
        string path = "";
        display_helper(root, path);
    }
};

int main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Trie t;
    int n;
    cin >> n;
    string cmd, word;
    vi result;
    for(int i = 0; i < n; i++){
        cin >> cmd >> word;
        if(cmd == "add")
            t.add(word);
        else
            result.__emplace_back(t.find(word));   
    }
    for(int i : result)
        cout << i << '\n';
}