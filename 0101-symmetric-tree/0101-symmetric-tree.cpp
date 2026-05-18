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
    bool checkSymmetry(TreeNode*t1,TreeNode*t2){
        if(t1==nullptr && t2==nullptr) return true;
        if(t1==nullptr || t2==nullptr) return false;
        return (t1->val==t2->val && checkSymmetry(t1->left,t2->right) && checkSymmetry(t1->right,t2->left));
    }
public:
    bool isSymmetric(TreeNode* root) {
        if(root==nullptr) return true;
        return checkSymmetry(root->left,root->right);
    }
};