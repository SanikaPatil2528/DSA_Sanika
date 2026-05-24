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
    TreeNode* build(vector<int>&preorder,int start,int end){
        if(start>end) return NULL;
        TreeNode* node=new TreeNode(preorder[start]);
        int i;
        for(i=start+1;i<=end;i++){
            if(node->val<preorder[i]) break;
        }
        node->left=build(preorder,start+1,i-1);
        node->right=build(preorder,i,end);
        return node;
    }
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int n=preorder.size();
        if(n==0) return NULL;
        TreeNode* root=build(preorder,0,n-1);
        return root;
    }
};