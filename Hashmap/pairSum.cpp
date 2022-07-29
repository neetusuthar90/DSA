#include <iostream>
#include <unordered_map>
using namespace std;

int pairSum0(int *a, int size){
    unordered_map<int,int> map;
    for(int i = 0; i< size; i++){
        map[a[i]]++;
    }
    
    int count = 0;
    for(int i = 0; i<size; i++){
        if(a[i] != 0 and map[-a[i]] != 0){
            count += (map[a[i]])*(map[-a[i]]);
            map[a[i]] = 0;
            map[-a[i]] = 0;
        }
        else if(a[i] == 0 and map[a[i]] != 0){
            count += ((map[a[i]])*(map[a[i]]-1))/2; //n_C_2 combination
            map[a[i]] = 0;
        }
    }
    return count;
}

int main(){
    int a[] = {1,2,3,-3,3,-1,0,0,0};
    int n = sizeof(a)/sizeof(a[0]);
    int count = pairSum0(a,n);
    cout << "Total pair sum 0 are: " << count << endl;
}

// Time Complexitiy: O(n)