#include <iostream>
#include <unordered_map>
#include <list>
#include <vector>
#include <climits>
#include <algorithm>
#include <stack>
#include <queue>
#include <string>
#include <utility>
using namespace std;

#define mp make_pair
#define INFI 10e8
#define INF 10e7

typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<bool> vb;

int main()
{
    unordered_map<string, string> start, route;
    int n;
    cin >> n;
    string src, dest;
    for (int i = 0; i < n; i++)
    {
        cin >> src >> dest;
        route[src] = dest;
        start[src] = dest;
    }

    for (auto travel : route)
    {
        if (start.count(travel.second) > 0)
        {
            start.erase(travel.second);
        }
    }

    unordered_map<string, string>::iterator it = start.begin();
    cout << it->first;
    while (!route.empty())
    {
        cout << " -> " << it->second;
        auto new_it = route.find(it->second);
        if (new_it == route.end())
        {
            break;
        }
        route.erase(it->first);
        it = new_it;
    }
    cout << "." << '\n';
}