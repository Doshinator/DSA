#include "array.h"
#include "test.h"
#include "two_ptr.h"
#include "sliding_window.h"
#include "stack.h"
#include <iostream>



int main(){

    ARRAY *a;
    TWO_PTR *p;
    SLIDING_WINDOW *sw;
    STACK *stk;


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

    Test::printResult();
    return 0;
    
}

