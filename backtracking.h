#ifndef _BACKTRACKING_H_
#define _BACKTRACKING_H_

#include <vector>

using namespace std;

class BackTracking{
    public:
    vector<vector<int>> subsets(vector<int> &nums);
    void subsetsHelper(vector<int> &nums,vector<int> &subset, vector<vector<int>> &ans, int index);

    vector<vector<int>> combinationSum(vector<int>& candidates, int target);
    void combinationSumHelper(vector<int>& candidates, vector<int> &combination, vector<vector<int>> &ans, int target, int index);

    vector<vector<int>> permute(vector<int>& nums);
};



#endif