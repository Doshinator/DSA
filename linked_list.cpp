#include "linked_list.h"

#include <unordered_map>
using namespace std;

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
}


ListNode* LINKED_LIST::removeNthFromEnd(ListNode* head, int n){
    // Input: head = [1,2,3,4,5], n = 2
    // Output: [1,2,3,5]

    ListNode* fast = head;
    ListNode* slow = head;

    for(int i = 0; i < n; i++){
        fast = fast->next;
    }

    while(fast->next != nullptr){
        slow = slow->next;
        fast = fast->next;
    }

    ListNode* temp = slow->next;
    slow->next = slow->next->next;
    delete(temp);

    return head;
}

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2){
    ListNode* sum = new ListNode(0);
    ListNode* node = sum;
    int carry = 0;

    while(carry || l1 || l2){
        int a = l1? l1->val : 0;
        int b = l2? l2->val : 0;
        carry = carry + a + b;

        node->next = new ListNode(carry % 10);
        node = node->next;
        
        carry /= 10;

        l1? l1 = l1->next : nullptr;
        l2? l2 = l2->next : nullptr;
    }
    
    return sum->next;
}

bool LINKED_LIST::hasCycle(ListNode *head){
    ListNode* slow = head;
    ListNode* fast = head;
    while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast)
            return true;
    }
    return false;
}

ListNode* LINKED_LIST::deleteDuplicates(ListNode* head){
    // 1, 1, 2
    // 1, 2

    ListNode* node = head;
    
    while(node && node->next){
        if(node->val == node->next->val){
            ListNode* temp = node->next;
            node->next = node->next->next;
            delete(temp);
        } else {
            node = node->next;
        }
    }
    return head;
}


int LRUCache::get(int key){
    if(m.find(key) == m.end())
        return -1;
    // map<int, list<pair<int,int>>::iterator>
    // have to re arrange list such that key gotten is now in front of the list (most recently used)
    list<pair<int,int>>::iterator it = m[key];
    l.splice(l.begin(), l, it);
    
    return it->second;
}

/*

LRUCache lRUCache = new LRUCache(2);
lRUCache.put(1, 1); // cache is {1=1}
lRUCache.put(2, 2); // cache is {1=1, 2=2}
lRUCache.get(1);    // return 1
lRUCache.put(3, 3); // LRU key was 2, evicts key 2, cache is {1=1, 3=3}

*/


void LRUCache::put(int key, int value){
    // if key's in the map, this will be most recently used and value needs to be updated for that key
    if(m.find(key) != m.end()){
        l.splice(l.begin(), l, m[key]);
        m[key]->second = value;
        return;
    }

    // evict least recent (back of list) and delete from map
    if(m.size() == capacity){
        m.erase(l.back().first);
        l.pop_back();
    }

    // default case to just push key value front
    l.push_front(make_pair(key, value));
    m[key] = l.begin();
}  