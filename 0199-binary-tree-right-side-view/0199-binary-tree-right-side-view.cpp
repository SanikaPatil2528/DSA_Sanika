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
    void traversal(TreeNode* root,int level,vector<int>&ans){
        if(!root) return;
        if(ans.size()==level) ans.push_back(root->val);
        if(root->right) traversal(root->right,level+1,ans);
        if(root->left) traversal(root->left,level+1,ans);
    }
public:
    vector<int> rightSideView(TreeNode* root) {
        if(!root) return {};
        // root right left
        vector<int>ans;
        // node, level
        traversal(root,0,ans);
        return ans;
    }
};