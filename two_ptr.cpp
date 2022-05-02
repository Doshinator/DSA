#include "two_ptr.h"

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