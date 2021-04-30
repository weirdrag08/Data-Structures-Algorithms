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

class Graph
{
    unordered_map<int, vector<pi> > gmap;

public:
    void addEdge(int src, int dest, int weight, bool bidir = true)
    {
        gmap[src].push_back(mp(dest, weight));
        if (bidir)
        {
            gmap[dest].push_back(mp(src, weight));
        }
    }

private:
    bool schedule_finish_helper(int start, int courses, vb &visited, stack<int> &order, stack<int> &path, vb &in_stack)
    {
        visited[start] = true;
        path.push(start);
        in_stack[start] = true;
        for (auto neighbour : gmap[start])
        {
            if (visited[neighbour.first] && in_stack[neighbour.first])
            {
                cout << neighbour.first << '\n';
                return false;
            }

            else if (!visited[neighbour.first])
            {
                bool recursive_ans = schedule_finish_helper(neighbour.first, courses, visited, order, path, in_stack);
                if (!recursive_ans)
                    return false;
            }
        }
        order.push(start);
        path.pop();
        in_stack[start] = false;
        return true;
    }

public:
    bool schedule_finish(int courses)
    {
        vb visited(courses, false), in_stack(courses, false);
        stack<int> order, path;
        for (int i = 0; i < courses; i++)
        {
            if (!visited[i])
            {
                bool ans = schedule_finish_helper(i, courses, visited, order, path, in_stack);
                if (!ans)
                    return ans;
            }
        }
        return true;
    }
};


    bool canFinish(int numCourses, vector<vector<int> > &prerequisites){
        Graph g;
        for (int i = 0; i < (int)prerequisites.size(); i++)
        {
            g.addEdge(prerequisites[i][0], prerequisites[i][1], 1, false);
        }
        return g.schedule_finish(numCourses);
    }


int main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int numCourses, relations, u, v;
    cin >> numCourses >> relations;
    vvi prerequisites(relations, vi(2));
    for(int i = 0; i < (int) relations; i++){
        cin >> u >> v;
        prerequisites[i][0] = u;
        prerequisites[i][1] = v;
    }
    cout << boolalpha << canFinish(numCourses, prerequisites);
}