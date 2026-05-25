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
    // sum,largest,smallest
    vector<int> postorder(TreeNode*root,int&maxi){
        vector<int>temp;
        // BST
        if(!root){
            temp.push_back(0);
            temp.push_back(INT_MIN);
            temp.push_back(INT_MAX);
            maxi=max(maxi,temp[0]);
            return temp;
        }

        vector<int>temp1=postorder(root->left,maxi);
        vector<int>temp2=postorder(root->right,maxi);

        // BST
        if(root->val>temp1[1] && root->val<temp2[2]){
            temp.push_back(root->val+temp1[0]+temp2[0]);
            temp.push_back(max({root->val,temp1[1],temp2[1]}));
            temp.push_back(min({root->val,temp1[2],temp2[2]}));
        } 
        // NOT BST
        else{
            temp.push_back(max(temp1[0],temp2[0]));
            temp.push_back(INT_MAX);
            temp.push_back(INT_MIN);
        }
        maxi=max(maxi,temp[0]);
        return temp;
    }
public:
    int maxSumBST(TreeNode* root) {
        vector<int>ans;
        int maxi=INT_MIN;
        ans=postorder(root,maxi);
        if(maxi<0) return 0;
        return maxi;
    }
};