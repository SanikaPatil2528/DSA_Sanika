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
    TreeNode* helper(TreeNode* &root){
        if(root->left==NULL) return root->right;
        if(root->right==NULL) return root->left;
        TreeNode* temp=root->left;
        while(temp->right) temp=temp->right;
        temp->right=root->right;
        return root->left;
    }
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) return NULL;
        if(root->val==key) return helper(root);
        TreeNode *curr=root;
        while(curr){
            if(curr->left && curr->left->val==key){
                curr->left=helper(curr->left);
                return root;
            }
            else if(curr->right && curr->right->val==key){
                curr->right=helper(curr->right);
                return root;
            }
            if(curr->val>key) curr=curr->left;
            else curr=curr->right;
        }
        return root;
    }
};