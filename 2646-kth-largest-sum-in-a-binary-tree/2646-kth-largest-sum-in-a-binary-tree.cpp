/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    long long kthLargestLevelSum(TreeNode* root, int k) {

        if(!root) return -1;

        vector<long long> ans;
        queue<TreeNode*> q;

        q.push(root);
        q.push(NULL);
        long long sum = 0;


        while(!q.empty()){

            TreeNode* frontNode = q.front();
            q.pop();


            if (frontNode==NULL) {
                
                ans.push_back(sum);
                sum = 0;
                if (!q.empty()) {
                    q.push(NULL);
                }
            }else{
            cout<<frontNode->val<<" ";
            sum = sum +  frontNode->val;

            if (frontNode->left)
                q.push(frontNode->left);
            if (frontNode->right)
                q.push(frontNode->right);
            }
        }

        sort(ans.begin(),ans.end());

        if(ans.size()<k) return -1;

        return ans[ans.size()-k];

       
    }
};