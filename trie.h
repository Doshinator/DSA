#ifndef _TRIE_H_
#define _TRIE_H_

#include <unordered_map>
#include <string>

using namespace std;

class Trie{
    public:
    Trie(){}
    void insert(string word);
    bool search(string word);
    bool startsWith(string prefix);
    private:
    unordered_map<char, Trie*> children;
    bool isWord = false;
};


class WordDictionary {
    public:
    WordDictionary(){}
    void addWord(string word);
    bool search(string word);
};



#endif