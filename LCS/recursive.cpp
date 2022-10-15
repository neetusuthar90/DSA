#include <iostream>
#include <string>
using namespace std;

int LCS(string X, string Y, int n, int m){
    if(n==0 || m==0){
        return 0;
    }

    if(X[n-1] == Y[m-1]){
        return 1 + LCS(X, Y, n-1, m-1);
    }
    else{
        return max(LCS(X,Y,n,m-1), LCS(X,Y,n-1,m));
    }
}

int main(){
    string X = "abcdgh";
    string Y = "abedfhr";
    int n = X.length();
    int m = Y.length();
    int length = LCS(X,Y,n,m);
    cout << "length of longest common subsequence: " << length << endl; 
}
