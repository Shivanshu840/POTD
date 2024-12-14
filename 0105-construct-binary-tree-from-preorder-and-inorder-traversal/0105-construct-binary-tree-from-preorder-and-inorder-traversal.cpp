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
    int findIndex(vector<int>& inorder,int val){

        for(int i = 0;i<inorder.size();i++){

            if(val==inorder[i]){
                return i;
            }
        }

        return -1;
    }

    TreeNode* constructTree(vector<int>& preorder, vector<int>& inorder, int &preIndex,int start,int end){

        if(preIndex>=preorder.size() || start>end){
            return nullptr;
        }

        int currVal = preorder[preIndex++];

        TreeNode* root = new TreeNode(currVal);
        int index = findIndex(inorder,currVal);
        root->left = constructTree(preorder,inorder,preIndex,start,index-1);
        root->right = constructTree(preorder,inorder,preIndex,index+1,end);

        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        int preIndex = 0;
        int inIndex = 0;
        int end = preorder.size()-1;


        return constructTree(preorder,inorder,preIndex,inIndex,end);
    }
};