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

        // vertical,level,multiset of node values (v,l,set)
        map<int,map<int,multiset<int>>> nodes;

        // BFS (Level order)
        // node ,v,l
        queue<pair<TreeNode*,pair<int,int>>> todo;
        todo.push({root,{0,0}});

        // Assigning each node the values of vertical & level (v,l) & adding them in map
        while(!todo.empty()){
            auto p=todo.front();
            todo.pop();
            TreeNode* node=p.first;
            int v=p.second.first;
            int l=p.second.second;
            nodes[v][l].insert(node->val);

            if (node->left) todo.push({node->left,{v-1,l+1}});
            if (node->right) todo.push({node->right,{v+1,l+1}});
        }


        vector<vector<int>> ans;
        for(auto p:nodes){
            vector<int>col;
            for(auto q: p.second){
                col.insert(col.end(),q.second.begin(),q.second.end());
            }
            ans.push_back(col);
        }

        return ans;
    }
};