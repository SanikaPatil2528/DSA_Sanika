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
    int getLeftHeight(TreeNode* root){
        int h=0;
        while(root){
            h++;
            root=root->left;
        }
        return h;
    }

    int getRightHeight(TreeNode* root){
        int h=0;
        while(root){
            h++;
            root=root->right;
        }
        return h;
    }
public:
    int countNodes(TreeNode* root) {
        if(!root) return 0;
        int lh=getLeftHeight(root);
        int rh=getRightHeight(root);

        if(lh==rh) return (1LL<<lh)-1;
        return 1+countNodes(root->left)+countNodes(root->right);
    }
};