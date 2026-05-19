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
        if(!root) return 0;
        // {node,index}
        queue<pair<TreeNode*,long long>>q;
        int maxWidth=0;
        q.push({root,0});
        while(!q.empty()){
            int mini=q.front().second;
            int size=q.size();
            int first,last;
            for(int i=0;i<size;i++){
                auto [node,idx]=q.front();
                q.pop();
                int curr_idx=idx-mini;
                if(node->left) q.push({node->left,(long long)2*curr_idx+1});
                if(node->right) q.push({node->right,(long long)2*curr_idx+2});
                if(i==0) first=idx;
                if(i==size-1) last=idx;
            }
            maxWidth=max(maxWidth, last-first+1);
        }
        return maxWidth;
    }
};