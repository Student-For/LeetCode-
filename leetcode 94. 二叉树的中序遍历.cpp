/*
    leetcode 94. 二叉树的中序遍历
    二叉树的中序遍历可以用递归或者迭代
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
 //迭代
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        if(!root) return res;
        stack<TreeNode*> s;
        while(root || !s.empty()){
            while(root){
                s.push(root);
                root = root->left;
            }
            root = s.top();
            s.pop();
            res.push_back(root->val);
            root = root->right;
        }

        return res;
    } 
};
/*
递归
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        if(!root) return res;
        inorder(root,res);
        return res; 
    }
    void inorder(TreeNode* root , vector<int>& res){
        if(!root) return ;
        inorder(root->left,res);
        res.push_back(root->val);
        inorder(root->right,res);
    }
};
*/