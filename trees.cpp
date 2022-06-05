#include "trees.h"
#include <queue>
#include <vector>
#include <unordered_map>
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
    rightSideViewHelper(root, res, 0);
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


int TREES::goodNodes(TreeNode* root){
    int ans = 0;
    goodNodesHelper(root, root->val, ans);
    return ans;
}



void TREES::goodNodesHelper(TreeNode* root, int greatest, int &ans){
    if(!root) return;

    // post condition for child
    if(root->val >= greatest) ans++;
    greatest = max(greatest, root->val);

    goodNodesHelper(root->left, greatest, ans);
    goodNodesHelper(root->right, greatest, ans);
}


bool TREES::isValidBST(TreeNode* root){
    return isValidBSTHelper(root, LONG_MIN, LONG_MAX);
}

bool TREES::isValidBSTHelper(TreeNode* root, long int left, long int right){
    if(!root) return true;
    
    if(root->val >= right)
        return false;

    if(root->val <= left)
        return false;

    return isValidBSTHelper(root->left, left, root->val) && isValidBSTHelper(root->right, root->val, right);
}


int TREES::kthSmallest(TreeNode* root, int k){
    vector<int> ans;
    kthSmallestHelper(root, k, ans);
    return ans[k - 1];
}


void TREES::kthSmallestHelper(TreeNode* root, int k, vector<int> &ans){
    // k-th smallest value in BST
    if(!root) return;

    kthSmallestHelper(root->left, k, ans);
    ans.push_back(root->val);
    kthSmallestHelper(root->right, k, ans);

    // keep a global int K 
    /*
    void dfs(TreeNode* root, &k){
        if(!root) return;
        dfs(root->left, k);
        k = k - 1; // this is global counter
        if(k == 0) ans = root->val;
        dfs(root->right, k);
    }
    */
}


TreeNode* TREES::buildTree(vector<int>& preorder, vector<int>& inorder){
    unordered_map<int, int> m;
    for(int i = 0; i < inorder.size(); i++){
        m[inorder[i]] = i;
    }

    // pre-order : [1, 2, 4, 5, 3, 6, 7, 9, 8]
    // in-order :  [4, 2, 5, 1, 3, 7, 9, 6, 8]
    // root is 1 ; pre-order[0]

    // pre-order : left subtree - 2, 4, 5 |  right subtree - 3, 6, 7, 9, 8
    // in-order : LHS = [4, 2, 5] | RHS = [3, 7, 9, 6, 8]
    
    int index = 0;
    int n = inorder.size();

    return buildTreeHelper(preorder, m, index, 0, n - 1);
}

TreeNode* TREES::buildTreeHelper(vector<int> &preorder, unordered_map<int, int> &m, int &index, int l, int r){
    if(l > r) return nullptr;
    
    TreeNode* root = new TreeNode(preorder[index]);
    index++;
    int mid = m[root->val];

    // left sub tree = dfs(preorder[1:mid], inorder[0, mid - 1]
    // right sub tree = dfs(preorder[mid + 1 : preorder.size() - 1], inorder[mid + 1 inorder.size() - 1 ])
    root->left = buildTreeHelper(preorder, m, index, l, mid - 1);
    root->right = buildTreeHelper(preorder, m, index, mid + 1, r);
    
    return root;
}
   

int TREES::maxPathSum(TreeNode* root){
    int ans = INT_MIN;
    maxPathSumHelper(root, ans);
    return ans;
}

int TREES::maxPathSumHelper(TreeNode* root, int &ans){
    if(!root) return 0;

    int l = maxPathSumHelper(root->left, ans);
    int r = maxPathSumHelper(root->right, ans);
    
    l = max(l, 0); // filter out negative
    r = max(r, 0); // filter out negative

    ans = max(ans, root->val + l + r);
    return root->val + max(l, r);
}

