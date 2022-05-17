#include "binary_search.h"
#include <vector>
#include <iostream>

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


bool BINARY_SEARCH::searchMatrix(vector<vector<int>> matrix, int target){
    int top = 0;
    int bottom = matrix.size() - 1;
    int r = 0, ans = 0;

    // bind search the first column to find where to search target value in what row

    while(top <= bottom){
        r = top + (bottom - top) / 2;
        if(matrix[r][matrix[0].size() - 1] <= target){
            top = r + 1;
        } else if(matrix[r][0] > target){
            bottom = r - 1;
        } else {
            break;
        }
    }

    int low = 0, high = matrix[r].size() - 1;
    int mid = 0;
    while(low <= high){
        mid = low + (high - low) / 2;
        if(matrix[r][mid] < target){
            low = mid + 1;
        } else if(matrix[r][mid] > target){
            high = mid - 1;
        } else {
            return true;
        }
    }

    return false;
    
}
