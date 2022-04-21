#include "array.h"
#include <iostream>
#include <string>
#include <set>
#include <unordered_map>


bool ARRAY::containsDuplicate(vector<int> nums){

    return nums.size() > set<int>(nums.begin(), nums.end()).size();
}


