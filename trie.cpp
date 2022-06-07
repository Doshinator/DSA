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
    return search(word, root);
}

bool WordDictionary::search(string word, Trie* node){
    Trie* curr = root;
    for(int i = 0; i < word.length(); i++){
        char c = word[i];

        if(c == '.'){
            for(auto child : curr->children){
                if(search(word.substr(i + 1), child.second)) return true;
            }
            return false;
        }
        else{
            if(curr->children.find(c) == curr->children.end())
                curr->children[c] = new Trie();

            curr = curr->children[c];
        }
    }
    return curr->isWord;
}