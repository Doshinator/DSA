#include "trie.h"
#include <unordered_map>
#include <string>

using namespace std;

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

// -- word dictionary
void WordDictionary::addWord(string word){
    Trie* curr = root;
    for(auto c : word){
        if(curr->children.find(c) == curr->children.end())
            curr->children[c] = new Trie();
        
        curr = curr->children[c];
    }
    curr->isWord = true;
}

bool WordDictionary::search(string word){
    return search(0, word, root);
}

bool WordDictionary::search(int index, string &word, Trie* node){
    if(index == word.size())
        return node->isWord;

    if(word[index] == '.'){
        for(auto it = node->children.begin(); it != node->children.end(); it++){
            if(search(index + 1, word, it->second)) 
                return true;
        }
    }
    else if(node->children.count(word[index])){
        return search(index + 1, word, node->children[word[index]]);
    }
    return false;
}