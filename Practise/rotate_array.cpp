#include <bits/stdc++.h>
using namespace std;

void rotateArray(vector<vector<int>>& m) {
    int n = m.size();
    for(int i = 1; i < n; i++){
        for(int j = 0; j < i; j++){
            swap(m[i][j], m[j][i]);
        }
    }
    for(int i = 0; i < n; i++){
        reverse(m[i].begin(), m[i].end());
    }
}

int main(){
    vector<vector<int>> m = {
        {1,2,3},{4,5,6},{7,8,9}
    };
    rotateArray(m);
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            cout << m[i][j] << " ";
        }
        cout << endl;
    }
}