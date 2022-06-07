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
    return search(root, word, 0);
}

bool WordDictionary::search(Trie* node, string &word, int index){
    if(index == word.size())
        return node->isWord;

    if(word[index] == '.'){
        for(auto it : node->children){
            if(node->children && search(node->children[it.first], word, index + 1))
                return true;
        }
    }

    if(node->children.find(word[index]) == node->children.end())
        return false;

    return search(node->children[word[index]], word, index + 1);
}


vector<string> findWords(vector<vector<char>>& board, vector<string>& words){
    
}