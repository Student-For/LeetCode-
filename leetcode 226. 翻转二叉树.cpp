/*
    leetcode 226. 翻转二叉树
    https://leetcode-cn.com/problems/invert-binary-tree/
    简单题
    递归解决
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
    void change(TreeNode* root,TreeNode* l ,TreeNode* r){
        if(!l && !r) return ;
        root->left = r;
        root->right = l;
    }
    TreeNode* invertTree(TreeNode* root) {
        if(root) change(root,root->left,root->right);
        if(root)invertTree(root->left);
        if(root)invertTree(root->right);
        return root;
    }
};