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

    ListNode* list1 = head;

    ListNode* mid = LINKED_LIST::midNode(head);
    ListNode* list2 = reverseList(mid);

    int i = 1;
    list1 = head->next;
    while(list1 != list2){
        if(i){
            head->next = list2;
            list2 = list2->next;
        } else{
            head->next = list1;
            list1 = list1->next;
        }
            head = head->next;
        i ^= 1;
}