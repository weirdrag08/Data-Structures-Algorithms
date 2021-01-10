#include <iostream>
#include <queue>
#include <vector>
#include<unordered_map>
#include<map>
#include<algorithm>
#include<climits>
#include<stack>
#include<string>
#include<utility>
using namespace std;

#define mp make_pair
#define INFI 10e8
#define INF 10e7

typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef long long ll;

int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, element, k;
    cin >> n;
    priority_queue<int> pq;
    for (int i = 0; i < n; i++)
    {
        cin >> element;
        pq.push(element);
    }
    cin >> k;
    vi v;
    for (int i = 0; i < k; i++){
        int element = pq.top();
        v.push_back(element);
        pq.pop();
    }
    for (int i = v.size() - 1; i >= 0; i--)
    {
        cout << v[i] << '\n';
    }
}