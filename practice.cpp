#include <iostream>
#include <string>
using namespace std;
#include <unordered_map>

int main(){

    unordered_map<string,int> data;
    pair<string,int> pa1("Neetu",26);
    pair<string,int> pa2("Liptan",27);

    data.insert(pa1);
    data.insert(pa2);

    cout << data.at("Neetu") << endl;
    for(auto& i:data){
        if(i.second == 27){
            cout << i.first << endl;
        }
    }

    return 0;
}