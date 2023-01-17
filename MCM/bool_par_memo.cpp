#include<iostream>
#include <vector>
#include <climits>
#include<string>
#include<unordered_map>
using namespace std;

unordered_map<string, int> mp;

int solve(string &str, int i, int j, bool isTrue){
    string key = to_string(i) + " " + to_string(j) + " " + (isTrue ? "T" : "F");

    //Base case
    if(i > j){
        return false;
    }
    if(i == j){
        if(isTrue == true){
            mp[key] = str[i] == 'T';
        }
        else{
            mp[key] = str[i] == 'F';
        }
        return mp[key];

    }
    int ans = 0;
    if(mp.find(key) != mp.end()){
        return mp[key];
    }

    //Loop
    for(int k = i+1; k <= j-1; k += 2){
        int lT = solve(str, i, k-1, true);
        int lF = solve(str, i , k-1,false);
        int rT = solve(str,k+1,j,true);
        int rF = solve(str,k+1,j,false);

        //Comparsion
        if(str[k] == '&'){
            if(isTrue == true) ans += lT*rT;
            else ans += lF*rT + lF*rF + lT*rF;
        }
        if(str[k] == '|'){
            if(isTrue == true) ans += lT*rT + lT*rF + lF*rT;
            else ans += lF*rF;
        }
        if(str[k] == '^'){
            if(isTrue == true) ans += lF*rT + lT*rF;
            else ans += lT*rT + lF*rF;
        }
    }
    
    return mp[key] = ans;
}

int main(){
    string str = "T|F&T^F";
    int res = solve(str,0,str.length()-1,true);
    cout << res << endl;
}