#include "linked_list.h"

ListNode* LINKED_LIST::reverseList(ListNode* head){
    ListNode* curr = head;
    ListNode* next = nullptr, *prev = nullptr;
    
    while(curr != nullptr){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
    return head;
}

ListNode* LINKED_LIST::midNode(ListNode* head){
    ListNode* fast = head;
    ListNode* slow = head;

    while(fast != nullptr && fast->next != nullptr){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

void LINKED_LIST::reorderList(ListNode* head){
    //Input: head = [1,2,3,4]
    // Output: [1,4,2,3]
    // l0 -> ln -> l1 -> ln-2 -> l2 -> ln-3...

    ListNode* node = head;
    ListNode* mid = LINKED_LIST::midNode(head);

    ListNode* list2 = reverseList(mid);
    
}