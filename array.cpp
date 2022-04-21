#include "array.h"
#include <iostream>
#include <string>
#include <set>
#include <unordered_map>


bool ARRAY::containsDuplicate(vector<int> nums){

    return nums.size() > set<int>(nums.begin(), nums.end()).size();
}


bool ARRAY::isAnagram(string s, string t){
    unordered_map<char,int> m1;
    unordered_map<char,int> m2;

    if(s.size() != t.size())
        return false;
    
    for(int i = 0; i < s.size(); i++){
        m1[s[i]]++;
        m2[t[i]]++;
    }

    for(int i = 0; i < s.size(); i++){
        if(m1[s[i]] != m2[s[i]])
            return false;
    }

    return true;
}