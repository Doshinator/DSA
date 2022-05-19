#ifndef BINARY_SEARCH_H_
#define BINARY_SEARCH_H_

#include <vector>

using namespace std;

class BINARY_SEARCH{
    public:
    int search(vector<int> nums, int target);
    bool searchMatrix(vector<vector<int>> matrix, int target);
    int minEatingSpeed(vector<int> piles, int h);
    int searchRotatedArray(vector<int> nums, int target);
};


#endif

