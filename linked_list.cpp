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