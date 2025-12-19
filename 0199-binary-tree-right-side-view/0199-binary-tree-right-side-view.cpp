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
    vector<int> rightSideView(TreeNode* root) {
        vector<int>ans;
        if (root==NULL) return ans;
        int level=0;
        reversePreorder(root,ans,level); // root,right,left

        return ans;
    }

    void reversePreorder(TreeNode* root,vector<int>& ans,int level){

        // if that level is visited first time i.e, node is first node from right in that level
        if(level==ans.size()) ans.push_back(root->val);

        if(root->right) reversePreorder(root->right,ans,level+1);
        if(root->left) reversePreorder(root->left,ans,level+1);
    }
};