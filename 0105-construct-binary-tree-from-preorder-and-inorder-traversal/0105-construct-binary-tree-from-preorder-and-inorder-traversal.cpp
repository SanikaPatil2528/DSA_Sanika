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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int,int>inmap;
        for(int i=0;i<inorder.size();i++)
            inmap[inorder[i]]=i;

        TreeNode* root= buildTree(0,preorder.size()-1,preorder,0,inorder.size()-1,inorder,inmap);
        
        return root;
    }

    TreeNode* buildTree(int preStart,int preEnd,vector<int>&preorder,int inStart,int inEnd,vector<int>&inorder,map<int,int>&inmap){
        if(preStart>preEnd || inStart>inEnd) return NULL;

        TreeNode* root=new TreeNode(preorder[preStart]);
        int inroot=inmap[root->val];
        int numsLeft=inroot-inStart;

        root->left=buildTree(preStart+1,preStart+numsLeft,preorder,inStart,inroot-1,inorder,inmap);
        root->right=buildTree(preStart+numsLeft+1,preEnd,preorder,inroot+1,inEnd,inorder,inmap);

        return root;
    }
};