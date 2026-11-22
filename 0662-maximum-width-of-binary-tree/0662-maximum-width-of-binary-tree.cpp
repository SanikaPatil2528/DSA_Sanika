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
using ll=long long;
public:
    int widthOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        ll width=0;
        // {node,index}
        queue<pair<TreeNode*,ll>>q;
        q.push({root,0});

        while(!q.empty()){
            int n=q.size();
            ll firstInd,lastInd;
            ll miniInd=q.front().second;
            for(int i=0;i<n;i++){
                TreeNode* t=q.front().first;
                ll ind=q.front().second;
                q.pop();

                ind-=miniInd;
                if(i==0) firstInd=ind;
                if(i==n-1) lastInd=ind;
                
                if(t->left) q.push({t->left,(ll)2*ind+1});
                if(t->right) q.push({t->right,(ll)2*ind+2});
            }
            width=max(width,lastInd-firstInd+1);
        }
        return width;
    }
};