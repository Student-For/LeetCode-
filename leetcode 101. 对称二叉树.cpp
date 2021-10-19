/*
    leetcode 101. 对称二叉树
    https://leetcode-cn.com/problems/symmetric-tree/
    简单题，递归判断一下，左子树的左边和右子树的右边，左子树的右边和右子树的左边。
*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        return check(root->left,root->right);
    }

    bool check(TreeNode* l,TreeNode* r){
        if(!l && !r) return true;
        if(!l || !r) return false;
        return l->val == r->val && check(l->left,r->right) && check(l->right,r->left);
    }
};