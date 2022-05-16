#include "binary_search.h"
#include <vector>

using namespace std;

int BINARY_SEARCH::search(vector<int> nums, int target){
    // Input: nums = [-1,0,3,5,9,12], target = 9
    // Output: 4
    int l = 0, r = nums.size() - 1;
    
    while(l < r){
        int mid = l + (r - l) / 2;
        if(nums[mid] < target){
            l = mid + 1;
        } else if(nums[mid] > target){
            r = mid;
        } else{
            return mid;
        }
    }

    return -1;
}


