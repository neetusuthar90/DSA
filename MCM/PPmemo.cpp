#include<bits/stdc++.h>
using namespace std;

const int d = 1001;
int t[d][d];

bool isPalindrone(string str, int i, int j){
    while (i <= j)
    {
        if(str[i] != str[j]){
            return false;
        }
        i++;
        j--;
    }
    return true;
}

int solve(string str, int i, int j){
    if(i>=j || isPalindrone(str,i,j)){
        return 0;
    }
    if(t[i][j] != -1){
        return t[i][j];
    }
    int mn = INT_MAX;
    for(int k = i; k <= j-1; k++){
        int tempAns = solve(str,i,k) + solve(str,k+1,j) + 1;
        mn = min(mn, tempAns);
    }
    return t[i][j] = mn;
}

int main(){
    string str = "ababbbabbababa";
    memset(t, -1, sizeof(t));
    cout << solve(str,0,str.length()-1) << endl;
}