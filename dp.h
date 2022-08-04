#include <vector>
#include <unordered_map>
using namespace std;

class DP{
    public:
    int climbStairs(int n);
    int minCostClimbingStairs(vector<int> &cost);
    private:
    unordered_map<int, int> memoClimbStairs{{1, 1}, {2, 2}};
};