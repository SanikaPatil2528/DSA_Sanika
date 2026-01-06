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
    int maxLevelSum(TreeNode* root) {
        if(root==NULL) return -1;
        return levelOrder(root);
    }

    int levelOrder(TreeNode* root){
        queue<TreeNode*>q;
        int max_sum=INT_MIN;
        int ind=1;
        int level=1;
        q.push(root);
        while(!q.empty()){
            int sum=0;
            int size=q.size();
            while(size--){
                TreeNode* curr=q.front();
                q.pop();
                sum+=curr->val;
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
            }
            if(sum>max_sum){
                level=ind;
                max_sum=sum;
            }
            ind++;
        }

        return level;
    }
};