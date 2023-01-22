#include <bits/stdc++.h>
using namespace std;

const int d = 101;
int t[d][d];

int minAttempt(int e, int f){
    //Base case
    if(t[e][f] != -1){
        return t[e][f];
    }
    if(e == 1){
        return t[e][f] = f;
    }
    if(f == 0 || f == 1){
        return t[e][f] = f;
    }
    int mn = INT_MAX;
    for(int k = 1; k <= f; k++){
        int temp = 1 + max(minAttempt(e-1,k-1), minAttempt(e,f-k));
        mn = min(mn, temp);
    }
    return t[e][f] = mn;
}

int main(){
    int e,f;
    cout << "Enter the no. of eggs:";
    cin >> e;
    cout << "Total no. of floor:";
    cin >> f;
    memset(t,-1,sizeof(t));
    int ans = minAttempt(e,f);
    cout << ans << endl;
}