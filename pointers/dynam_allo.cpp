#include <iostream>
using namespace std;

int main(){
    int *p = new int;
    int n;
    cin >> n;
    int * pa = new int[n];
    for (int i = 0; i < n; i++){
        cin >> pa[i];
    }

    int max = -1;
    for (int i = 0; i < n; i++){
        if (max < pa[i]){
            max = pa[i];
        }
    }
    cout << max << endl;
}