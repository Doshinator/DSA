#ifndef TWO_PTR_H_
#define TWO_PTR_H_

#include <string>
#include <vector>

using namespace std;

class TWO_PTR{
    public:
    bool isPalindrome(string s);
    vector<int> twoSum(vector<int> numbers, int target);
    vector<vector<int>> threeSum(vector<int> nums);
    int maxArea(vector<int> height);
};


#endif