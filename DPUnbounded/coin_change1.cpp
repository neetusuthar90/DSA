#include <iostream>
using namespace std;

int coinChange1(int coin[], int N, int size){
    int t[size+1][N+1];
    for(int i = 0; i < size+1; i++){
        for(int j = 0; j < N+1; j++){
            if(i==0) t[i][j] = 0;
            if(j==0) t[i][j] = 1;
        }
    }

    for(int i = 1; i < size+1; i++){
        for(int j = 1; j < N+1; j++){
            if(coin[i-1] <= j){
                t[i][j] = t[i-1][j] + t[i][j-coin[i-1]];
            }
            else{
                t[i][j] = t[i-1][j];
            }
        }
    }
    return t[size][N];
}

int main(){
    int coin[] = {1,2,3};
    int N = 4;
    int size = sizeof(coin)/sizeof(coin[0]);
    int maxChange = coinChange1(coin, N, size);
    cout << "Maximum number of ways to choose coins:" << maxChange << endl;
}