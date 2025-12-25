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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        map<int,int>inmap;
        for(int i=0;i<inorder.size();i++)
            inmap[inorder[i]]=i;

        TreeNode* root=buildTree(inorder,0,inorder.size()-1,postorder,0,postorder.size()-1,inmap);

        return root;
    }

    TreeNode* buildTree(vector<int>&inorder, int inStart,int inEnd,vector<int>&postorder,int postStart,int postEnd,map<int,int>&inmap){
        if(inStart>inEnd|| postStart>postEnd) return NULL;

        TreeNode* root=new TreeNode(postorder[postEnd]);

        int inroot=inmap[root->val];
        int numsLeft=inroot-inStart;

        root->left=buildTree(inorder,inStart,inroot-1,postorder,postStart,postStart+numsLeft-1,inmap);
        root->right=buildTree(inorder,inroot+1,inEnd,postorder,postStart+numsLeft,postEnd-1,inmap);

        return root;
    }
};