#include <iostream>
using namespace std;

int All_Indices(int a[], int size, int x, int b[]){
    if (size == 0){
        return 0;
    }
    int ans = All_Indices(a+1, size-1, x, b);
    
    if (a[0]==x){
        for (int i = ans -1; i >= 0; i--){
            b[i + 1] = b[i] + 1;
        }
        b[0] = 0;
        ans ++;
    }
    else{
        for(int i = ans -1; i>=0; i--){
            b[i] = b[i] + 1;
        }
    }

    return ans;
    

}

int main(){
    int n,x;
    int a[n];
    int b[1000];
    cin >> n >> x;
    cout << All_Indices(a, n, x, b) << endl;
}