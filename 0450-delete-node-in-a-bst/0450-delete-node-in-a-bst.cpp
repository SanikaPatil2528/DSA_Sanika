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
    TreeNode* deletion(TreeNode*node){
        if(!node->right) return node->left;
        if(!node->left) return node->right;

        TreeNode* curr=node->left;
        while(curr->right) curr=curr->right;
        curr->right=node->right;

        return node->left;
    }
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) return nullptr;
        if(root->val==key) return deletion(root);
        TreeNode*curr=root;
        while(curr){
            if(curr->left && curr->left->val==key){
                curr->left=deletion(curr->left);
                return root;
            }
            if(curr->right && curr->right->val==key){
                curr->right=deletion(curr->right);
                return root;
            }
            if(curr->val<key) curr=curr->right;
            else curr=curr->left;
        }
        return root;
    }
};