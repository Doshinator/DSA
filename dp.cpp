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

    // 0 - 2, 1 - 3, 2 - 4, 3 - 5
    for(int i = 0; i < n; i++){

    }

    return "";
}