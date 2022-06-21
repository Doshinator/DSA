#include "backtracking.h"
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;


vector<vector<int>> BackTracking::subsets(vector<int> &nums){
    // Input: nums = [1,2,3]
    // Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
    vector<vector<int>> ans;
    vector<int> subset;
    subsetsHelper(nums, subset, ans, 0);
    return ans;
}

void BackTracking::subsetsHelper(vector<int> &nums,vector<int> &subset, vector<vector<int>> &ans, int index){ 
    // choice : we can choose element from array
    // constaint : we need to chooise all elements
    // goal (reach our base case) : we looped through entire nums array
    ans.push_back(subset);

    for(int i = index; i < nums.size(); i++){
        subset.push_back(nums[i]);
        subsetsHelper(nums, subset, ans, index + 1);
        // if our decision doesn't work out - come back from exploration - eject the dicision
        subset.pop_back();
    }

}

vector<vector<int>> BackTracking::combinationSum(vector<int>& candidates, int target){
    // Input: candidates = [2,3,6,7], target = 7
    // Output: [[2,2,3],[7]]
    std::sort(candidates.begin(), candidates.end());
    vector<vector<int>> ans;
    vector<int> combination;
    combinationSumHelper(candidates, combination, ans, target, 0);
    return ans;
}

void BackTracking::combinationSumHelper(vector<int> &candidates, vector<int> &combination, vector<vector<int>> &ans, int target, int index){
    // choice : choose an element multiple times or combination of elements from given array
    // constraint : if we don't reach the target, we can continue to recurse to next element
    // goal (reach our base case): get target to 0 (answer)
    if(target == 0){
        ans.push_back(combination);
        return;
    }
    
    for(int i = index; i < candidates.size() && target > 0; i++){
        combination.push_back(candidates[i]);
        combinationSumHelper(candidates, combination, ans, target - candidates[i], i);
        // if our decision doesn't work out - come back from exploration - eject the dicision
        combination.pop_back();
    }
}


vector<vector<int>> BackTracking::permute(vector<int>& nums){
    // [1,2,3] 
    // [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
    vector<vector<int>> ans;
    permuteHelper(nums, ans, 0);
    return ans;
}

void BackTracking::permuteHelper(vector<int> nums, vector<vector<int>> &ans, int index){
    // choice : build subarray using all values from nums array
    // constraint : if we we need to re-arrange elements after fully exploring to form another set of permutated array
    // goal (reach our base) : we reached end of array
    if(index == nums.size()){
        ans.push_back(nums);
        return;
    }

    for(int i = index; i < nums.size(); i++){
        swap(nums[index], nums[i]);
        permuteHelper(nums, ans, index + 1);
    }
}

vector<vector<int>> BackTracking::subsetsWithDup(vector<int>& nums){
    // Input: nums = [1,2,2]
    // Output: [[],[1],[1,2],[1,2,2],[2],[2,2]]
    sort(nums.begin(), nums.end());
    vector<vector<int>> ans;
    vector<int> subset;
    subsetsHelper(nums, subset, ans, 0);
    return ans;
}

void BackTracking::subsetsWithDupHelper(vector<int>& nums, vector<int> &subset, vector<vector<int>> &ans, int index){
    ans.push_back(subset);

    for(int i = index; i < nums.size(); i++){
        if(nums[i] == nums[i-1] && i != index)
            continue;
        subset.push_back(nums[i]);
        subsetsWithDupHelper(nums, subset, ans, i + 1);
        subset.pop_back();
    }
}

vector<vector<int>> BackTracking::combinationSum2(vector<int>& candidates, int target){
    std::sort(candidates.begin(), candidates.end());
    vector<int> combination;
    vector<vector<int>> ans;
    combinationSum2Helper(candidates, combination, ans, target, 0);
    return ans;
}

void BackTracking::combinationSum2Helper(vector<int>& candidates, vector<int> &combination, vector<vector<int>> &ans, int target, int index){
    if(target == 0){
        ans.push_back(combination);
        return;
    }

    for(int i = index; i < candidates.size() && target > 0; i++){
        if(i != index && candidates[i] == candidates[i-1]) continue;
        combination.push_back(candidates[i]);
        combinationSum2Helper(candidates, combination, ans, target - candidates[i], i + 1);
        combination.pop_back();
    }
}

bool BackTracking::exist(vector<vector<char>>& board, string word){
    // Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"
    // Output: true
    for(int x = 0; x < board.size(); x++){
        for(int y = 0; y < board[x].size(); y++){
            if(existHelper(board, word, x, y, 0))
                return true;
        }
    }
    return false;
}

bool BackTracking::existHelper(vector<vector<char>>& board, string word, int m, int n, int index){
    // choices : we can choose cell [m][n] if it matches word
    // constraints : if we don't have our subset word matching word, we keep going or out of bound
    // goal : subset of string matches wrod

    if(index == word.size()){
        return true;
    }
    
    if(m < 0 || n < 0 || m > board.size()-1 || n > board[0].size()-1) return false; // board out of bound check
    if(board[m][n] != word[index]) return false; // word char does not match the one on the board at that point
    
    board[m][n] = '*';
    bool exists = existHelper(board, word, m + 1, n, index + 1) ||
                    existHelper(board, word, m - 1, n, index + 1) ||
                    existHelper(board, word, m, n + 1, index + 1) ||
                    existHelper(board, word, m, n - 1, index + 1);

    board[m][n] = word[index];
    return exists;
}


vector<vector<string>> BackTracking::partition(string s){
    // Input: s = "aab"
    // Output: [["a","a","b"],["aa","b"]]
    vector<vector<string>> res;
    vector<string> subset;
    partitionHelper(s, subset, res, 0);
    return res;
}

void BackTracking::partitionHelper(string &s, vector<string> &subset, vector<vector<string>> &ans, int index){
    if(index == s.size()){
        ans.push_back(subset);
        return;
    }

    for(int i = index; i < s.size(); i++){
        if(isPalindrome(s, index, i)){
            subset.push_back(s.substr(index, i - index + 1)); // index or original index to i- which is iterating every dfs 
            partitionHelper(s, subset, ans, i + 1);
            subset.pop_back();
        }
    }
}


bool BackTracking::isPalindrome(string &s, int l, int r){
    while(l < r){
        if(s[l++] != s[r--])
            return false;
    }
    return true;
}

vector<string> BackTracking::letterCombinations(string digits){
    // Input: digits = "23"
    // Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]
    if (!digits.size())
        return {};
    vector<string>letter({"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"});
    vector<string> ans;
    string subset;
    letterCombinationsHelper(digits, subset, ans, letter, 0);
    return ans;
}

void BackTracking::letterCombinationsHelper(string &digits, string subset, vector<string> &ans, vector<string> &letter, int index){
    if(index == digits.size()){
        ans.push_back(subset);
        return;
    }

    int d = digits[index] - '0'; // get digit's to int "23" -> 2 and 3
    for(int i = 0; i < letter[d].size(); i++){
        letterCombinationsHelper(digits, subset + letter[d][i], ans, letter, index + 1);
    }
}