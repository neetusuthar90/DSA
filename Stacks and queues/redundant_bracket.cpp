#include <iostream>
using namespace std;
#include <stack>
#include <string>

bool isopen(char c){
    return (c == '(');
}

bool ismatching(char a, char b){
    return (a == '(' && b == ')');
}

bool check_Redundant_Bracket(string str){
    stack<char> s;
    int d = str.length();
    
    for (int i = 0; i<d; i++){
        char ch = str[i];

        if (isopen(ch)){
            s.push(ch);
        }
        else{
            if (s.empty()){
                return false;
            }
            else if (! ismatching(s.top(),ch)){
                return false;
            }
            else if (s.top() == '+' || s.top() == '-' ||
                    s.top() == '*' || s.top() == '/')
            {
                return s.top();
            }
            else{
                s.pop();
            }  
        }    
    }
    return s.empty();
}


int main(){
    string str;
    getline(cin, str);
    bool ans = check_Redundant_Bracket(str);
    cout << ans << endl;
}