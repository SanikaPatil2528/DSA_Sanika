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
    int pathSum(TreeNode*root,int &ans){
        if(!root) return 0;
        int l=pathSum(root->left,ans);
        l=max(0,l);
        int r=pathSum(root->right,ans);
        r=max(0,r);
        ans=max(ans,l+r+(root->val));
        return root->val+max(l,r);
    }
public:
    int maxPathSum(TreeNode* root) {
        int ans=INT_MIN;
        int pathSumi=pathSum(root,ans);
        return ans;
    }
};