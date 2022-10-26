#include<bits/stdc++.h>
using namespace std;

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
    if(i>=j){
        return 0;
    }
    if(isPalindrone(str,i,j)){
        return 0;
    }
    int mn = INT_MAX;
    for(int k = i; k <= j-1; k++){
        int tempAns = solve(str,i,k) + solve(str,k+1,j) + 1;
        mn = min(mn, tempAns);
    }
    return mn;
}

int main(){
    string str = "abcbd";
    cout << solve(str,0,str.length() -1) << endl;
}