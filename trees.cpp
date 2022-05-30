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