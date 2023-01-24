#include <bits/stdc++.h>
using namespace std;

void  preparedAdjList ( unordered_map<int,set<int>> &adjList, vector<pair<int, int>> &edges){
    for(int i=0; i<edges.size();i++){
        int u= edges[i].first;
        int v= edges[i].second;
        
        adjList[u].insert(v);
        adjList[v].insert(u);
    }
}


void BFS(unordered_map<int, set<int>> &adj, unordered_map<int,bool> &visited, vector<int> &ans,int node){
    queue<int> q;
    q.push(node);
    visited[node] = 1;
    
    while (!q.empty())
    {
        int frontNode = q.front();
        q.pop();

        //store front into ans
        ans.push_back(frontNode);

        // Add neighbour nodes into queue
        for(auto i:adj[frontNode]){
            if(!visited[i]){
                q.push(i);
                visited[i] = 1;
            }
        }
    }
}

vector<int> bfs(int vertex, vector<pair<int, int>> edges)
{
    unordered_map<int,set<int>> adjList;
    vector<int> ans;
     unordered_map<int,bool> visited;
    
    preparedAdjList(adjList,edges);
    // traverse all components
    for(int i =0;i<vertex;i++){
        if(!visited[i]){
            BFS(adjList,visited,ans,i); 
        }
    }
   return ans; 
}

int main(){
    int N = 5;
    vector<pair <int,int>> edges = {
        {0,1},{0,3},{4,4},{1,2},{2,3}
    };

    vector<int>
    ans = bfs(N,edges);
    for(int i = 0; i < ans.size();i++){
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}