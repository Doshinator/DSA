#ifndef LINKED_LIST_H_
#define LINKED_LIST_H_

#include <unordered_map>
#include <list>

using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class LINKED_LIST{
    public:
    ListNode* reverseList(ListNode* head);
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2);
    void reorderList(ListNode* head);
    ListNode* midNode(ListNode* head);
    ListNode* removeNthFromEnd(ListNode* head, int n);
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2);
    bool hasCycle(ListNode *head);
    ListNode* deleteDuplicates(ListNode* head);
    ListNode* mergeKLists(vector<ListNode*> lists);
};

class LRUCache{
    public:
    LRUCache(int capacity) : capacity(capacity) {}
    int get(int key);
    void put(int key, int value);
    private:
    const int capacity;
    list<std::pair<int,int>> l;
    unordered_map<int, list<pair<int,int>>::iterator> m;
};


#endif
