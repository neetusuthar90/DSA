#include <iostream>
#include <climits>
using namespace std;

int coinChange1(int coin[], int N, int size){
    int t[size+1][N+1];
    for(int i = 0; i < size+1; i++){
        for(int j = 0; j < N+1; j++){
            if(j==0) t[i][j] = 0;
            if(i==0) t[i][j] = INT_MAX - 1;
        }
    }

    int i = 1;
    for(int j = 1; j < N+1; j++){
        if(j%coin[0] == 0){
            t[i][j] = j/coin[0];
        }
        else{
            t[i][j] = INT_MAX - 1;
        }
    }

    for(int i = 2; i < size+1; i++){
        for(int j = 1; j < N+1; j++){
            if(coin[i-1] <= j){
                t[i][j] = min(t[i-1][j] , t[i][j-coin[i-1]] + 1);
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
    int N = 5;
    int size = sizeof(coin)/sizeof(coin[0]);
    int min_coins = coinChange1(coin, N, size);
    cout << "Minimum no of coins required : " << min_coins << endl;
}