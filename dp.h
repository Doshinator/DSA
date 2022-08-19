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
    
    private:
    unordered_map<int, int> memoClimbStairs{{1, 1}, {2, 2}};
};