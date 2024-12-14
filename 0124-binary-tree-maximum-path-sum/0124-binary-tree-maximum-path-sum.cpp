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
    int maxSum;
    int solve(TreeNode* root){
        if(root==nullptr) return 0;

        int left = solve(root->left);
        int right = solve(root->right);

        int neche_hi_milgya_answer = left + right + root->val;
        int koi_ek_acha_hai = max(left,right) + root->val;
        int only_root_acha = root->val;

        maxSum = max({maxSum,only_root_acha,koi_ek_acha_hai,neche_hi_milgya_answer});

        return max(only_root_acha,koi_ek_acha_hai);
    }
    int maxPathSum(TreeNode* root) {

        maxSum = INT_MIN;
        solve(root);

        return maxSum;
        
    }
};