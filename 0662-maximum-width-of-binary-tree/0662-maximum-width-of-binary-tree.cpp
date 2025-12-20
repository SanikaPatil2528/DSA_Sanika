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
    int widthOfBinaryTree(TreeNode* root) {
        if(root==NULL) return 0;
        int ans=0;
        
        // BFS (Level order) and normalizing the indices of nodes
        queue<pair<TreeNode*,long long>> nodes;
        nodes.push({root,0});

        while(!nodes.empty()){
            int min=nodes.front().second;
            int size=nodes.size();
            int first,last;
            for(int i=0;i<size;i++){
                TreeNode* curr_node=nodes.front().first;
                long long curr_index=nodes.front().second-min;
                nodes.pop();

                if(i==0) first=curr_index;
                if(i==size-1) last=curr_index;

                if(curr_node->left) nodes.push({curr_node->left,curr_index*2+1});
                if(curr_node->right) nodes.push({curr_node->right,curr_index*2+2});
                
            }
            ans=max(ans,last-first+1);

        }
        return ans;
    }
};