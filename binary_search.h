#ifndef BINARY_SEARCH_H_
#define BINARY_SEARCH_H_

#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class BINARY_SEARCH{
    public:
    int search(vector<int> nums, int target);
    bool searchMatrix(vector<vector<int>> matrix, int target);
    int minEatingSpeed(vector<int> piles, int h);
    int searchRotatedArray(vector<int> nums, int target);
};

class TimeMap{
    private:
    unordered_map<string, vector<pair<int,string>>> m;
    public:
    TimeMap();
    void set(string key, string value, int timestamp);
    string get(string key, int timestamp);
};


#endif

