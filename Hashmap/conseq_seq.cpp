#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

vector<int> longest_Consq_Seq(int *arr, int n){
    unordered_set<int> elm;

    for(int i=0; i < n; i++){
        elm.insert(arr[i]);
    }

    int maxlength = 0;
    int startElm;
    int endElm;

    for(int i = 0;i<n;i++){
        if(elm.find(arr[i]-1) != elm.end()){
            continue;
        }
        else{
            int next = arr[i];
            while (elm.find(next) != elm.end()){
                next++;
            }
            if(maxlength < next - arr[i]){
                maxlength = next - arr[i];
                startElm = arr[i];
                endElm = next - 1;
            }
        }
    }

    if (maxlength == 1){
        return {startElm};
    }
    else{
        return {startElm, endElm};
    }
}

int main(){
    int arr[] = {2,12,9,16,10,5,3,20,25,11,1,8,6};
    int size = sizeof(arr)/sizeof(arr[0]);
    vector<int> v = longest_Consq_Seq(arr, size);
    for(int i = 0; i < v.size() ; i++){
        cout << v[i] << " ";
    }
    cout << endl;
}