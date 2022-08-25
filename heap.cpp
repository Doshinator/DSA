#include "heap.h"
#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>

using namespace std;

KthLargest::KthLargest(int k, vector<int> nums){
    size = k;
    for(auto n : nums)
        q.push(n);
}


int KthLargest::add(int val){
    q.push(val);
    
    while(q.size() > size)
        q.pop();

    return q.top();
}

int Heap::lastStoneWeight(vector<int> stones){
    // Input: stones = [2,7,4,1,8,1]
    // Output: 1
    // Explanation: 
    // We combine 7 and 8 to get 1 so the array converts to [2,4,1,1,1] then,
    // we combine 2 and 4 to get 2 so the array converts to [2,1,1,1] then,
    // we combine 2 and 1 to get 1 so the array converts to [1,1,1] then,
    // we combine 1 and 1 to get 0 so the array converts to [1] then that's the value of the last stone.
    // 8, 7, 4, 2, 1, 1
    // 8 - 7 | 4, 2, 1, 1, push(8-7)
    // 4 - 2 | push(4 - 2), 1, 1, push(8 - 7)
    // 2 - 1 | push(2 - 1), 1, push(8 - 7)
    // 1 - 1 | push(0) , push(8 - 1)
    // 1 - 0? or do we not include 0? 

    priority_queue<int> q(stones.begin(), stones.end());

    while(q.size() >= 2){
        int y = q.top(); q.pop();
        int x = q.top(); q.pop();
        q.push(y - x);
    }

    return q.top();
}

vector<vector<int>> kClosest(vector<vector<int>> points, int k){
    // √(x1 - x2)^2 + (y1 - y2)^2 
    // origin : (0, 0)
    // point 1 : (1, 3)
    // point 2 : (-2, 2)
    // √((1 - 0)^2 + (3 - 0)^2) = √(1 + 9) = √(10)
    // √((-2 - 0)^2 + (2 - 0)^2) = √(4 + 4) = √(8)
    // √(10) > √(8) so we return (-2, 2)
    
    vector<vector<int>> res;
    priority_queue<vector<int>, vector<vector<int>>, Heap::compare> q;
    
    for(int i = 0; i < points.size(); i++){
        q.push(points[i]);
        if(q.size() > k)
            q.pop();
    }


    while(!q.empty()){
        res.push_back(q.top());
        q.pop();
    }

    return res;
}


int Heap::findKthLargest(vector<int> nums, int k){
    // priority_queue<int, vector<int>, greater<int>> minHeap; 
    // for(int i = 0; i < nums.size(); i++){
    //     minHeap.push(nums[i]);
    //     if(minHeap.size() > k)
    //         minHeap.pop();
    // }
    // return minHeap.top();

    priority_queue<int> maxHeap;
    for(int i = 0; i < nums.size(); i++){
        maxHeap.push(nums[i]);
    }
    for(int i = 0; i < k - 1; i++){
        maxHeap.pop();
    }
    return maxHeap.top();
}

int Heap::leastInterval(vector<char> tasks, int n){
    int maxCount = 0, e = 0;

    unordered_map<char, int> m;
    for(auto task : tasks){
        m[task]++;
    }

    for(auto it : m){
        maxCount = std::max(maxCount, it.second);
    }

    for(auto it : m){
        if(it.second == maxCount)
            e++;
    }

    return max((int)tasks.size(), (maxCount-1)*(n+1) + e);
}


void Twitter::postTweet(int userId, int tweetId){
    post.push_back({userId, tweetId});
}

vector<int> Twitter::getNewsFeed(int userId){
    vector<int> ans;
    for(int i = post.size() - 1, n = 10; i >= 0 && n > 0; i--){
        if(post[i].first == userId || followers[userId].find(post[i].first) != followers[userId].end()){
            ans.push_back(post[i].second);
            n--;
        }
    }
    return ans;
}

void Twitter::follow(int followerId, int followeeId){
    followers[followerId].insert(followeeId);
}

void Twitter::unfollow(int followerId, int followeeId){
    followers[followerId].erase(followeeId);
}


void MedianFinder::addNum(int num){
    // 4 4 - insert depends on element size > or < top of min or max heap
    // 5 4 - if element needs to be inserted to heap of lower size - insert
    // 4 5 - if element needs to be inserted to heap of the greater size - resize the heap and then insert
    if(maxHeap.empty() || num < maxHeap.top()){
        maxHeap.push(num); // the smaller number goes on maxHeap which contains smaller element
    }else{
        minHeap.push(num); 
    }

    if(maxHeap.size() > minHeap.size() + 1){
        minHeap.push(maxHeap.top());
        maxHeap.pop();
    }
    else if(maxHeap.size() + 1 < minHeap.size()){
        maxHeap.push(minHeap.top());
        minHeap.pop();
    }
    
}

double MedianFinder::findMedian(){
    if(minHeap.size() == maxHeap.size()) 
        return (minHeap.top() + maxHeap.top()) / 2.0;

    return minHeap.size() < maxHeap.size()? maxHeap.top() : minHeap.top();
}

vector<int> Heap::mergeKSortedArray(vector<vector<int>> &nums){
    /* Input
    [
        [1,2,3,4],
        [3,5,7].
        [4,6,8]
    ]
    */ 
    // out = [1,2,3,3,4,4,5,6,7,8]
    vector<int> res;
    int k = nums.size();
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> q;
    
    for(int i = 0; i < k; i++)
        q.push({nums[i][0], 0, i});

    while(!q.empty()){
        vector<int> data = q.top(); q.pop();
        int element = data[0];
        int index = data[1];
        int row = data[2];
        
        res.push_back(element);

        int next_index = index + 1;
        int next_element = nums[row][next_index];
        
        if(next_index < nums[row].size())
            q.push({next_element, next_index, row});
        
    }
    return res;
}