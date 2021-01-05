#include<iostream>
#include<unordered_map>
#include<list>
#include<vector>
#include<algorithm>
#include<climits>
#include<string>
#include<utility>
#include<queue>
using namespace std;

#define mp make_pair
#define INFI 10e8
#define INF 10e7

typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<pair<int, vi> > vpv;
typedef vector<pi> vp;


class Graph{
public: 
    unordered_map<int, list<pi> > gmap;

    void addEdge(int src, int dest, int weight, bool bidir = true){
        gmap[src].push_back(mp(dest, weight));
        if(bidir){
            gmap[dest].push_back(mp(src, weight));
        }
    }

  void multisolver_helper(int src, int dest, vb &visited, vi path, int total_weight, vpv &all_paths){
        visited[src] = true;
        if(src == dest){
            path.push_back(src);
            for(int i = 0; i < path.size(); i++){
                cout << path[i] << " ";
            }
            cout << "Total Weight: " << total_weight << '\n';
            all_paths.push_back(mp(total_weight, path));
            visited[src] = false;
            return;
        }
        path.push_back(src);
        for(auto neighbour : gmap[src]){
            if(!visited[neighbour.first]){
                multisolver_helper(neighbour.first, dest, visited, path, total_weight + neighbour.second, all_paths);
            }
        }
        visited[src] = false;
    }

    void multisolver(int V, int E, int src, int dest, int criteria, int k){
        vi path;
        vpv all_paths;
        vb visited(V, false);
        int total_weight = 0;
        multisolver_helper(src, dest, visited, path, total_weight, all_paths);
        sort(all_paths.begin(), all_paths.end());
        int just_largest = INT_MIN, just_smallest = INT_MAX;
        for(int i = 0; i < all_paths.size(); i++){
           if(all_paths[i].first >= criteria){
               just_smallest = i - 1;
               if(all_paths[i].first == criteria){
                   just_largest = i + 1;
               }
               else{
                   just_largest = i;
               }
               break;
           }
        }

        cout << '\n' << "Smallest Path = ";
        for(int i = 0; i < all_paths[0].second.size(); i++){
                cout << all_paths[0].second[i];
        }
        cout << "@" << all_paths[0].first << '\n';

        cout << "Largest Path = ";
        for(int i = 0; i < all_paths[all_paths.size() - 1].second.size(); i++){
            cout << all_paths[all_paths.size() - 1].second[i];
        } 
        cout << "@" << all_paths[all_paths.size() - 1].first << '\n';

        cout << "Just Larger Path than " << criteria << " = ";
        for(int i = 0; i < all_paths[just_largest].second.size(); i++){
            cout << all_paths[just_largest].second[i];
        }
        cout << "@" << all_paths[just_largest].first << '\n';

        cout << "Just Smaller Path than " << criteria << " = ";
        for(int i = 0; i < all_paths[just_smallest].second.size(); i++){
            cout << all_paths[just_smallest].second[i];
        }  
        cout << "@" << all_paths[just_smallest].first << '\n';

        cout << k << "th" << " largest path = ";
        for(int i = 0; i < all_paths[all_paths.size() - k].second.size(); i++){
            cout << all_paths[all_paths.size() - k].second[i];
        }
        cout << "@" << all_paths[all_paths.size() - k].first << '\n';
    }

};

int main(){
    std::ios_base::sync_with_stdio(false);
    Graph g;
    int V, E, u, v, w, src, dest, criteria, k;
    cin >> V >> E;
    for(int i = 0; i < E; i++){
        cin >> u >> v >> w;
        g.addEdge(u, v, w);
    }
    cin >> src >> dest >> criteria >> k;
    g.multisolver(V, E, src, dest, criteria, k);

}