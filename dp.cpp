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

