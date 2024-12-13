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
    int height(TreeNode*root){

        if(root==nullptr) return 0;

        int left = height(root->left);
        int right = height(root->right);

        return max(left,right) + 1;
    }
    int diameterOfBinaryTree(TreeNode* root) {

        if(root==nullptr) return 0;

        int leftSub = diameterOfBinaryTree(root->left);
        int rightSub = diameterOfBinaryTree(root->right);

        int curr = height(root->left) + height(root->right);

        return max(curr,max(leftSub,rightSub));
        
    }
};