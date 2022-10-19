// Online C++ compiler to run C++ program online
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

int main() {
    // Write C++ code here
    vector<string> words = {"the","day","is","sunny","the","the","the","sunny","is","is"};
    unordered_map<string, int> mp;
    int n = words.size();
    for(int i = 0; i < n; i++ ){
        mp[words[i]]++;
    }
    for (auto x : mp)
    cout << x.first << " " <<
            x.second << endl;
    return 0;
}