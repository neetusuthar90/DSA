#include <iostream>
#include <climits>
using namespace std;

int findMinVertex(int *weights, bool* visited, int n){
    int minVertex = -1;
    for(int i = 0; i <n; i++){
        if(!visited[i] && (minVertex == -1 || weights[i] < weights[minVertex])){
            minVertex = i;
        }
    }
    return minVertex;
}

void prims(int** edges, int n){
    int *parents = new int[n];
    int *weights = new int[n];
    bool *visited = new bool[n];

    for(int i = 0; i < n; i++){
        visited[i] = false;
        weights[i] = INT_MAX;
    }
    parents[0] = -1;
    weights[0] = 0;

    for(int i = 0; i <n; i++){
        // Find min vertex
        int minVertex = findMinVertex(weights, visited,n);
        visited[minVertex] = true;
        // Explore the non visited vertex
        for(int j = 0; j < n; j++){
            if(edges[minVertex][j] != 0 && !visited[j]){
                if(edges[minVertex][j] < weights[j]){
                    weights[i] = edges[minVertex][j];
                    parents[j] = minVertex;
                }
            }
        }
    }

    for(int i = 0; i < n; i++){
        if(parents[i] < i){
            cout << parents[i] << " " << i << weights[i] << endl;
        }else{
            cout << i << " " << parents[i] << weights[i] << endl;
        }
    }
    
}

int main(){
    int n, E;
    cin >> n >> E;
    int **edges = new int*[n];
    for(int i = 0; i <n; i++){
        edges[i] = new int[n];
        for(int j = 0; j <n; j++){
            edges[i][j] = 0;
        }
    }
    for(int i = 0; i < E; i++){
        int s,d,weight;
        cin >> s >> d >> weight;
        edges[s][d] = weight;
        edges[d][s] = weight;
    }
    prims(edges,n);
    for(int i = 0; i < n; i++){
        delete [] edges[i];     
    }
    delete [] edges;
}