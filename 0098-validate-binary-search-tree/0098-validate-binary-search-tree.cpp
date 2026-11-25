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
    bool validate(TreeNode*root,long long lower_bound,long long upper_bound){
        if(root->val<=lower_bound || root->val>=upper_bound) return false;
        bool l=true,r=true;
        if(root->left) l=validate(root->left,lower_bound,root->val);
        if(root->right) r=validate(root->right,root->val,upper_bound);
        return l&&r;
    }
public:
    bool isValidBST(TreeNode* root) {
        return validate(root,-1e18,1e18);
    }
};