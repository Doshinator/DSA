#include "heap.h"
#include <vector>
#include <queue>

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