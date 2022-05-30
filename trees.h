#ifndef _TREES_H_
#define _TREES_H_

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
};


#endif