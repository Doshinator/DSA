#ifndef _BACKTRACKING_H_
#define _BACKTRACKING_H_

#include <vector>

using namespace std;

class BackTracking{
    public:
    vector<vector<int>> subsets(vector<int> &nums);
    void subsetsHelper(vector<int> &nums,vector<int> &subset, vector<vector<int>> &ans, int index);
};



#endif