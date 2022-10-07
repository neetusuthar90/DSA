#include <iostream>
#include <vector>
using namespace std;

void rotate(vector<int>& nums, int k) {
        int p = 1;
        int n = nums.size();
        while(p <= k){
            int last = nums[n-1];
            cout << last << endl;
            for(int i = n-1; i >0; i--){
                nums[i] = nums[i-1];
            }
            nums[0] = last;
            p++;
        }
}
int main(){
    vector<int> arr = {1,2,3,4,5,6,7};
    rotate(arr,3);
    for(int i = 0; i < 7; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}