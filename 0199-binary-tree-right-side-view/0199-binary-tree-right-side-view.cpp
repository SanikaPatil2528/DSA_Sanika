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
    void reversePreorder(TreeNode*root,vector<int>&ans,int level){
        if(root==nullptr) return ;
        if(ans.size()==level) ans.push_back(root->val);
        reversePreorder(root->right,ans,level+1);
        reversePreorder(root->left,ans,level+1);
    }
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int>ans;
        reversePreorder(root,ans,0);
        return ans;
    }
};