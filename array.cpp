#include "array.h"
#include <iostream>
#include <string>
#include <set>
#include <unordered_map>
#include <unordered_set>




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


bool ARRAY::isValidSudoku(vector<vector<char>> board){

    /*
        Input: board = 
        [["5","3",".",".","7",".",".",".","."]
        ,["6",".",".","1","9","5",".",".","."]
        ,[".","9","8",".",".",".",".","6","."]
        ,["8",".",".",".","6",".",".",".","3"]
        ,["4",".",".","8",".","3",".",".","1"]
        ,["7",".",".",".","2",".",".",".","6"]
        ,[".","6",".",".",".",".","2","8","."]
        ,[".",".",".","4","1","9",".",".","5"]
        ,[".",".",".",".","8",".",".","7","9"]]
        Output: true
    */
    int row = board[0].size();
    int col = board.size();

    unordered_map<int,set<char>> rows(9);
    unordered_map<int,set<char>> cols(9);
    unordered_map<int,set<char>> block;
    
    // loop through the board rows - add into map
    // if row hashmap contains duplicate while looping through col - return false 
    // if col hashmap contains duplicate while looping through - return false
    // if the 3x3 contains duplicate while looping - return false

    for(int r = 0; r < row; r++){
        for(int c = 0; c < col; c++){
            if(board[r][c] == '.')
                continue;
            if(rows[r].find(board[r][c]) != rows[r].end() ||
                cols[c].find(board[r][c]) != cols[c].end() ||
                block[(r / 3) * 3 + c / 3].find(board[r][c]) != block[(r / 3) * 3 + c / 3].end())
                    return false;
                
            rows[r].insert(board[r][c]);
            cols[c].insert(board[r][c]);
            // to calculate the position of the block - (r / 3) * 3 + c / 3
            block[(r / 3) * 3 + c / 3].insert(board[r][c]);
        }
    }

    return true;
}


string ARRAY::encode(vector<string> strs){
    string res;
    string delimiter = "#";
    for(int i = 0; i < strs.size(); i++){
        res.append(to_string(strs[i].size()) + delimiter + strs[i]);
    }

    return res;
}

vector<string> ARRAY::decode(string str){
    vector<string> res;
    size_t pos = 0;
    string token;
    string delimiter = "#";

    int i = 0;
    while(i < str.size()){
        int j = i;
        if(j != '#')
            j++;
        int strLength = stoi(str.substr(i, j));
        res.push_back(str.substr(j + 1, strLength)); // substr(index, # of characters to include in the substring)
        i = j + 1 + strLength;
    }

    return res;
}


int ARRAY::longestConsecutive(vector<int> nums){
    // Input: nums = [100,4,200,1,3,2]
    // Output: 4
    // [1, 2, 3, 4]

    // insert all nums into unordered_set
    // go through nums and start deleting .. if it's not in the set - continue
    // for the deleted element, look at the previous and next element to see if those are in the set
    // start expanding the window and deleting those elements found from the set
    // take the max of current window size and new window size
    if(nums.empty())
        return 0;
    int res = 1;
    unordered_set<int> num(nums.begin(), nums.end());
    
    for(int i = 0; i < nums.size(); i++){
        if(num.find(nums[i]) == num.end())
            continue;

        num.erase(nums[i]);
        int next = nums[i] + 1;
        int prev = nums[i] - 1;
        
        while(num.find(prev) != num.end()) {
            num.erase(prev);
            prev--;
        }

        while(num.find(next) != num.end()){
            num.erase(next);
            next++;
        }

        res = std::max(res, next - prev - 1);
    }
    
    return res;
}