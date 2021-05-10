#include<unistd.h>
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

    pair<char, bool> alphabet;
    vector<Node*> *children;
   
    Node(char alphabet){
        this-> alphabet.first = alphabet;
        this-> alphabet.second = false;
        children = new vector<Node*>(26, NULL);
    }
};

class Trie{    
    Node *root;

public:
    Trie(){
        root = new Node ('#');
    }

    ~Trie(){
        for(int i = 0; i < root-> children-> size(); i++)
            delete(root-> children-> at(i));
    }

private:
    void addWord_helper(Node *root, string &word, int index){
        if(index == (int) word.size() - 1){
            root-> alphabet.second = true;
            return; 
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

    bool search_helper(Node *root, string &word, int index){
        if(index == word.size() - 1)
            return root-> alphabet.second ? true : false;

        bool recursive_ans = false;

        if(root-> children-> at(word[index] - 'a') == NULL)
            return false;

        else
            recursive_ans = search_helper(root-> children-> at(word[index] - 'a'), word, index + 1);
        return recursive_ans;        
    }

    void deleteWord_helper(Node *root, string &word, int index){
        if(index == word.size() - 1)
          root-> alphabet.second = false;
        deleteWord_helper(root-> children-> at(word[index] - 'a'), word, index + 1);  
    }

public:
    void addWord(string &word){
        int index = 0;
        addWord_helper(root, word, index);
    }

    bool search(string &word){
        int index = 0;
        return search_helper(root, word, index);
    }

    void deleteWord(string &word){
        int index = 0;
        deleteWord_helper(root, word, index);
    }

};

int main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    Trie t;
    string words, first, second, third;
    getline(cin, words);
    cout << "Aditya: ";
    getline(cin, first);
    sleep(3);
    cout << "Trie: Oh, Hi dude!, Whatup?" << '\n';
    cout << "Aditya: ";
    getline(cin, second); 
    sleep(2);
    cout << "Trie: I am in a party dude, having fun ヽ(⌐■_■)ノ♪♬" << '\n';
    cout << "Aditya: ";
    getline(cin, third);
    sleep(2);
    cout << "Trie: What do you want from me? A poor data structure can't even rest properly ( ˘︹˘ ), Say?" << '\n';
    sleep(3);
    cout << "Aditya: Nothing much, but if there is any secret message stored inside you, I need it, please diplay it on the console." << '\n';
    sleep(3);
    cout << "Trie: What was it related to?" << '\n';
    sleep(3);
    cout << "Aditya: It's none of your business!" << '\n';
    sleep(3);
    cout << "Trie: Tell me otherwise I won't search it for you! ┐(￣ー￣)┌ " << '\n';
    sleep(3);
    cout << "Aditya: I stored a message for my girlfriend inside you while I was trying to implement you! " << '\n';
    sleep(3);
    cout << "Aditya: Now is the time, that you retrieve it for me, it's like now or never, please find it asap (˘_˘٥)" << '\n';
    sleep(3);
    cout << "Trie: Okay Okay, wait, let me search! " << '\n';
    sleep(3);
    cout << "Aditya: Please search it fast, otherwise why would I prefer you over the sweet Hashmap :-/ " << '\n';
    sleep(3);
    cout << "Aditya: Search it faster bro, I am running out of time here ヾ(-_-;)" << '\n';
    sleep(3);
    cout << "Trie: Hold on! Kid !" << '\n';
    sleep(3);
    cout << "Trie: It's a little messy around here!" << '\n';
    cout << "Aditya: ";
    string f0, f1, f2, f3;
    cin >> f0 >> f1 >> f2 >> f3;
    t.addWord(f0);
    t.addWord(f1);
    t.addWord(f2);
    t.addWord(f3); 

    string s0 = "i";
    string s1 = "love";
    string s2 = "you";
    string s3 = "soooo";
    string s4 = "much";
    string s5 = "ishika";
    
    t.addWord(s0);
    t.addWord(s1);
    t.addWord(s2);
    t.addWord(s3);
    t.addWord(s4);
    t.addWord(s5);
    
    if(t.search(f0) && t.search(f1) && t.search(f2) && t.search(f3)){
        cout << "Trie: Searching." << '\n';
        sleep(4);
        cout << "Trie: Searching.." << '\n';
        sleep(3);
        cout << "Trie: Just a second more please! " << '\n';
        sleep(2);
        cout << "Trie: Have a good day Ishika! Please forgive this idiot." << '\n';
        sleep(2);
        cout << "Trie: It might take some time, but don't worry I will print it for you Ishika ( ˘ ³˘)❤" << '\n';
        sleep(2);
        cout << "Aditya: Stop flirting with her, just display the message dumb trie (•̀o•́)ง" << '\n';
        sleep(2);
        cout << "Trie: Chill dude! ┐(´•_•`)┌" << '\n';
        sleep(4);
        cout << "Trie: Oh, I found your message buddy, Here you go, you two have a good night, I will not disturb in between, I am going to sleep ヽ(•‿•)ノ" << '\n' << '\n';
        sleep(2);
        t.search(s0) ? cout << s0 << " " : cout << "Not found" << " ";
        t.search(s1) ? cout << s1 << " " : cout << "Not found" << " ";
        t.search(s2) ? cout << s2 << " " : cout << "Not found" << " ";
        t.search(s3) ? cout << s3 << " " : cout << "Not found" << " ";
        t.search(s4) ? cout << s4 << " " : cout << "Not found" << " ";
        t.search(s5) ? cout << s5 << " " : cout << "Not found" << " ";

        cout << '\n' << '\n';
    }

    else{
        cout << "Nothing exists in the trie: " << '\n';
    }
}

// Hello Ishika, Consider it my apology for today and a small gift for you!
// Hey Trie, Hello? Are you there dude?
// What you doing?
// Actually I wanted you to do something for me, it's kinda important