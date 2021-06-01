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
        Node *child = root-> children[word[0] - 'a'];
        if(child-> terminal)
            return;
         bool has_child = false;
        for(int i = 0; i < (int) child-> children.size(); i++){
            if(child-> children[i] != NULL){
                has_child = true;
                break;
            }
        }
        if(has_child)
            return;
        else{
            Node *temp = child;
            root-> children[word[0] - 'a'] = NULL;
            delete temp;
        }
    }
    
    void searchSuggestions_helper(Node *root, string word, vector<string> &char_suggest, int &count, string path){
        if(count == 0)
            return;
        
        if(word.size() == 0){
            path += root-> data;
            if(root-> terminal){
                char_suggest.push_back(path);
                count--;
            }
            for(int i = 0; i < (int) root-> children.size(); i++){
                if(root-> children[i] != NULL)
                    searchSuggestions_helper(root-> children[i], word, char_suggest, count, path);  
            }  
        }
        
        else{
            if(root-> data != '#')
            path += root-> data;
        
            if(root-> children[word[0] - 'a'] == NULL)
            return;
            searchSuggestions_helper(root-> children[word[0] - 'a'], word.substr(1), char_suggest, count, path);
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
    
    void searchSuggestions(string word, vector<string> &char_suggest){
        int count = 3;
        string path = "";
        searchSuggestions_helper(root, word, char_suggest, count, path);
    }
};



int main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);

        int size;
        cin >> size;
        vector<string> products(size);
        string searchWord = "";
        for(int i = 0; i < size; i++)
            cin >> products[i];
        cin >> searchWord;
        Trie t;
        vector<vector<string> > total_suggestions;
        for(int i = 0; i < (int) products.size(); i++)
            t.insert(products[i]);
        for(int i = 1; i <= searchWord.size(); i++){
            vector<string> char_suggest;
            t.searchSuggestions(searchWord.substr(0, i), char_suggest);
            total_suggestions.push_back(char_suggest);
        }
    for(int i = 0; i < (int) total_suggestions.size(); i++){
        for(int j = 0; j < (int) total_suggestions[i].size(); j++){
            cout << total_suggestions[i][j] << " ";
        }
        cout << '\n';
    }   
}