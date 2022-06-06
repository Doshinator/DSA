#include "trie.h"
#include <unordered_map>
#include <string>

using namespace std;

Trie::Trie(){

}

void Trie::insert(string word){
    Trie* node = this;
    for(char c : word){
        if(node->children.find(c) == node->children.end())
            node->children[c] = new Trie();
        
        node = node->children[c];
    }
    node->isWord = true;
}

bool Trie::search(string word){
    Trie* node = this;
    for(auto c : word){
        if(node->children.find(c) == node->children.end())
            return false;

        node = node->children[c];
    }
    return node->isWord;
}

bool Trie::startsWith(string prefix){
    Trie* node = this;
    for(auto c : prefix){
        if(node->children.find(c) == node->children.end())
            return false;
        node = node->children[c];
    }
    return true;
}