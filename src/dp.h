#include <vector>
#include <unordered_map>
#include <string>
using namespace std;

class DP{
    public:
    int climbStairs(int n);
    int minCostClimbingStairs(vector<int> &cost);

    int rob(vector<int> &nums);
    int robTabulation(vector<int> &nums);
    int robMemo(vector<int> &nums, vector<int> &dp, int i);

    int robII(vector<int> &nums);
    
    string longestPalindromeTwoPtr(string s);
    string longestPalindromeTabulation(string s);

    int countSubstrings(string s);
    int countSubstringsMemoization(string s);
    int countSubstringsTabulation(string s);

    bool canJump(vector<int> &nums);
    bool canJumpRecurse(vector<int> &nums, int index);

    int numDecodings(string s);
    int numDecodingRecursive(string s, int index);
    int numDecodingBottomUp(string s);

    int coinChange(vector<int> &coins, int amount);
    int coinChangeMemo(vector<int> &coins, int amount);
    int coinChangeBottomUp(vector<int> &coins, int amount);

    int maxProduct(vector<int> &nums);
    int maxProductBrute(vector<int> &nums);
    int maxProductTabulation(vector<int> &nums);

    bool canPartition(vector<int> &nums);

    int fib(int n);
    
    private:
    unordered_map<int, int> memoClimbStairs{{1, 1}, {2, 2}};
};