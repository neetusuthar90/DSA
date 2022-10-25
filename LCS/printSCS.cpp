#include <algorithm> 
#include<iostream>
#include<string>
#include<climits>
using namespace std;

int** LCS(string X, string Y, int n, int m) {

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
                dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
            }
        }
    }
    int mx = INT_MIN;
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= m; j++){
            mx = max(mx, dp[i][j]);
        }
    }
    return dp;
}

string printSCS(string X, string Y, int n, int m){
    int ** dp = LCS(X,Y,n,m);
    string str = " ";
    int i = n;
    int j = m;
    while(i > 0 && j > 0){
        if(X[i-1] == Y[j-1]){
            str.push_back(X[i-1]);
            i--;
            j--;
        }
        else if(dp[i][j-1] > dp[i-1][j]){
            str.push_back(Y[j-1]);
            j--;
        }
        else{
            str.push_back(X[i-1]);
            i--;
        }
    }
    while(i > 0){
        str.push_back(X[i-1]);
        i--;
    }
    while (j>0)
    {
        str.push_back(Y[j-1]);
        j--;
    }
    reverse(str.begin(), str.end());
    return str;
}

int main() {
	string X = "acbcf";
    string Y = "abcdaf";
	int n = X.length(), m = Y.length();
	cout << printSCS(X, Y, n, m) << endl;
	return 0;
}