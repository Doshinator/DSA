#ifndef _TRIE_H_
#define _TRIE_H_

#include <unordered_map>
#include <string>
#include <vector>

using namespace std;

class Trie{
    public:
    Trie(){}
    void insert(string word);
    bool search(string word);
    bool startsWith(string prefix);
    friend class WordDictionary;
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words);
    private:
    unordered_map<char, Trie*> children;
    bool isWord = false;
};


class WordDictionary {
    public:
    WordDictionary(){}
    void addWord(string word);
    bool search(string word);
    bool search(Trie* node, string &word, int index);
    private:
    Trie* root = new Trie();
};



#endif