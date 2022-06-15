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