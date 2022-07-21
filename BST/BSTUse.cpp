#include<iostream>
#include "BinarySearchTreeNode.h"
using namespace std;

// 8 5 10 2 6 -1 -1 -1 -1 -1 7 -1 -1
int main(){
    BinarySearchTreeNode b1;
    int n;
    cin >> n;
    for (int i = 0; i<n; i++){
        int data;
        cin >> data;
        b1.insert(data);
    }
    b1.print();
    cout << endl;
    cout << boolalpha << b1.hasData(5) << endl;
    b1.deleteData(4);
    b1.print();
    

}