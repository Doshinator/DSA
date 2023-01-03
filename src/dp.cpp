#include "dp.h"



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
    return DP::robMemo(nums, dp, nums.size());
}

int DP::robTabulation(vector<int> &nums){
    int n = nums.size();
    if(n == 1) return nums[0];

    vector<int> dp(nums);
    dp[1] = max(nums[0], nums[1]);
    for(int i = 2; i < n; i++){
        dp[i] = max(dp[i-2] + nums[i], dp[i-1]);
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
    if(n == 1) return nums[0];

    // include the n[0] and don't include last  n[0...n-1] 
    // don't include n[0] and include last      n[1...n]   
    // take max
    vector<int> nums1(nums.begin()+1, nums.end());
    vector<int> nums2(nums.begin(), nums.end()-1);

    return max(DP::robTabulation(nums1), DP::robTabulation(nums2));
}

string DP::longestPalindromeTwoPtr(string s){
    // babad
    string res = "";
    // int res_l = 0, res_r = 0;
    int resultLength = 0;

    for(int i = 0; i < s.size(); i++){
        int l = i, r = i;
        // odd case
        while(l >= 0 && r < s.size() && s[l] == s[r]){
            // check for potential new result string and result length & update
            if(r - l + 1 > resultLength){
                res = s.substr(l, r - l + 1);
                // res_l = l;
                // res_r = r;
                resultLength = r - l + 1;
            }
            l--;
            r++;
        }
        // even case
        l = i, r = i + 1;
        while(l >= 0 && r < s.size() && s[l] == s[r]){
            // check for potential new reult stirng and result length & update
            if(r - l + 1 > resultLength){
                res = s.substr(l, r - l + 1);
                // res_l = l;
                // res_r = r;
                resultLength = r - l + 1;
            }
            l--;
            r++;
        }
    }
    // return s.substr(res_l, res_r - res_l + 1); - saves memory and time
    return res;
}


string DP::longestPalindromeTabulation(string s){
    int n = s.size();
    vector<vector<int>> dp(n, vector<int>(n));
    
    // set up dp table
    for(int i = 0; i < n; i++)
        dp[i][i] = 1;

    for(int i = 0; i < n - 1; i++)
        s[i] == s[i+1]? dp[i][i+1] =  1 : dp[i][i+1] = 0;

    // finish rest of tabulation method

    return "";
}


int DP::countSubstrings(string s){
    int count = 0;
    for(int i = 0; i < s.size(); i++){
        int l = i, r = i;
        while(l >= 0 && r < s.size() && s[l] == s[r]){
            count++;
            l--;
            r++;
        }

        l = i, r = i + 1;
        while(l >= 0 && r < s.size() && s[l] == s[r]){
            count++;
            l--;
            r++;
        }
    }

    return count;
}

int DP::countSubstringsMemoization(string s){

}

int DP::countSubstringsTabulation(string s){

}


bool DP::canJump(vector<int> &nums){
    //[2,3,1,1,4] -> t
    //[3,2,1,0,4] -> f
    return canJumpRecurse(nums, 0);
}

bool DP::canJumpRecurse(vector<int> &nums, int index){
    if(index == nums.size() - 1)
        return true;
    
    int steps = index + nums[index];
    for(int i = index + 1; i <= steps; i++){
        if(canJumpRecurse(nums, i))
            return true;
    }
    return false;
}


int DP::numDecodings(string s){
    return numDecodingRecursive(s, 0);
}

int DP::numDecodingRecursive(string s, int index){
    if(index == s.size())
        return 1;

    if(s[index] == '0')
        return 0;

    int res = numDecodingRecursive(s, index + 1);

    if(index < s.size() - 1 && 
        (s[index] == '1' || (s[index] == '2' && s[index + 1] < '7')))
    res +=  numDecodingRecursive(s, index + 2);

    return res;
}

int DP::numDecodingBottomUp(string s){
    int n = s.size();
    vector<int> dp(n + 1, 0);
    dp[n] = 1;

    for(int i = n - 1; i >= 0; i--){
        if(s[i] != '0')
            dp[i] += dp[i + 1];
        if(i+1 < s.size() && (s[i] == '1' || (s[i] == '2' && s[i + 1] <= '6')))
            dp[i] += dp[i + 2];
    }
    return dp[0];    
}


int DP::coinChange(vector<int> &coins, int amount){

}

int DP::coinChangeMemo(vector<int> &coins, int amount){
    // #1 - base case - if amount == 0, then you can take 0 coins to fufil that condition
    if(amount == 0)
        return 0;

    // #2 - choice
    // choice 1) pick current coin, solve remaining problem
    // choice 2) don't pick current coin, solve remaining problem
    // int pick =  1 + min(coinChange(coins[i + 1], amount - coins[i]), coinChange(coins[i], amount - coins[i]));

    // #3 - optimal ; optamize - take only minimum # of coins
}

int DP::coinChangeBottomUp(vector<int> &coins, int amount){
    vector<int> dp(amount + 1, amount + 1);
    dp[0] = 0;

    for(int i = 1; i <= amount; i++){
        for(int c = 0; c < coins.size(); c++){
            if(i - coins[c] >= 0)
                dp[i] = min(1 + dp[i - coins[c]], dp[i]);
        }
    }

   return dp[amount] == amount + 1? -1 : dp[amount];
}


int DP::maxProduct(vector<int>& nums){
    return maxProductBrute(nums);
}

int DP::maxProductBrute(vector<int> &nums){
    //[2, 3, -2, 4]
    // 1st iteration - i = 0, j = 0 -> 3
    // 2 * 3 = 6
    // 6 * -2 = -12
    // -12 * 4 = -48
    // 2nd iteration - i = 1, j = 1 -> 3
    // keep track of max every iteration O(n^2)
    int res = 0;
    for(int i = 0; i < nums.size(); i++){
        int product = 1;
        for(int j = i; j < nums.size(); j++){
            product *= nums[j];
            res = max(res, product);
        }
    }
    return res;
}


int DP::maxProductTabulation(vector<int> &nums){
    int res = nums[0];
    vector<int> dpMin(nums), dpMax(nums);
    
    for(int i = 1; i < nums.size(); i++){
        int n = nums[i];
        dpMin[i] = min(n, n * (n >= 0? dpMin[i-1] : dpMax[i-1]));
        dpMax[i] = max(n, n * (n >= 0? dpMax[i-1] : dpMin[i-1]));
        res = max(res, dpMax[i]);
    }

    return res;
}