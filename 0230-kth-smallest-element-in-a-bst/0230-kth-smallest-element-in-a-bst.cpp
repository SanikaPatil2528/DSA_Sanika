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
    int kthSmallest(TreeNode* root, int k) {
        if(root==NULL) return -1;

        vector<int>sorted;
        inorder(sorted,root);
        return sorted[k-1];
    }

    void inorder(vector<int>&sorted,TreeNode* root){
        if(root==NULL) return;

        inorder(sorted,root->left);
        sorted.push_back(root->val);
        inorder(sorted,root->right);
    }
};