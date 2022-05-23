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


ListNode* LINKED_LIST::mergeTwoLists(ListNode* list1, ListNode* list2){
    if(!list1) return list2;
    if(!list2) return list1;

    ListNode* mergedList = new ListNode(0);
    ListNode* node = mergedList;

    while(list1 && list2){
        if(list1->val < list2->val){
            node->next = list1;
            list1 = list1->next;
        } else {
            node->next = list2;
            list2 = list2->next;
        }
        node = node->next;
    }
    
    list1? node->next = list1 : node->next = list2;
    return mergedList->next;
}