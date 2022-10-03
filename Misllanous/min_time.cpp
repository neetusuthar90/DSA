#include <iostream>
#include <vector>
using namespace std;
#include <string>

int minCost(string colors, vector<int> &neededTime)
{
    int res = neededTime[0];
    int max_time = neededTime[0];
    int n = colors.size();
    for(int i = 1; i < n; i++){
        if(colors[i] != colors[i-1]){
            res = res - max_time;
            max_time = 0;
        }
        res = res + neededTime[i];
        max_time = max(max_time,neededTime[i]);
    }
    return res - max_time;
}

int main()
{
    string clr = "aaabbbbbbbb";
    vector<int> arr = {3, 5, 10, 7, 5, 3, 5, 5, 4, 8, 1};
    int m = minCost(clr, arr);
    cout << m << endl;
}
