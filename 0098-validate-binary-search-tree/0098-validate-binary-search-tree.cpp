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
    bool isValidBST(TreeNode* root) {
        return checkBST(root,LLONG_MIN,LLONG_MAX);
    }

    bool checkBST(TreeNode* root, long long lower,long long higher){
        if(root==NULL) return true;

        if(root->val<=lower || root->val>=higher) return false;
        return (checkBST(root->left,lower,root->val) && checkBST(root->right,root->val,higher));
    }
};