#include<iostream>
#include<unordered_map>
#include<list>
#include<climits>
#include<utility>
#include<algorithm>
#include<queue>
#include<string>
#include<vector>
using namespace std;

#define mp make_pair
#define INFI 10e8
#define INF 10e7

typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<vector<int>> vvi;


// * Used in sort function ==> sort(begin(), end(), compare)
/*
bool compare(const obj &o1, const obj &o2){
    return o1.property < o2.property;
}
*/
// * customised compare function for in-built sort function, in case of object sorting (sorting objects on the basis of one of it's property)
// * o1.property < o2.property ==> sorts the objects in increasing order on the basis of selected property, for decreasing order we do o1.property > o2.property
// * The function simply return true or false on the basis of arrangement of object. The below function will return true, when o1 will come before o2 in the array, otherwise it will return false.




// * Used in priority queue ==> priority_queue<object, vector<object>, compare> pq;
/*
struct compare{
    bool operator()(const obj &o1, const obj &o2){
        return o1.property > o2.property;
    }
};
*/
// * Customised compare parameter/function for priority queue, in case of object sorting(Sorting objects on the basis of one of it's property)
//* o1.property > o2.property ==> sorts the object in increasing order on the basis of selected property, for decreasing order we do o1.property < o2.property 
// * The function returns true or false on the basis of arrangement of objects in priority queue. The above function will return true, when o1 will come after o2 in the priority queue, otherwise it will return false. 


class Graph{
public:
    unordered_map<int, list<pi> > gmap;

    void addEdge(int src, int dest, int weight, bool bidir = true){
        gmap[src].push_back(mp(dest, weight));
        if(bidir){
            gmap[dest].push_back(mp(src, weight));
        }
    }

    void all_path(int V, int E, int src, int dest, vb* visited){
            visited-> at(src) = true;
            if(src == dest){
              cout << src << '\n';
            }
        
        for(auto neighbour : gmap[src]){
            if(!visited-> at(src)){
                all_path(V, E, neighbour.first, dest, visited);
                cout << 
                visited-> at(neighbour.first) = true;
            }
        }
    }

};


int main(){

}