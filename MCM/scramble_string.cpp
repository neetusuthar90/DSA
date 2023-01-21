#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool Solve(string a, string b){
    // Base case
    if(a.compare(b) == 0) return true;
    if(a.length() <= 1) return false;

    int n = a.length();
    bool flag = false;
    for(int i = 1; i < n; i++){
        if ((Solve(a.substr(0, i), b.substr(n - i, i)) && Solve(a.substr(i), b.substr(0, n - i))) || //  
		        (Solve(a.substr(0, i), b.substr(0, i)) && Solve(a.substr(i), b.substr(i)))) {
			flag = true; 
			break;
		}
        
    }
    return flag;
}

int main(){
    int n;
    cin >> n;
    string s1, s2;
    cout << "Enter two string:";
    cin >> s1 >> s2 ;
    bool ans = Solve(s1, s2);
    cout << boolalpha << ans << endl;

}