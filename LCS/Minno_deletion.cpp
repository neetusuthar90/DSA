#include <bits/stdc++.h>
using namespace std;

int LCS(string X, string Y, int n, int m){
    
    int **dp = new int*[n+1];
    for(int i = 0; i <= n; i++)
        dp[i] = new int[m+1];
    
   for(int i = 0; i <= n; i++){
        for(int j = 0; j <= m; j++){
            if(i == 0 || j == 0)
                dp[i][j] = 0;
        }
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(X[i-1] == Y[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
            }
            else{
                dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
            }
        }
    }
    return dp[n][m];
}

int LPS(string X, int n){
    string Y = X;
    reverse(Y.begin(), Y.end());
    return LCS(X,Y,n,n);
}

int main(){
    string X = "geeksforgeeks";
    int n = X.length();
    int len = LPS(X,n);
    cout << "Minimum no. of deletion required: "<< n - len << endl;
}