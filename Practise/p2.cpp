#include <bits/stdc++.h>
#include <vector>
#include <string>
using namespace std;

vector<int> minflip(string s)
{
    vector<int> vec;
    int n = s.length();
    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        int left = i;
        int right = i;
        while (left != -1 && s[left] == 1)
        {
            sum += 1;
            left++;
        }
        while (right < n && s[right] == 0)
        {
            sum += 1;
            right++;
        }
        vec.push_back(sum);
    }
    return vec;
}
int main(){
    string s = "00110";
    vector<int> vec = minflip(s);
    for(int i= 0; i < vec.size(); i++){
        cout << vec[i] << " ";
    }
}