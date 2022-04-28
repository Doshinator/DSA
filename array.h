#ifndef ARRAY_H_
#define ARRAY_H_
#include <vector>
#include <string>
#include <map>
using namespace std;



class ARRAY{
    public:
    bool containsDuplicate(vector<int> nums);
    bool isAnagram(string s, string t);
    vector<int> twoSum(vector<int> nums, int target);
    vector<vector<string>> groupAnagrams(vector<string> strs);
    vector<int> topKFrequent(vector<int> nums, int k);
};



#endif

