#include "trees.h"
#include <queue>

using namespace std;

TreeNode* TREES::invertTree(TreeNode* root){
    if(root == nullptr)
        return root;

    TreeNode* temp = root->left;
    root->left = root->right;
    root->right = temp;
    

    invertTree(root->left);
    invertTree(root->right);
    
    return root;
}



int maxDepth(TreeNode* root){
    // depth first search
    // return !root? 0 : 1 + max(maxDepth(root->left), maxDepth(root->right));
    
    // bredth first search
    int res = 0;
    queue<TreeNode*> q;

    q.push(root);

    while(!q.empty()){
        res++;
        for(int i = 0; i < q.size(); i++){
            TreeNode* node = q.front();
            q.pop();
            
            if(node->left){
                q.push(node->left);
            }

            if(node->right){
                q.push(node->right);
            }
        }
        
    }

    return res;

}


int TREES::diameterOfBinaryTreeHelper(TreeNode* root, int &ans){
    if(root == nullptr)
        return 0;

    int leftH = diameterOfBinaryTreeHelper(root->left, ans);
    int rightH = diameterOfBinaryTreeHelper(root->right, ans);
    
    ans = max(ans, leftH + rightH);
    return 1 + max(leftH, rightH);
}

int TREES::diameterOfBinaryTree(TreeNode* root){
    int ans = 0;
    if(root == nullptr)
        return 0;
    diameterOfBinaryTreeHelper(root, ans);
    return ans;
}


int TREES::isBalancedHelper(TreeNode* root, bool &ans){
    if(root == nullptr)
        return 0;
    int leftH = isBalancedHelper(root->left, ans);
    int rightH = isBalancedHelper(root->right, ans);
    if(abs(rightH - leftH) > 1)
        ans = false;

    return 1 + max(rightH, leftH);
}

bool TREES::isBalanced(TreeNode* root){
    bool ans = true;
    isBalancedHelper(root, ans);
    return ans;
}


// void TREES::isSameTreeHelper(TreeNode* p, TreeNode* q, bool &ans){
//     if(p == nullptr || q == nullptr){
//         if(p != q)
//             ans = false;
        
//         return;
//     }
//     isSameTreeHelper(p->left, q->left, ans);
//     isSameTreeHelper(p->right, q->right, ans);

//     if(p == nullptr || q == nullptr || p->val != q->val)
//         ans = false;

// }

bool TREES::isSameTree(TreeNode* p, TreeNode* q){
    if(!p && !q) return true;
    if(!p || !q) return false;
    if(p->val != q->val) return false;

    bool leftTree = isSameTree(p->left, q->left);
    bool rightTree = isSameTree(p->right, q->right);

    return leftTree && rightTree;
}


bool TREES::isSubtree(TreeNode* root, TreeNode* subRoot){
    if(!root) return false;
    
    if(isSameTree(root, subRoot)) return true;
    
    return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
}   


TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q){
    
}
