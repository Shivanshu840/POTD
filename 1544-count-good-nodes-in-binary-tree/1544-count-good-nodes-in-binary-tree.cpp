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
    void count(TreeNode*root, int currVal,int &countVal){

        if(root==nullptr) return;
       
        if(root->val>=currVal){
            countVal++;
            currVal = root->val;
        }
        count(root->left,currVal,countVal);
        count(root->right,currVal,countVal);
       
       
    }
    int goodNodes(TreeNode* root) {
        
        if(root==nullptr) return 0;
        int countVal = 0;
        int currVal = INT_MIN;
         count(root,root->val,countVal);
         return countVal;

       
    }
};