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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root) return {};
        queue<TreeNode*>q;
        q.push(root);
        vector<vector<int>>ans;

        bool leftToRight=true;
        while(!q.empty()){
            int n=q.size();
            vector<int>level(n);
            int i=leftToRight?0:n-1;
            while(n--){
                TreeNode *t=q.front();
                q.pop();
                level[i]=t->val;
                i=leftToRight?i+1:i-1;
                if(t->left) q.push(t->left);
                if(t->right) q.push(t->right);
            }
            ans.push_back(level);
            leftToRight=!leftToRight;
        }

        return ans;
    }
};