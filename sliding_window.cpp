#include "sliding_window.h"
#include <vector>
#include <string>
#include <set>
#include <unordered_map>

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


bool SLIDING_WINDOW::checkInclusion(string s1, string s2){
    // Input: s1 = "ab", s2 = "eidbaooo"
    // Output: true
    // count freq of char in s1 .. 
    // make the window of sized s1?
    // go through s2 by the length of the window size to check for char and it's frequency in m1 - ??
    // return true if freq matches of m1 == m2 for that window size

    unordered_map<char, int> m;
    for(int i = 0; i < s1.size(); i++){
        m[s1[i]]++;
    }
    int mapSize = m.size(), lenS1 = s1.size();
    int l = 0, r = 0;
    
    // loop through string 2
    while(r < s2.size()){
        // if string 2 char is in map containing the char and their frequency in s1
        if(m.find(s2[r]) != m.end()){
            m[s2[r]]--;
            if(m[s2[r]] == 0)
                mapSize--;
        }
        if(r - l + 1 < lenS1)
            r++;
        // need to understand and finish the rest
    

    }
    return false;
}