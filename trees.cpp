#include "trees.h"
#include <queue>
#include <vector>

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
        for(int i = 0, n = q.size(); i < n; i++){
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


TreeNode* TREES::lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q){
    if(!root) return nullptr;
    
    if((p->val < root->val) && (q->val < root->val)){
        return lowestCommonAncestor(root->left, p, q);
    } else if((p->val > root->val) && (q->val > root->val)){
        return lowestCommonAncestor(root->right, p, q);
    } else {
        return root;
    }
}

vector<vector<int>> TREES::levelOrder(TreeNode* root){
    vector<vector<int>> res;
    queue<TreeNode*> q;
    q.push(root);
    if(!root) return res;

    while(!q.empty()){
        vector<int> nodes;
        for(int i = 0, n = q.size(); i < n; i++){
            TreeNode* node = q.front();
            q.pop();
            nodes.push_back(node->val);
            
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
        }
        res.push_back(nodes);
    }
    return res;

    //  recursive method - check helper function
    // int depth = 0;
    // levelOrderHelper(root, depth, res);
}

void TREES::levelOrderHelper(TreeNode* root, int depth, vector<vector<int>> &res){
    if(!root) return;
    if(depth == res.size()) res.push_back({});
    res[depth].push_back(root->val);

    levelOrderHelper(root->left, depth + 1, res);
    levelOrderHelper(root->right, depth + 1, res);
}

vector<int> TREES::rightSideView(TreeNode* root){
    vector<int> res;
    rightSideViewHelper(root, res);
    return res;
}

void TREES::rightSideViewHelper(TreeNode* root, vector<int> &res, int depth){
    // base case
    if(!root) return;

    // and pre conditions you want to check for the current node before recursing into childrens node?
    if(depth == res.size())
        res.push_back(root->val);
    
    // recurse
    rightSideViewHelper(root->right, res, depth + 1);
    rightSideViewHelper(root->left, res, depth + 1);

    // any post condition you want calculate and return to the parent node from the calculation of two childrens node
}
