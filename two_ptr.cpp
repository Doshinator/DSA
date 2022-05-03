#include "two_ptr.h"
#include <unordered_map>

bool TWO_PTR::isPalindrome(string s){
    int l = 0, r = s.size() - 1;
    while(l < r){
        if(s[l] != s[r])
            return false;
        l++;
        r--;
    }

    return true;
}


vector<int> TWO_PTR::twoSum(vector<int> numbers, int target) {
    vector<int> res(2, -1);
    int l = 0, r = numbers.size() - 1;
    while(l < r){
        if(numbers[l] + numbers[r] == target){
            return {l + 1, r + 1};
        }

        if(numbers[l] + numbers[r] > target)
            r--;
        else
            l++;
    }

    return res;
}


vector<vector<int>> TWO_PTR::threeSum(vector<int> nums){
    vector<vector<int>> res;
    // Input: nums = [-1,0,1,2,-1,-4]
    // Output: [[-1,-1,2],[-1,0,1]]
    std::sort(nums.begin(), nums.end());
    for(int i = 0; i < nums.size(); i++){
        // a < b < c in a sorted array.. 
        // the aim is -1a=b+c
        // if the target -1a<0, then a>0. so b+c<0. But 0<a<b<c, so b+c<0 is impossible.
        if(nums[i] > 0)
            break;

        if (i > 0 and nums[i] == nums[i-1]) 
            continue;

        int l = i + 1, r = nums.size() - 1;
        while(l < r){
            int sum = nums[i] + nums[l] + nums[r];
            if(sum > 0){
                r--;
            } else if(sum < 0){
                l++;
            } else {
                res.push_back({nums[i], nums[l], nums[r]});
                int prev_l = nums[l], prev_r = nums[r];
                while(l < r && nums[l] == prev_l) l++;
                while(l < r && nums[r] == prev_r) r--;
            }

        }
        
    }
    return res;
}


int TWO_PTR::maxArea(vector<int> height){
    // Input: height = [1,8,6,2,5,4,8,3,7]
    // Output: 49

    int maxArea = INT_MIN;
    int l = 0, r = height.size() - 1;

    while(l < r){
        int area = (r - l) * min(height[l], height[r]);
        maxArea = max(maxArea, area);
        if(height[l] > height[r])
            r--;
        else 
            l++;
    }

    return maxArea;
}



int TWO_PTR::trap(vector<int> height){
    int water = 0;
    // Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
    // Output: 6
    int l = 0, r = height.size() - 1;
    int maxL = height[l], maxR = height[r];

    while(l < r){
        if(maxL < maxR){
            l++;
            maxL = max(maxL, height[l]);
            water += maxL - height[l];
        } else {
            r--;
            maxR = max(maxR, height[r]);
            water += maxR - height[r];
        }
    }

    return water;
}