#include <iostream>
#include <unordered_map>
using namespace std;

int lengthOfLongestSubsetWithZeroSum(int* arr, int n) {
    unordered_map<int,int> prefixSum;
    
    int maxLength = 0;
	int runningSum = 0;    
    for(int i = 0; i < n; i++) {
        runningSum += arr[i];
         
        // Corner cases
        if (arr[i] == 0 and maxLength == 0) {
            maxLength = 1;
        }
        if (runningSum == 0) { 
            maxLength = i + 1;
        }
        
        if(prefixSum.find(runningSum) != prefixSum.end()) {
            maxLength = max(maxLength, i - prefixSum[runningSum]);
        } else {
            prefixSum[runningSum] = i;
        }
    }
    
    return maxLength;
}

int main(){
    int arr[] = {95,-97,-387,-435,-5,-70,897,127,23,284};
    int size = sizeof(arr)/sizeof(arr[0]);
    int maxLength = lengthOfLongestSubsetWithZeroSum(arr,size);
    cout << maxLength << endl;
}