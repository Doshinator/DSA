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

vector<int> ARRAY::topKFrequent(vector<int> nums, int k){
    // Input: nums = [1,1,1,2,2,3], k = 2
    // Output: [1,2]
    vector<int> res;
    vector<vector<int>> numList(nums.size() + 1);
    unordered_map<int,int> m;

    for(int i = 0; i < nums.size(); i++){
        m[nums[i]]++;
    }

    for(auto i : m){
        numList[i.second].push_back(i.first);
    }

    for(int i = numList.size() - 1; i >= 0 && res.size() < k; i--){
        for(int j = 0; j < numList[i].size(); j++){
            res.push_back(numList[i][j]);
           
        }
    }
    return res;
}

vector<int> ARRAY::productExceptSelf(vector<int> nums){
    // Input: nums = [1,2,3,4]
    // Output: [24,12,8,6]

    // split into two arrays L and R
    // L array is product of all element left of i'th element 
    // R array is product of all element right of i'th element 
    // combine the array / multiple the L and R array
    vector<int> res(nums.size());
    int multiple = 1;

    for(int i = 0; i < nums.size(); i++){
        res[i] = multiple;
        multiple = multiple * nums[i];
    }
    multiple = 1;
    for(int i = nums.size() - 1; i >= 0 ; i--){
        res[i] = multiple * res[i];
        multiple = multiple * nums[i];
    }
    return res;
}