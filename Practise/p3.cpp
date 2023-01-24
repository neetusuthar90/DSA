#include <bits/stdc++.h>
using namespace std;

int findJudge(int n, vector<vector<int>>& trust) {
    int m = trust.size();
    int ans;
    map<int,int> mp;
    for(int i = 1; i <= n; i++){
        mp.insert({i,0});
    }
    for (auto itr = mp.begin(); itr != mp.end(); ++itr) {
        if(itr->second == 0){
            ans = itr->first;
            break;
        }
        else{
            ans = -1;
        }
    }
    return ans;   
}

int main(){
    vector<vector<int>> trust = {
        {1,3},{1,4},{2,3},{2,4},{4,3}
    };
    int ans = findJudge(4,trust);
    cout << ans << endl;
}