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

class ListNode{
public:
    int val;
    ListNode *next;

    ListNode(int val){
        this->val = val;
        this->next = NULL;
    }
};

// TODO => Write input function

bool isPalindrome(ListNode *head)
{
    stack<ListNode *> my_stack;
    ListNode *slow = head, *fast = head;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    if (fast == NULL)
        while (slow != NULL)
        {
            my_stack.push(slow);
            slow = slow->next;
        }
    else
    {
        slow = slow->next;
        while (slow != NULL)
        {
            my_stack.push(slow);
            slow = slow->next;
        }
    }

    ListNode *temp = head;
    bool palindrome = true;
    while (!my_stack.empty())
    {
        ListNode *top = my_stack.top();
        my_stack.pop();
        if (top->val == temp->val)
        {
            temp = temp->next;
        }
        else
        {
            palindrome = false;
            break;
        }
    }
    return palindrome;
}

int main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ListNode *head = input();
    bool palindrome = isPalindrome(head);
    if(palindrome) cout << "true" << '\n';
    else cout << "false" << '\n';
}