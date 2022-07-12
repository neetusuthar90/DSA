#include<iostream>
#include<vector>
using namespace std;

int main(){
    // vector<int> *vp = new vector<int>();
    vector<int> v;
    for(int i = 0; i < 20; i++){
        cout << "capacity: " << v.capacity() << endl;
        cout << "size: " << v.size() << endl;
        v.push_back(i+1);
    }

    v.push_back(10);
    v.push_back(20);
    v.push_back(30);

    // Don't use [] for inserting elements
    v[1] = 100;
    v[5] = 123;

    v.push_back(23); 
    v.push_back(12);

    /*
    v.pop_back();
    for (int i = 0; i < v.size(); i++){
        cout << v[i] << " ";
    }
    cout << endl;
    
    //cout << v[0] << " " << v[1] << " " << v[2] << " "<< v[3] << endl;
    cout << v.size() << endl;
    cout << v.at(2) << endl;
    */
   
}