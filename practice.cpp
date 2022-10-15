#include <bits/stdc++.h>
using namespace std;
#include <vector>

int largestPerimeter(vector<int>& nums) {
    int para = 0;
    for(int i = 0; i <nums.size(); i++){
        para += nums[i];
    }
    float s = para/2.0;
    cout << s << endl;
    float val = 1;
    for(int i = 0; i<nums.size(); i++){
        val = val*(s-nums[i]);
    }
    cout << val << endl;
    if(sqrt(s*val) == 0){
        return 0;
    }
    return para;
}

int main(){
    vector<int> nums = {2,1,2};
    cout << largestPerimeter(nums) << endl;
}