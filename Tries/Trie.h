#include <iostream>
#include "TrieNode.h"
#include <string>
using namespace std;

class Trie
{
private:
    TrieNode *root;
public:
    Trie(){
        root = new TrieNode('\0');
    }

    void insertWord(TrieNode *root, string word){
        //Base case
        if(word.size() == 0){
            root -> isTerminal = true;
            return;
        }

        // Simple calculation
        int index = word[0] - 'a';
        TrieNode *child;
        if(root -> children[index] != NULL){
            child = root -> children[index];
        }
        else{
            child = new TrieNode(word[0]);
            root -> children[index] = child;
        }

        //Recursive call
        insertWord(child, word.substr(1));
    }

    // For users
    void insertWord(string word){
        insertWord(root,word);
    }


    bool searchWord(TrieNode *root, string word){
        //Base case
        if(word.size() == 0){
            return root -> isTerminal;
        }

        //Small Calculation
        int index = word[0] - 'a';
        TrieNode *child;
        if(root -> children[index] != NULL){
            child = root -> children[index];
        }
        else{
            return false;
        }

        //Recursive call
        return searchWord(child, word.substr(1));
    }

    bool searchWord(string word){
        return  searchWord(root,word);    
    }

    void removeWord(TrieNode* root, string word){
        //Base case
        if(word.size() == 0){
            root -> isTerminal = false;
            return;
        }

        // Small case
        int index = word[0] - 'a';
        TrieNode *child;
        if(root -> children[index] != NULL){
            child = root -> children[index];
        }
        else{
            return;
        }

        // Recursive call
        removeWord(child, word.substr(1));
    }

    void removeWord(string word){
        removeWord(root, word);
    }
};


