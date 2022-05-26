#include "test.h"
#include "array.h"
#include "two_ptr.h"
#include "sliding_window.h"
#include "stack.h"
#include "binary_search.h"
#include "linked_list.h"
#include <iostream>



int main(){

    ARRAY *a;
    TWO_PTR *p;
    SLIDING_WINDOW *sw;
    STACK *stk;
    BINARY_SEARCH *bin_search;


    Test(true, a->containsDuplicate({5, 4, 4, 3}));
    Test(false, a->containsDuplicate({5, 1, 4, 3, 2}));

    Test(true, a->isAnagram("anagram", "nagaram"));
    Test(false, a->isAnagram("car", "rat"));


    Test({0, 1}, a->twoSum({2,7,11,15}, 9));
    Test({1, 2}, a->twoSum({3,2,4}, 6));

    Test({1, 2}, a->topKFrequent({1,1,1,2,2,3},2));
    Test({1}, a->topKFrequent({1}, 1));

    Test({24,12,8,6}, a->productExceptSelf({1,2,3,4}));

    Test(4, a->longestConsecutive({100,4,200,1,3,2}));
    Test(9, a->longestConsecutive({0,3,7,2,5,8,4,6,0,1}));

    Test(4, a->countPrime(10));
    Test(9, a->countPrime(25));
    Test(1229, a->countPrime(10000));

    Test(1, p->isPalindrome("atoyotasatoyota"));

    Test({1, 2}, p->twoSum({2,7,11,15}, 9));
    Test({1, 3}, p->twoSum({2,3,4}, 6));
    

    Test(49, p->maxArea({1,8,6,2,5,4,8,3,7}));
    Test(1, p->maxArea({1,1}));

    
    Test(6, p->trap({0,1,0,2,1,0,1,3,2,1,2,1}));
    Test(9, p->trap({4,2,0,3,2,5}));

    Test(5, sw->maxProfit({7,1,5,3,6,4}));
    Test(0, sw->maxProfit({7,6,4,3,1}));

    Test(3,sw->lengthOfLongestSubstring("abcabcbb"));
    Test(1,sw->lengthOfLongestSubstring("bbbbb"));

    Test(4, sw->characterReplacement("ABAB", 2));
    Test(4, sw->characterReplacement("AABABBA", 1));
    
    Test({3,3,5,5,6,7}, sw->maxSlidingWindow({1,3,-1,-3,5,3,6,7}, 3));
    Test({1}, sw->maxSlidingWindow({1}, 1));

    Test(true, stk->isValid("()[]{}"));
    Test(false, stk->isValid("(}"));

    /* min stack */
    // MinStack *minStack;
    // minStack->push(5);
    // Test(5, minStack->top());
    // Test(5, minStack->getMin());

    // minStack->push(-2);
    // Test(-2, minStack->top());
    // Test(-2, minStack->getMin());

    // minStack->push(-3);
    // Test(-3, minStack->top());
    // Test(-3, minStack->getMin());

    // minStack->push(-20);
    // Test(-20, minStack->top());
    // Test(-20, minStack->getMin());

    Test(9, stk->evalRPN({"2","1","+","3","*"}));
    Test(6, stk->evalRPN({"4","13","5","/","+"}));
    Test(2, stk->evalRPN({"13","5","/"}));

    Test({"((()))","(()())","(())()","()(())","()()()"}, stk->generateParenthesis(3));
    Test({"()"}, stk->generateParenthesis(1));

    Test({1,1,4,2,1,1,0,0}, stk->dailyTemperatures({73,74,75,71,69,72,76,73}));
    Test({1,1,1,0}, stk->dailyTemperatures({30,40,50,60}));

    Test(3, stk->carFleet(12, {10,8,0,5,3}, {2,4,1,1,3}));
    Test(1, stk->carFleet(100, {0, 2, 4}, {4, 2, 1}));
    Test(4, stk->carFleet(17, {8,12,16,11,7}, {6,9,10,9,7}));

    Test(10, stk->largestRectangleArea({2,1,5,6,2,3}));
    Test(2, stk->largestRectangleArea({1,1}));
    Test(10, stk->largestRectangleArea({5,6}));
    
    Test(4, bin_search->search({-1,0,3,5,9,12}, 9));
    Test(-1, bin_search->search({-1,0,3,5,9,12}, 2));

    Test(1, bin_search->searchMatrix({{1,3,5,7},{10,11,16,20},{23,30,34,60}}, 3));
    Test(0, bin_search->searchMatrix({{1,3,5,7},{10,11,16,20},{23,30,34,60}}, 13));
    Test(1, bin_search->searchMatrix({{1}}, 1));
    Test(1, bin_search->searchMatrix({{1,3}}, 3));

    Test(4, bin_search->minEatingSpeed({3, 6, 7, 11}, 8));
    Test(30, bin_search->minEatingSpeed({30,11,23,4,20}, 5));
    Test(23, bin_search->minEatingSpeed({30,11,23,4,20}, 6));

    Test(4, bin_search->searchRotatedArray({4,5,6,7,0,1,2}, 0));
    Test(-1, bin_search->searchRotatedArray({4,5,6,7,0,1,2}, 3));
    Test(1, bin_search->searchRotatedArray({3,1}, 1));
    Test(5, bin_search->searchRotatedArray({4,5,6,7,0,1,2}, 1));

    TimeMap *T = new TimeMap();
    T->set("foo", "bar", 1);
    T->set("foo", "bar2", 4);

    Test("bar", T->get("foo", 3));
    Test("bar2", T->get("foo", 6));

    // ---- LRU ----
    LRUCache *lru = new LRUCache(2);

    lru->put(1, 1);
    lru->put(2, 2);

    Test(1, lru->get(1));

    lru->put(3, 3);
    Test(-1, lru->get(2));
    
    lru->put(4, 4);
    Test(-1, lru->get(1));
    Test(3, lru->get(3));
    Test(4, lru->get(4));
    

    Test::printResult();
    return 0;
    
}

