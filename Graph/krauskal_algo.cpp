#include <iostream>
#include "Edge.h"
#include <algorithm>
using namespace std;

bool weightSort(Edge e1, Edge e2){
    return e1.weight < e2.weight;
}

int findParent(int v, int *parent){
    if(parent[v] == v){
        return v;
    }
    return findParent(parent[v], parent);
}

void kruskals(Edge *input , int n, int E){

    // Step 1.
    sort(input, input+E, weightSort);
    
    // Step 2.
    Edge *output = new Edge[n-1];

    int *parent = new int[n];
    for(int i = 0; i < n; i++){
        parent[i] = i;
    }
    int count = 0;
    int i = 0;

    // Step 3.
    while (count < (n-1))
    {
        Edge cur_edge = input[i];
        int source_parent = findParent(cur_edge.source, parent);
        int dest_parent = findParent(cur_edge.dest, parent);
        
        if(source_parent != dest_parent){
            output[count] = cur_edge;
            count++;
            parent[source_parent] = dest_parent;
        }
        else{
            i++;
        }
    }
    
    // Step 4.
    cout << "Minimum spanning tree:" << endl;
    for(int i = 0; i < (n-1); i++){
        cout << output[i].source << " " << output[i].dest << " " << output[i].weight << endl;
    }
    
}

int main(){
    
    int n,E;
    cin >> n >> E;
    Edge *input = new Edge[E];
    
    for(int i = 0; i < E; i++){
        int s,d,w;
        cin >> s >> d >> w;
        input[i].source = s;
        input[i].dest = d;
        input[i].weight = w;
    }
    
    kruskals(input, n, E);

}