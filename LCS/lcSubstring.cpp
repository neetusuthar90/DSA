#include <bits/stdc++.h>
using namespace std;

int LCS(string X, string Y, int n, int m) {

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
            if(i == 0 || j == 0){
                dp[i][j] = 0;
            }
            if(X[i-1] == Y[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
            }
            else{
                dp[i][j] = 0;
            }
        }
    }
    int mx = INT_MIN;
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= m; j++){
            mx = max(mx, dp[i][j]);
        }
    }
    return mx;
}

int main() {
	string X = "zxabcdezy";
    string Y = "yzabcdezx";
	int n = X.length(), m = Y.length();
	cout << LCS(X, Y, n, m) << endl;
	return 0;
}