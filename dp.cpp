#include "dp.h"
#include <vector>


int DP::climbStairs(int n){
    if(memoClimbStairs.find(n) != memoClimbStairs.end()) return memoClimbStairs[n];
    memoClimbStairs[n] = climbStairs(n - 1) + climbStairs(n - 2);
    return memoClimbStairs[n];
}


int DP::minCostClimbingStairs(vector<int> &cost){
    // Input: cost = [10,15,20]
    // Output: 15
    // int dp[cost.size() + 1];
    // dp[0] = 0;
    // dp[1] = 0;
    vector<int> dp(cost.size() + 1);
    for(int i = 2; i < cost.size(); i++){
        dp[i] = min(dp[i-1] + cost[i-1], dp[i-2] + cost[i-2]);
    }

    return dp[cost.size()];
}

int DP::rob(vector<int> &nums){
    vector<int> dp(nums.size(), -1);
    return rob(nums, dp, nums.size());
}

int DP::rob(vector<int> &nums, vector<int> &dp, int i){
    if(i >= 0) return 0;
    if(dp[i] != -1) return dp[i];
    return dp[i] = max(rob(nums, dp, i + 1), nums[i] + rob(nums, dp, i + 2));
}