#include "sliding_window.h"
#include <vector>
#include <string>
#include <set>

using namespace std;


int SLIDING_WINDOW::maxProfit(vector<int> prices){
    // Input: prices = [7,1,5,3,6,4]
    // Output: 5
    int minPrice = INT_MAX;
    int res = INT_MIN;
    for(int i = 0; i < prices.size(); i++){
        minPrice = min(minPrice, prices[i]);
        res = max(res, abs(minPrice - prices[i]));
    }
    return res;
}


int SLIDING_WINDOW::lengthOfLongestSubstring(string s){
    int res = 0;
    // Input: s = "abcabcbb"
    // Output: 3
    int l = 0, r = 0;
    set<char> str;
    while(l < s.size() && r < s.size()){
        if(str.find(s[r]) != str.end()){
            str.erase(s[l]);
            l++;
        }
        str.insert(s[r]);
        r++;
        res = max(res, r - l);
    }
    return res;
}