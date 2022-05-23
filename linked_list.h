#ifndef LINKED_LIST_H_
#define LINKED_LIST_H_


struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class LINKED_LIST{
    public:
    ListNode* reverseList(ListNode* head);
    void reorderList(ListNode* head);
    ListNode* midNode(ListNode* head);
};



#endif
