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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        
        if(p==nullptr && q==nullptr) return true;

        if(!p && q) return false;
        if(p && !q) return false;

        bool curr = p->val == q->val;
        bool left = isSameTree(p->left,q->left);
        bool right = isSameTree(p->right,q->right);

        return curr && left && right;

    
    }
};