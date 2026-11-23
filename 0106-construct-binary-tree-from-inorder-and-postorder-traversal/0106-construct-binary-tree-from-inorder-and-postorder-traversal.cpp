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
    TreeNode* build(vector<int>& inorder, vector<int>& postorder, unordered_map<int,int>&inIdx, int inStart,int inEnd, int postStart, int postEnd){
        if(inEnd<inStart || postEnd<postStart) return nullptr;

        TreeNode* root=new TreeNode(postorder[postEnd]);
        int idx=inIdx[postorder[postEnd]];
        int leftSize=idx-inStart;

        root->left=build(inorder,postorder,inIdx,inStart,idx-1,postStart,postStart+leftSize-1);
        root->right=build(inorder,postorder,inIdx,idx+1,inEnd,postStart+leftSize,postEnd-1);

        return root;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int,int>inIdx;
        for(int i=0;i<inorder.size();i++) inIdx[inorder[i]]=i;

        TreeNode* root=build(inorder,postorder,inIdx,0,inorder.size()-1,0,postorder.size()-1);
        return root;
    }
};