#include "backtracking.h"
#include <vector>

using namespace std;


vector<vector<int>> BackTracking::subsets(vector<int> &nums){
    vector<vector<int>> ans;
    vector<int> subset;
    subsetsHelper(nums, subset, ans, 0);
    return ans;
}

void BackTracking::subsetsHelper(vector<int> &nums,vector<int> &subset, vector<vector<int>> &ans, int index){ 
    if(index >= nums.size()){
        ans.push_back(subset);
        return;
    }
    subset.push_back(nums[index]);
    subsetsHelper(nums, subset, ans, index + 1);
    subset.pop_back();
    subsetsHelper(nums, subset, ans, index + 1);
}

vector<vector<int>> BackTracking::combinationSum(vector<int>& candidates, int target){
    vector<vector<int>> ans;
    vector<int> combination;
    combinationSumHelper(candidates, combination, ans, target, 0);
    return ans;
}

void BackTracking::combinationSumHelper(vector<int> &candidates, vector<int> &combination, vector<vector<int>> &ans, int target, int index){
    if(target == 0){
        ans.push_back(combination);
        return;
    }

    if(index >= candidates.size() || target < 0){
        return;
    }
    combination.push_back(candidates[index]);
    combinationSumHelper(candidates, combination, ans, target - candidates[index], index);
    combination.pop_back();
    combinationSumHelper(candidates, combination, ans, target, index + 1);
}