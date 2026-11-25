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
private:
    void inorderTraversal(TreeNode* root,vector<int>&inorder,int &ans,int k){
        if(!root) return;
        inorderTraversal(root->left,inorder,ans,k);
        inorder.push_back(root->val);
        if(inorder.size()==k){
            ans=root->val;
            return;
        }
        inorderTraversal(root->right,inorder,ans,k);
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        vector<int>inorder;
        int ans=-1;
        inorderTraversal(root,inorder,ans,k);
        return ans;
    }
};