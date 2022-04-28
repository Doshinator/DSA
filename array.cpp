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


vector<int> ARRAY::twoSum(vector<int> nums, int target){
    vector<int> res;
    unordered_map<int, int> m;
    
    for(int i = 0; i < nums.size(); i++){
        if(m.find(target - nums[i]) != m.end()){
            res.push_back(m[target - nums[i]]);
            res.push_back(i);
        }
        m[nums[i]] = i;
    } 
    return res;
}

vector<vector<string>> ARRAY::groupAnagrams(vector<string> strs){
    vector<vector<string>> res;
    unordered_map<string, vector<string>> mp;

    // map will be < sorted string, {list of the initial unosorted string}>

    // Input: strs = ["eat","tea","tan","ate","nat","bat"]
    // Output: [["bat"],["nat","tan"],["ate","eat","tea"]]
    for(int i = 0; i < strs.size(); i++){
        string str = strs[i];
        std::sort(strs[i].begin(), strs[i].end()); // string [i] is sorted 
        mp[strs[i]].push_back(str); // <sorted string1, {unsorted string1}>
    }
    for(auto i : mp){
        res.push_back(i.second);
    }
    return res;
}