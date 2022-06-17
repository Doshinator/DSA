#include "backtracking.h"
#include <vector>

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
    
    for(int i = index; i < candidates.size() && target >= candidates[i]; i++){
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

    for(int i = index; i < candidates.size() && target >= candidates[i]; i++){
        if(i != index && candidates[i] == candidates[i-1]) continue;
        combination.push_back(candidates[i]);
        combinationSum2Helper(candidates, combination, ans, target - candidates[i], i + 1);
        combination.pop_back();
    }
}