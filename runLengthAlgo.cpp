#include <iostream>
#include <string>
using namespace std;

string runLengthEncoding(string s){
    int n = s.length();
    string letters;
    for(int i = 0; i < n; i++){
        int count = 1;
        while (i < n-1 && s[i] == s[i+1]){
            count ++;
            i++;
        }
        letters.push_back(s[i]);
        if(count != 1){
            letters += std::to_string(count);
        }
    }
    return letters;
}

int main(){
    string s = "aaabccd";
    string str = runLengthEncoding(s);
    cout << str << endl;
}