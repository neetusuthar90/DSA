#include <iostream>
using namespace std;

long long power(int a, int b){
    if(a = 0){
        return 1;
    }
    return (a*power(a,b-1))%1000000007;    
}

int main(){
    int a = 12;
    int b = 21;
    long long ans = power(a,b);
    cout << ans << endl;
}