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

    
    
    
}

