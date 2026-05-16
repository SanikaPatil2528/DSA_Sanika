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
        // node,v,level
        queue<pair<TreeNode*,pair<int,int>>>q;
        q.push({root,{0,0}});
        // v->{r->{]}}
        map<int,map<int,multiset<int>>>mpp;
        while(!q.empty()){
            auto [node,coords]=q.front();
            auto [v,level]=coords;
            q.pop();
            mpp[v][level].insert(node->val);
            if(node->left) q.push({node->left,{v-1,level+1}});
            if(node->right) q.push({node->right,{v+1,level+1}});
        }
        vector<vector<int>>ans;
        for(auto vertical:mpp){
            vector<int>temp;
            for(auto r:vertical.second){
                auto st=r.second;
                temp.insert(temp.end(),st.begin(),st.end());
            }
            ans.push_back(temp);
        }
        return ans;
    }
};