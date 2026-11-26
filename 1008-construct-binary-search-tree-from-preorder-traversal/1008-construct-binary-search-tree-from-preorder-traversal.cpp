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
    TreeNode* build(int &i,vector<int>&preorder,int ub){
        if(i>=preorder.size()) return nullptr;
        if(preorder[i]>ub
        ) return nullptr;

        TreeNode* node=new TreeNode(preorder[i]);
        i++;
        node->left=build(i,preorder,node->val);
        node->right=build(i,preorder,ub);

        return node;
    }
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i=0;
        return build(i,preorder,INT_MAX);
    }
};