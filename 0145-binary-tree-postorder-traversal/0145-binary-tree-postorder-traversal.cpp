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
    vector<int> postorder(TreeNode*&root){
        if(!root) return {};
        vector<int>left=postorder(root->left);
        vector<int>right=postorder(root->right);
        vector<int>res;
        res.insert(res.end(),left.begin(),left.end());
        res.insert(res.end(),right.begin(),right.end());
        res.push_back(root->val);
        return res;
    }
public:
    vector<int> postorderTraversal(TreeNode* root) {
        return postorder(root);
    }
};