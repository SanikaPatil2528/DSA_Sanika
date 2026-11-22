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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        if(!root) return {};
        // col, row map
        map<int,map<int,multiset<int>>>mpp;
        // {node, {col,row}}
        queue<pair<TreeNode*,pair<int,int>>>q;
        q.push({root,{0,0}});

        while(!q.empty()){
            TreeNode* t=q.front().first;
            auto p=q.front().second;
            q.pop();
            int c=p.first;
            int r=p.second;
            mpp[c][r].insert(t->val);

            if(t->left) q.push({t->left,{c-1,r+1}});
            if(t->right) q.push({t->right,{c+1,r+1}});
        }

        vector<vector<int>>ans;
        for(auto p:mpp){
            vector<int>col;
            for(auto q:p.second){
                col.insert(col.end(),q.second.begin(),q.second.end());
            }
            ans.push_back(col);
        }

        return ans;
    }
};