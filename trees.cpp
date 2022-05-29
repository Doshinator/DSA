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