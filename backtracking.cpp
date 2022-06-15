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
    if(index == nums.size()){
        ans.push_back(subset);
        return;
    }

    for(int i = index; i < nums.size(); i++){
        subset.push_back(nums[i]);
        subsetsHelper(nums, subset, ans, index + 1);
        subset.pop_back();
    }

}

vector<vector<int>> BackTracking::combinationSum(vector<int>& candidates, int target){
    std::sort(candidates.begin(), candidates.end());
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
    
    for(int i = index; i < candidates.size() && target >= candidates[i]; i++){
        combination.push_back(candidates[i]);
        combinationSumHelper(candidates, combination, ans, target - candidates[i], i);
        combination.pop_back();
    }
}


vector<vector<int>> BackTracking::permute(vector<int>& nums){
    // [1,2,3] 
    // [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
    vector<vector<int>> ans;
    vector<int> permutations;
    permuteHelper(nums, permutations, ans, 0);
    return ans;
}

void BackTracking::permuteHelper(vector<int>& nums, vector<int> permutations, vector<vector<int>> ans, int index){
    if(index == nums.size()){
        ans.push_back(permutations);
        return;
    }
    
}