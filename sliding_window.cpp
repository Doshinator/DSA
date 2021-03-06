#include "sliding_window.h"
#include <vector>
#include <string>
#include <set>
#include <unordered_map>
#include <deque>
#include <iostream>

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

int SLIDING_WINDOW::characterReplacement(string s, int k){
    // Input: s = "ABAB", k = 2
    // Output: 4
    // Explanation: Replace the two 'A's with two 'B's or vice versa.
    unordered_map<char,int> count;
    int l = 0, r = 0, res = 0;
    int maxf = 0;
    while(r < s.size()){
        count[s[r]]++;
        maxf = std::max(maxf, count[s[r]]); 
        if((r - l + 1) - maxf > k){
            count[s[l]]--;
            l++;
        }
        res = std::max(res, (r - l + 1));
        r++;
    }
    return res;
}



vector<int> SLIDING_WINDOW::maxSlidingWindow(vector<int> nums, int k){
    // Input: nums = [1,3,-1,-3,5,3,6,7], k = 3
    // Output: [3,3,5,5,6,7]
    //      0, 1, 2,  3,  4, 5, 6, 7
    //      1, 3, -1, -3, 5, 3, 6, 7
    //         l       r             
    // q : 3 -1 3
    // res : 3 3 5 5 6 7
    vector<int> res;
    deque<int> q;
    int l = 0, r = 0;

    while(r < nums.size()){
        while(!q.empty() && nums[q.back()] < nums[r])
            q.pop_back();

        q.push_back(r);

        if(l > q.front())
            q.pop_front();

        if(r - l + 1 == k){
            res.push_back(nums[q.front()]);
            l++;
        }
        r++;
    }

    return res;
}



string minWindow(string s, string t){
    // Input: s = "ADOBECODEBANC", t = "ABC"
    // Output: "BANC"
    

    // min window len = min(min window len, window start - window end)
    // start of window = first char in string s that is in t 
    // keep iteraitng until used up all char from string t
    // end of window = last char used in string t 
    // calculate the window len
    // start next window - begin at the ending of last window point
    // stop at last char

    int l = 0, r = 0;
    string res;
    int minString = INT_MAX;
    unordered_map<char, int> m;
    unordered_map<char, int> m2;
    for(int i = 0 ; i < t.size(); i++){
        m[t[i]]++;
        m2[t[i]]++;
    }

    while(r < s.size()){
        if(m.find(s[r]) != m.end()){
            l = r;
            string str;
            while(!m.empty()){
                m[s[r]]--;
                str.push_back(s[r]);
                if(m[s[r]] == 0){
                    m.erase(s[r]);
                }
                r++;     
            }

            if(str.size() < minString)
                res = str;
            l = r;
            m = m2;
        }
       
    }

    return res;
}