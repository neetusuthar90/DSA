#include <iostream>
using namespace std;

int Last_Index(int a[], int size, int x){
    // Base case
    if (size == 0){
        return -1;
    }
    
    // // First logic
    // if (a[size-1] == x){
    //     return size -1;
    // }
    // int ans = Last_Index(a, size -1, x);
    // return ans;

    // Second logic
    int ans = Last_Index(a+1, size -1, x);
    if (ans != -1){
        return ans +1;
    }

    if (a[0] == x){
        return 0;
    }
    else{
        return -1;
    }
}

int main(){
    int a[5] = {5,5,6,5,6};
    int x;
    cin >> x;
    cout << Last_Index(a,5,x) << endl;
}