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
    void inorder(vector<int>&sorted,TreeNode*root){
        if(!root) return;
        vector<int>left;
        inorder(left,root->left);
        vector<int>right;
        inorder(right,root->right);
        sorted.insert(sorted.end(),left.begin(),left.end());
        sorted.push_back(root->val);
        sorted.insert(sorted.end(),right.begin(),right.end());
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        if(root->left==NULL && root->right==NULL && k==1) return root->val;
        vector<int>sorted;
        inorder(sorted,root);
        return sorted[k-1];
    }
};