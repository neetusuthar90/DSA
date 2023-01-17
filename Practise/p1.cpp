#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int main(){
    vector<vector<int>> edges{
        {0,1},{0,2},{1,4},{1,5},{2,3},{2,6}
    };
    vector<int> hasApple{
        0,0,1,0,1,1,0
    };
    unordered_map<int,int> m;
    for(auto const& edge : edges)  {
        if (m.count(edge[1]) > 0){
            cout << m.count(edge[1]) << endl;
            m[edge[0]] = edge[1];
        }
        else m[edge[1]] = edge[0];
    }
    int result = 0;
    for(int i = 0; i < hasApple.size(); i++){
        if (!hasApple[i]){
            cout << hasApple[i] << endl;
            continue;
        }
        int parent = i;
        while(parent != 0 && m[parent] >= 0) {
            auto temp = m[parent];
            m[parent] = -1;
            parent = temp;
            result += 2;
        }
    }
    return 0;
}