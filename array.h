#ifndef ARRAY_H_
#define ARRAY_H_
#include <vector>
#include <string>
#include <map>
using namespace std;



class EASY{
    public:
    bool mapTest();
    bool containsDuplicate(vector<int> nums);
    int missingNumber(vector<int> nums);
    vector<int> findDisappearedNumbers(vector<int> nums);
    int singleNumber(vector<int> nums);
    int climbStairs(int n);
    int bestTimeBuySellStock(vector<int> prices);
    int maxSubArray(vector<int> nums);
    int sumRange(int l, int r, vector<int> nums);
    vector<string> summaryRanges(vector<int> nums);
    bool hasCycle(ListNode *head);
    ListNode* middleNode(ListNode* head);
    ListNode* reverseLinkedList(ListNode* head);
    bool isPalindrome(ListNode* head);
    ListNode* deleteDuplicates(ListNode* head);
    ListNode* removeElements(ListNode* head, int val);
    ListNode* removeNthFromEnd(ListNode* head, int n);
    TreeNode* invertTree(TreeNode* root);
    int maxDepthBinaryTree(TreeNode* root);
    int missingNumberInArray(vector<int> nums);
    bool isAnagram(string s, string t);
};

class MID{
    public:
    int knapsack(vector<int> items, vector<int> value, int weight, int n);
    vector<int> topKFrequent(vector<int> nums, int k);
};

#endif

