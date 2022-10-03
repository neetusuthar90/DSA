#include <iostream>
#include "Trie.h"
using namespace std;

int main(){
    Trie t;
    t.insertWord("are");
    t.insertWord("does");
    t.insertWord("and");

    std::cout << std::boolalpha << t.searchWord("and") << endl;

    t.removeWord("and");
    std::cout << std::boolalpha << t.searchWord("and") << endl;
    return 0;
}