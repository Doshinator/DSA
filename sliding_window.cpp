#include "sliding_window.h"
#include <vector>

using namespace std;


int SLIDING_WINDOW::maxProfit(vector<int> prices){
    // Input: prices = [7,1,5,3,6,4]
    // Output: 5
    int minPrice = INT_MAX;
    int res = INT_MIN;
    for(int i = 0; i < prices.size(); i++){
        minPrice = min(minPrice, prices[i]);
        res = max(res, abs(minPrice - prices[i]));
    }
    return res;
}