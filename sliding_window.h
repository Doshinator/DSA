#ifndef SLIDING_WINDOW_H_
#define SLIDING_WINDOW_H_

#include <vector>

using namespace std;

class SLIDING_WINDOW{
    public:
    int maxProfit(vector<int> prices);
    int lengthOfLongestSubstring(string s);
    int characterReplacement(string s, int k);
    vector<int> maxSlidingWindow(vector<int> nums, int k);
};

#endif