#include <bits/stdc++.h>
using namespace std;

void sortElement(vector<int> &num1, vector<int> &num2, int m, int n){
    int i = 0, j = 0;
    while(i < m){
        if(num1[i] > num2[j]){
            swap(num1[i],num2[j]);
            i++;
            sort(num2.begin(), num2.end());
        }
        else{
            continue;
        }
    }
    int k = i;
    int t = 0;
    while(k < m+n){
        num1[k] = num2[t];
        k++;
        t++;
    }
}

int main(){
    vector<int> num1 = {1,2,3};
    vector<int> num2 = {2,5,6};
    int m = 3, n = 3;
    sortElement(num1, num2,m,n);
    for(int i = 0; i < m+n; i++){
        cout << num1[i] << " ";
    }
}