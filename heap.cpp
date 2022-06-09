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
