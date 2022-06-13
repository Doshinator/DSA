#ifndef _HEAP_
#define _HEAP_

#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Heap{
    public: 
    int lastStoneWeight(vector<int> stones);
    vector<vector<int>> kClosest(vector<vector<int>> points, int k);
    int findKthLargest(vector<int> nums, int k);
    int leastInterval(vector<char> tasks, int n);    

    
    struct compare{
        bool operator()(vector<int> p, vector<int> q){
            return p[0] * p[0] + p[1] * p[1] < q[0] * q[0] + q[1] * q[1];
        }
    };
};

class KthLargest{
    public:
    KthLargest(int k, vector<int> nums);
    int add(int val);
    private:
    int size;
    priority_queue<int, vector<int>, greater<int>> q;
    
};


class Twitter {
    public:
    Twitter(){}
    void postTweet(int userId, int tweetId);    
    vector<int> getNewsFeed(int userId);
    void follow(int followerId, int followeeId);
    void unfollow(int followerId, int followeeId);
    private:
    unordered_map<int, unordered_set<int>> followers;
    vector<pair<int,int>> post;
};



#endif