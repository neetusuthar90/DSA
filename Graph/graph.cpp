#include <bits/stdc++.h>
using namespace std;
template <typename T>
class graph
{
public:
    unordered_map<T, list<T>> adj;

    void addEdge(T u, T v, bool direction){
        // direction = 0 undirected graph
        // direction = 1 directed graph

        // connect an edge
        adj[u].push_back(v);

        // If undiecrted graph
        if(direction == 0){
            adj[v].push_back(u);
        }
    }

    void printAdjList(){
        for(auto i:adj){
            cout << i.first << "->";
            for(auto j:i.second){
                cout << j << ",";
            }
            cout << endl;
        }
    }
};

int main(){
    int N,E;
    cout << "Enter the number of nodes: ";
    cin >> N;
    cout << "Enter the number of edges: ";
    cin >> E;

    graph<int> gp;
    for(int i = 0; i < E; i++){
        int u,v;
        cin >> u >> v;
        gp.addEdge(u,v,0);
    } 
    gp.printAdjList();
    return 0;
}

