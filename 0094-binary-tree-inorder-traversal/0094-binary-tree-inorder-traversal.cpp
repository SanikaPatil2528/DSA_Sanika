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
    vector<int> inorder(TreeNode*&root){
        if(!root) return {};
        vector<int>left=inorder(root->left);
        vector<int>right=inorder(root->right);
        vector<int>res;
        res.insert(res.end(),left.begin(),left.end());
        res.push_back(root->val);
        res.insert(res.end(),right.begin(),right.end());
        return res;
    }
public:
    vector<int> inorderTraversal(TreeNode* root) {
        return inorder(root);
    }
};