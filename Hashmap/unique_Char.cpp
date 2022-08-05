#include <iostream>
using namespace std;
#include <unordered_map>
#include <string>

string extractUniqueChar(string str){
    unordered_map<char, int> frequency;

    for(int i = 0; i < str.length(); i++){
        frequency[str[i]]++;
    }

    string ans;
    for(int i = 0; i < str.length(); i++){
        if(frequency[str[i]] != 0){
            ans += str[i];
            frequency[str[i]] = 0;
        }
        else{
            continue;
        }
    }
    return ans;
}

int main(){
    string str;
    cout << "Enter the string: ";
    cin >> str;
    str = extractUniqueChar(str);
    cout << "Unique char of the string are: " << str << endl;
}