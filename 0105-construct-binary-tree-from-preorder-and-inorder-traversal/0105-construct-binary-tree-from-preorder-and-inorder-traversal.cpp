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
    TreeNode* build(vector<int>& preorder, vector<int>& inorder,unordered_map<int,int>&inorderIdx,int preStart,int preEnd,int inStart,int inEnd){
        int n=preorder.size();
        if(preEnd<preStart || inEnd<inStart) return nullptr;

        TreeNode* root=new TreeNode(preorder[preStart]);
        int inIdx=inorderIdx[root->val];

        int leftSize=inIdx-inStart;
        root->left=build(preorder,inorder,inorderIdx,preStart+1,preStart+leftSize,inStart,inIdx-1);
        root->right=build(preorder,inorder,inorderIdx,preStart+leftSize+1,preEnd,inIdx+1,inEnd);

        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        // node->val,index for inorder
        unordered_map<int,int>inorderIdx;
        for(int i=0;i<inorder.size();i++) inorderIdx[inorder[i]]=i;

        TreeNode* root=build(preorder,inorder,inorderIdx,0,preorder.size()-1,0,inorder.size()-1);
        return root;
    }
};