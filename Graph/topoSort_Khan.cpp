#include <bits/stdc++.h>
using namespace std;

vector<int> topoSortKhanAlgo(vector<vector<int>> &edges, int v, int e){
    unordered_map<int, list<int>> adj;
    for(int i = 0; i < e; i++){
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
    }

    vector<int> indegree(v,0);
    for(auto i:adj){
        for(auto j:i.second){
            indegree[j]++;
        }
    }

    queue<int> q;
    for(int i = 0; i <= v; i++){
        if(indegree[i] == 0){
            q.push(i);
        }
    }
    vector<int> visited;
    vector<int> ans;
    while (!q.empty()){
        int front = q.front();
        q.pop();
        ans.push_back(front);

        for(auto nbd:adj[front]){
            indegree[nbd]--;
            if(indegree[nbd] == 0){
                q.push(nbd);
            }
        }
    }
    return ans;
}

int main(){
    vector<vector<int>> edges = {
        {5,2},{5,0},{4,0},{4,1},{2,3},{3,1}
    };
    int v = 6;
    int e = 6;
    vector<int> ans = topoSortKhanAlgo(edges,v,e);
    for(int i = 0; i < v; i++){
        cout << ans[i] << " ";
    }
    cout << endl;
}