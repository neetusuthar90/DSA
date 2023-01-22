#include <bits/stdc++.h>
using namespace std;

int minAttempt(int e, int f){
    //Base case
    if(e == 1){
        return f;
    }
    if(f == 0 || f == 1){
        return f;
    }

    int mn = INT_MAX;
    for(int k = 1; k <= f; k++){
        int temp = 1 + max(minAttempt(e-1,k-1), minAttempt(e,f-k));
        mn = min(mn, temp);
    }
    return mn;
}

int main(){
    int e,f;
    cout << "Enter the no. of eggs:";
    cin >> e;
    cout << "Total no. of floor:";
    cin >> f;
    int ans = minAttempt(e,f);
    cout << ans << endl;
}