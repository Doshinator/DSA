#ifndef _HEAP_
#define _HEAP_

#include <vector>
#include <queue>

using namespace std;

class Heap{
    public: 

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