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
    void inorderTraversal(TreeNode*root, TreeNode*&prev,TreeNode*&first,TreeNode*&second,TreeNode*&third){
        if(!root) return;
        inorderTraversal(root->left,prev,first,second,third);

        if(prev!=nullptr && prev->val>root->val){
            if(!first){
                first=prev;
                second=root;
            }
            else{
                third=root;
            }
        }
        prev=root;

        inorderTraversal(root->right,prev,first,second,third);
    }
public:
    void recoverTree(TreeNode* root) {
        if(!root) return ;
        TreeNode* prev=nullptr,*first=nullptr,*second=nullptr,*third=nullptr;
        inorderTraversal(root,prev,first,second,third);

        if(!third) swap(first->val,second->val);
        else swap(first->val,third->val);
    }
};