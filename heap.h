#ifndef _HEAP_
#define _HEAP_

#include <vector>
#include <queue>

using namespace std;

class Heap{
    public: 
    int lastStoneWeight(vector<int> stones);
    vector<vector<int>> kClosest(vector<vector<int>> points, int k);
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



#endif