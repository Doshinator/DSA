#include "binary_search.h"
#include <vector>
#include <iostream>
#include <math.h>
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
        if(matrix[r][0] <= target){
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


int BINARY_SEARCH::minEatingSpeed(vector<int> piles, int h){
    // Input: piles = [3,6,7,11], h = 8
    // Output: k = 4 bananaes koko can finish eating all the bananas from all the piles
    // hr[1, 2, 2, 3] = 8
    // 3 / can k be ?2.. 3.. <- 4 -> 5.. 6..
    // k = 1 will take 27hr , max hr we have is 8
    // k = 2 will take 15hr, max hr we have is 8
    // up to max k can be is 11, which means 11 bananaes can be cunsumed in an hour and it will take 4 hours to consume all 4 piles
   
    /*
        Logic..

        eating more bananas-hour, k, will lessen the hour it takes to finish all bananas
        eating less bananas-hour, k, will up the hours it takes to finish all bananas
        goal : eat less bananas-hour while keeping close to h
        so... if we have low k, resulting in high hours, bin search for other k values to the right of k 
        if we have a very high k, resulting in low hours, bin search left of k to find a potential new min k, keep track of current min
     
     */

    sort(piles.begin(), piles.end());
    int hours = 0;
    int l = 1, r = piles[piles.size() - 1]; // from k = 1 to k = max in piles to eat / hr
    double res = INT_MAX;
    
    while(l <= r){
        double k = l + (r - l) / 2;
        hours = 0;
        for(int i = 0; i < piles.size(); i++){
            hours = ceil(piles[i] / k) + hours;
        }
        if(hours <= h){
            r = k - 1;
            res = min(res, k);
        } else {
            l = k + 1;
        }
    }
    return res;
}


int BINARY_SEARCH::searchRotatedArray(vector<int> nums, int target){
    // Input: nums = [4,5,6,7,0,1,2], target = 0
    // Output: 4
    int l = 0, r = nums.size() - 1;
    int mid;
    while(l <= r){
        mid = l + (r - l) / 2;
        if(nums[mid] == target) return mid;
        
        if(nums[mid] >= nums[l]){
            if(target <= nums[mid] && target >= nums[l])
                r = mid - 1;
            else 
                l = mid + 1;
        } else {
            if(target >= nums[mid] && target <= nums[r])
                l = mid + 1;
            else
                r = mid - 1;
        }

    }

    return -1;
}

// Input
// ["TimeMap", "set", "get", "get", "set", "get", "get"]
// [[], ["foo", "bar", 1], ["foo", 1], ["foo", 3], ["foo", "bar2", 4], ["foo", 4], ["foo", 5]]
// Output
// [null, null, "bar", "bar", null, "bar2", "bar2"]

// Explanation
// TimeMap timeMap = new TimeMap();
// timeMap.set("foo", "bar", 1);  // store the key "foo" and value "bar" along with timestamp = 1.
// timeMap.get("foo", 1);         // return "bar"
// timeMap.get("foo", 3);         // return "bar", since there is no value corresponding to foo at timestamp 3 and timestamp 2, then the only value is at timestamp 1 is "bar".
// timeMap.set("foo", "bar2", 4); // store the key "foo" and value "bar2" along with timestamp = 4.
// timeMap.get("foo", 4);         // return "bar2"
// timeMap.get("foo", 5);         // return "bar2"

TimeMap::TimeMap(){

}

void TimeMap::set(string key, string value, int timestamp){
    m[key].push_back({timestamp, value});
}
string TimeMap::get(string key, int timestamp){
    if(m.find(key) == m.end()) return "";

    int l = 0, r = m[key].size() - 1;
    int mid;

    while(l <= r){
        mid = l + ((r - l) / 2);
        // if(timestamp < m[key][mid].first && timestamp >= m[key][mid - 1].first)
        //     return m[key][mid - 1].second;
        // else {
        // // if(timestamp > m[key][mid].first && timestamp < m[key][mid + 1].first)
        // //     return m[key][mid + 1].second;
        // // else if(timestamp == m[key][mid].first)
        //     return m[key][mid].second;
        // }
        
        if(timestamp < m[key][mid].first)
            r = mid - 1;
        else if(timestamp > m[key][mid].first)
            l = mid + 1;
        else
            return m[key][mid].second;
    }
    return r >= 0? m[key][r].second : "";
}

double findMedianSortedArrays(vector<int> nums1, vector<int> nums2){
    // Input: nums1 = [1,2], nums2 = [3,4]
    // Output: 2.50000
    double res;
    

    return res;
}