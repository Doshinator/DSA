#include <vector>
#include <unordered_map>
using namespace std;

class DP{
    public:
    int climbStairs(int n);
    int minCostClimbingStairs(vector<int> &cost);
    int rob(vector<int> &nums);
    int rob(vector<int> &nums, vector<int> &dp, int i);

    private:
    unordered_map<int, int> memoClimbStairs{{1, 1}, {2, 2}};
};