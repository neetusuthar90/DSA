#include <bits/stdc++.h>
using namespace std;

void DFS(int node, unordered_map<int,bool> &visited, unordered_map<int,list<int>> &adj,vector<int> &component){
    component.push_back(node);
    visited[node] = 1;
    for(auto i:adj[node]){
        if(!visited[i]){
            DFS(i,visited,adj,component);
        }
    }
}

vector<vector<int>> depthFirstSearch(int V, int E, vector<pair <int,int>> &edges){
    unordered_map<int,list<int>> adj;
    for(int i=0; i< edges.size();i++){
        int u= edges[i].first;
        int v= edges[i].second;
        
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<vector<int>> ans;
    unordered_map<int,bool> visited;

    for(int i = 0; i < V; i++){
        if(!visited[i]){
            vector<int> component;
            DFS(i,visited,adj,component);
            ans.push_back(component);
        }
    }
    return ans;
}

int main(){
    int V = 5;
    int E = 6;
    vector<pair <int,int>> edges = {
        {0,4},{4,2},{2,3},{3,5},{5,1},{1,4}
    };

    vector<vector<int>> ans;
    ans = depthFirstSearch(V,E,edges);
    for(int i = 0; i < ans.size();i++){
        for(int j = 0; j < ans[0].size(); j++){
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}