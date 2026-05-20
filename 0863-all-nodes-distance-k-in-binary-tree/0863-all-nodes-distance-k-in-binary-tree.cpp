/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        if(root==nullptr) return {};
        unordered_map<TreeNode*,TreeNode*>parent;
        queue<TreeNode*>q;
        q.push(root);
        parent[root]=nullptr;
        while(!q.empty()){
            int s=q.size();
            while(s--){
                TreeNode*node=q.front();
                q.pop();
                if(node->left){
                    parent[node->left]=node;
                    q.push(node->left);
                }
                if(node->right){
                    parent[node->right]=node;
                    q.push(node->right);
                }
            }
        }

        unordered_map<TreeNode*,int>vis;
        q.push(target);
        int dis=0;
        vis[target]=1;
        vector<int>ans;
        while(!q.empty()){
            int size=q.size();
            if(dis==k){
                while(size--){
                    ans.push_back(q.front()->val);
                    q.pop();
                }
                return ans;
            }
            while(size--){
                TreeNode* node=q.front();
                q.pop();
                if(parent[node] && vis.find(parent[node])==vis.end()){
                    q.push(parent[node]);
                    vis[parent[node]]=1;
                }
                if(node->left && vis.find(node->left)==vis.end()){
                    q.push(node->left);
                    vis[node->left]=1;
                }
                if(node->right && vis.find(node->right)==vis.end()){
                    q.push(node->right);
                    vis[node->right]=1;
                }
            }
            dis++;
        }
        return {};
    }
};