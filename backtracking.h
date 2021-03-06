#ifndef _BACKTRACKING_H_
#define _BACKTRACKING_H_

#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class BackTracking{
    public:
    vector<vector<int>> subsets(vector<int> &nums);
    void subsetsHelper(vector<int> &nums,vector<int> &subset, vector<vector<int>> &ans, int index);

    vector<vector<int>> combinationSum(vector<int>& candidates, int target);
    void combinationSumHelper(vector<int>& candidates, vector<int> &combination, vector<vector<int>> &ans, int target, int index);

    vector<vector<int>> permute(vector<int>& nums);
    void permuteHelper(vector<int> nums, vector<vector<int>> &ans, int index);

    vector<vector<int>> subsetsWithDup(vector<int>& nums);
    void subsetsWithDupHelper(vector<int>& nums, vector<int> &subset, vector<vector<int>> &ans, int index);

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target);
    void combinationSum2Helper(vector<int>& candidates, vector<int> &combination, vector<vector<int>> &ans, int target, int index);
    
    bool exist(vector<vector<char>>& board, string word);
    bool existHelper(vector<vector<char>>& board, string word, int m, int n, int index);

    vector<vector<string>> partition(string s);
    void partitionHelper(string &s, vector<string> &subset, vector<vector<string>> &ans, int index);
    bool isPalindrome(string &s, int l, int r);

    vector<string> letterCombinations(string digits);
    void letterCombinationsHelper(string &digits, string subset, vector<string> &ans, vector<string> &letter, int index);

    vector<vector<string>> solveNQueens(int n);
    void solveQueensHelper(vector<vector<string>> &ans, vector<string> &board, int &n, int r);
    bool validPosition(vector<string> &board, int r, int c, int &n);
};



#endif