#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int main(){
    unordered_map <string, int> ourmap;
    //Insert
    pair<string, int> p("abc",1);
    ourmap.insert(p);
    ourmap["def"] = 2;

    //find or access
    cout << ourmap["abc"] << endl;
    cout << ourmap.at("def") << endl;

    // access unassign key using .at give error
    //cout << ourmap.at("ghi") << endl;
    cout << "Size: " << ourmap.size() << endl;
    // access unassign key using [] will insert key with value 0
    cout << ourmap["ghi"] << endl;
    cout << "Size: " << ourmap.size() << endl;

    if (ourmap.count("ghi") > 0){
        cout << "ghi is present" << endl;
    }
    ourmap.erase("ghi");
    cout << "Size: " << ourmap.size() << endl;

    return 0;
}