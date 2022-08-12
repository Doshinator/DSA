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


// memo
int DP::rob(vector<int> &nums){
    vector<int> dp(nums.size(), -1);
    return robMemo(nums, dp, nums.size());
}

int DP::robTabulation(vector<int> &nums){
    int n = nums.size();
    if(n == 1) return nums[0];

    vector<int> dp(nums);
    dp[1] = max(nums[0], nums[1]);
    for(int i = 2; i < n; i++){
        dp[i] = max(dp[i-1], dp[i-2] + nums[i]);
    }
    return dp[n-1];
}

int DP::robMemo(vector<int> &nums, vector<int> &dp, int i){
    if(i >= 0) return 0;
    if(dp[i] != -1) return dp[i];
    return dp[i] = max(robMemo(nums, dp, i + 1), nums[i] + robMemo(nums, dp, i + 2));
}

int DP::robII(vector<int> &nums){
    int n = nums.size();
    vector<int> dp(nums.size());
    if(nums.size() == 1) return nums[0];

    dp[1] = max(nums[0], nums[1]);
    for(int i = 0; i < n; i++){

    }

    return dp[n];
}