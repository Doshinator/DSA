#include "array.h"
#include "test.h"
#include <iostream>



int main(){

    ARRAY *a;

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


    Test::printResult();
    return 0;
    
}

