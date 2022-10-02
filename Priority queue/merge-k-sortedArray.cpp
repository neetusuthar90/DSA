#include<iostream>
using namespace std;
#include <queue>

/*
vector<int> merge_KSorted_Array(int arr1[], int arr2[], int arr3[], int n1, int n2, int n3){
    priority_queue<int, vector<int>, greater<int>> pq;
    vector<int> ans;
    for(int i = 0; i < n1; i++){
        pq.push(arr1[i]);
    }
    for(int i = 0; i < n2; i++){
        pq.push(arr2[i]);
    }
    for(int i = 0; i < n3; i++){
        pq.push(arr3[i]);
    }

    while (!pq.empty())
    {
        ans.push_back(pq.top());
        pq.pop();
    }
    return ans;
}
*/

typedef pair<int, pair<int,int>> ppi;

vector<int> merge_KSorted_Array(vector<vector<int>> arr){
    vector<int> output;
    priority_queue<ppi, vector<ppi>, greater<ppi>> pq;
    
    for(int i = 0; i < arr.size(); i++){
        pq.push({arr[i][0], {i,0}});
    }

    while (!pq.empty())
    {
        ppi curr = pq.top();
        pq.pop();

        int i = curr.second.first;
        int j = curr.second.second;
        
        output.push_back(curr.first);

        if((j+1) < arr[i].size()){
            pq.push({arr[i][j+1],{i, j+1}});
        }
    }
    return output;
}

int main(){
    vector<vector<int> > arr{ { 2, 6, 12 }, { 1, 9 }, { 23, 34, 90, 2000 } };
    vector<int> output = merge_KSorted_Array(arr);
    for(int i = 0; i < output.size(); i++){
        cout << output.at(i) << " ";
    }
    cout << endl;
}