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


    
    std::cout << a->encode({"Hello", "World"}) << std::endl;

    for(int i = 0; i < a->decode(a->encode({"Hello", "World"})).size() ; i++){
        std::cout << a->decode(a->encode({"Hello", "World"}))[i] << endl;
    }
    

    Test::printResult();
    return 0;
    
}

