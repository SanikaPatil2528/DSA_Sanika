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
    void recoverTree(TreeNode* root) {
        vector<TreeNode*>in=inorder(root);
        TreeNode* first=NULL;
        TreeNode* second=NULL;
        TreeNode* third=NULL;

        int i=0;
        TreeNode* prev=NULL;
        TreeNode* curr=NULL;
        while(i<in.size()-1){
            prev=in[i];
            curr=in[i+1];
            if(prev->val>curr->val){
                if(first==NULL) first=prev;
                if(second==NULL) second=curr;
                else third=curr;
            }
            i++;
        }
        int temp=first->val;
        if(third==NULL) {
            first->val=second->val;
            second->val=temp;
        }
        else{
            first->val=third->val;
            third->val=temp;
        }
    }

    vector<TreeNode* > inorder(TreeNode* root){
        if(root==NULL) return{};

        vector<TreeNode*>left=inorder(root->left);
        vector<TreeNode*>right=inorder(root->right);

        vector<TreeNode*>ans;
        ans.insert(ans.end(),left.begin(),left.end());
        ans.push_back(root);
        ans.insert(ans.end(),right.begin(),right.end());

        return ans;
    }
};