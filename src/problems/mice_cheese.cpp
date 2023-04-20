/**
 *  Input: reward1 = [1,1,3,4], reward2 = [4,4,1,1], k = 2
 *  Output: 15
 *  In this example, the first mouse eats the 2nd (0-indexed) and 
 *  The 3rd types of cheese, and the second mouse eats the 0th and the 1st types of cheese.
 *  The total points are 4 + 4 + 3 + 4 = 15.
 *  It can be proven that 15 is the maximum total points that the mice can achieve.
*/
int miceAndCheese(vector<int>& reward1, vector<int>& reward2, int k){
    priority_queue<pair<int, int>> pq;
    int ans = 0;

    for (int i = 0; i < reward1.size(); i++) {
        pq.push({(reward1[i] - reward2[i]), i});
    }
    while (!pq.empty()) {
        auto top = pq.top();
        pq.pop();

        k > 0 ? ans += reward1[topPQ.second] : ans += reward2[topPQ.second];
        k--;
    }
    return ans;
}

/**
 *  we figure out what side is "stacked" to choose k elements to maximize the 'points' 
 *  stack := which side of the reward array has the greater value. 
 *  ig. calc arr1[i] - arr2[i]. If value >, that means arr1[i] > arr2[i]. If value <, that means arr1[i] < arr2[i]
 *  
 * 
 *  for k times, we add the max value from the appropriate side of the array
*/