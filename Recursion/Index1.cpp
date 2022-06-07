#include <iostream>
using namespace std;

int First_index(int a[], int size, int x){
    //Base case
    if (size == 0){
        return -1;
    }

    if (a[0] == x){
        return 0;
    }

    int ans = First_index(a+1, size-1, x);
    if (ans == -1){
        return ans;
    }
    else{
        return ans +1;
    }
}

int main(){
    int n,x;
    int a[n];
    cin >> n;
    for (int i = 0; i<n; i++){
        cin >> a[i] ;
    }
    cin >> x;
    cout << "First Index of x is: "<< First_index(a,5,x) << endl;

}