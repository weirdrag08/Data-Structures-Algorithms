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
        this-> children = vector<Node*>(10, NULL);
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
    bool insert_helper(Node *root, string word){
        if(root-> terminal && word.size() != 0)
            return false;
        if(word.size() == 0){
            root-> terminal = true;
            return root-> prefix > 1 ? false : true;
        }

        if(root-> children[word[0] - 'a'] == NULL){
            Node *child = new Node(word[0]);
            root-> children[word[0] - 'a'] = child;
        }
        else
            root-> children[word[0] - 'a']-> prefix += 1;
        return insert_helper(root-> children[word[0] - 'a'], word.substr(1));    
    }

public:
    bool insert(string &word, bool &good_set){
        bool good = insert_helper(root, word);
        if(!good_set)
            return false;
        else
            return good;    
    }
        
};

int main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Trie t;
    int n;
    cin >> n;
    string word, result = "";
    bool good_set = true, good;
    for(int i = 0; i < n; i++){
        cin >> word;
        good = t.insert(word, good_set);
        if(good_set && !good)
            result = word, good_set = false;
    }
    if(!good_set)
        cout << "BAD SET" << '\n' << result << '\n';
    else
        cout << "GOOD SET" << '\n';    
}