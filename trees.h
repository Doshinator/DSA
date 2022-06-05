#ifndef _TREES_H_
#define _TREES_H_

#include <vector>
#include <unordered_map>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };


class TREES{
    public:
    TreeNode* invertTree(TreeNode* root);
    int maxDepth(TreeNode* root);
    
    int diameterOfBinaryTree(TreeNode* root);
    int diameterOfBinaryTreeHelper(TreeNode* root, int &ans);
    
    bool isBalanced(TreeNode* root);
    int isBalancedHelper(TreeNode* root, bool &ans);

    bool isSameTree(TreeNode* p, TreeNode* q); 
    // void isSameTreeHelper(TreeNode* p, TreeNode* q, bool &ans); 
    bool isSubtree(TreeNode* root, TreeNode* subRoot);
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q);
    vector<vector<int>> levelOrder(TreeNode* root);
    void levelOrderHelper(TreeNode* root, int depth, vector<vector<int>> &res);
    vector<int> rightSideView(TreeNode* root);
    void rightSideViewHelper(TreeNode* root, vector<int> &res, int depth);
    int goodNodes(TreeNode* root);
    void goodNodesHelper(TreeNode* root, int greatest, int &ans);
    bool isValidBST(TreeNode* root);
    bool isValidBSTHelper(TreeNode* root, long int min, long int max);
    int kthSmallest(TreeNode* root, int k);
    void kthSmallestHelper(TreeNode* root, int k, vector<int> &ans);
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder);
    TreeNode* buildTreeHelper(vector<int> &preorder, unordered_map<int, int> &m, int &index, int l, int r); 
    int maxPathSum(TreeNode* root);
    int maxPathSumHelper(TreeNode* root, int &ans);
};


#endif