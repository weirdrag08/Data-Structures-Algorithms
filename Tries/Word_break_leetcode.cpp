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
    vector<Node*> children;
    bool terminal;

    Node(char data){
        this-> data = data;
        this-> children = vector<Node*>(26, NULL);
        terminal = false;
    }
};

class Trie{
public:
    Node *root;

    Trie(){
        root = new Node('#');
    }

private:

    void insert_helper(Node *root, string word){
        if(word.size() == 0){
            root-> terminal = true;
            return;
        }
        if(root-> children[word[0] - 'a'] == NULL){
            Node *child = new Node(word[0]);
            root-> children[word[0] - 'a'] = child;
        }
        insert_helper(root-> children[word[0] - 'a'], word.substr(1));
    }

    bool search_helper(Node *root, string word){
        if(word.size() == 0)
            return root-> terminal ? true : false;

        if(root-> children[word[0] - 'a'] == NULL)
            return false;

        return search_helper(root-> children[word[0] - 'a'], word.substr(1));
    }

    void remove_helper(Node *root, string word){
        if(word.size() == 0){
            root-> terminal = false;
            return;
        }
        if(root-> children[word[0] - 'a'] == NULL)
            return;

        remove_helper(root-> children[word[0] - 'a'], word.substr(1));   
        if(root-> children[word[0] - 'a']-> terminal)
           return; 
        bool leaf = true;
        for(int i = 0; i < 26; i++){
            if(root-> children[word[0] - 'a']-> children[i] != NULL){
                leaf = false;
                break;
            }
        }
        if(leaf){
            Node *temp = root-> children[word[0] - 'a']; 
            root-> children[word[0] - 'a'] = NULL;
            delete temp; 
        }    
    }
    void display_helper(Node *root, string word)
    {
        if (root == NULL)
            return;
        if (root-> terminal)
        {
            string temp = word + root->data;
            cout << temp << endl;
        }

        for (int i = 0; i < 26; i++)
        {
            string temp = word + root->data;
            display_helper(root->children[i], temp);
        }
    }

public:
    void insert(string word){
        insert_helper(root, word);
    }  

    bool search(string word){
       return search_helper(root, word);
    }  
    
    void remove(string word){
        remove_helper(root, word);
    }

    void display(){
        string word = "";
        display_helper(root, word);
    }
};

int main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Trie t;
    int n;
    cin >> n;
    string word, sentence;
    for(int i = 0; i < n; i++){
        cin >> word;
        t.insert(word);
    }
    cin >> sentence;
    vll wordBreak((int) sentence.size(), 0);

    for(int i = 0; i < (int) sentence.size(); i++){
        for(int j = 0; j <= i; j++){
            string suffix = sentence.substr(j, i + 1 - j);
            if(t.search(suffix)){
                if(j == 0)
                    wordBreak[i] += 1;
                else
                    wordBreak[i] += wordBreak[j - 1];
            }
        }
    }
    cout << wordBreak[(int) sentence.size() - 1] << '\n';
}