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
    TreeNode* solve(TreeNode* root){
        if(root==nullptr){
            return nullptr;
        }

        TreeNode* newRoot = new TreeNode(root->val);
        newRoot->left = solve(root->right);
        newRoot->right = solve(root->left);

        return newRoot;
    }

    TreeNode* invertTree(TreeNode* root) {
        if(root==NULL || (root->left==NULL && root->right==NULL))return root;
        TreeNode* root1 = solve(root);
        return root1;
       
        
    }
};