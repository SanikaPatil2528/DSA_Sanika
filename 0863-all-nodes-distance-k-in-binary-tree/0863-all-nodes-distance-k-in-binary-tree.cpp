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
        // child, parent
        unordered_map<TreeNode*,TreeNode*>parent;
        parent[root]=nullptr;

        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            TreeNode* t=q.front();
            q.pop();
            if(t->left){
                parent[t->left]=t;
                q.push(t->left);
            }
            if(t->right){
                parent[t->right]=t;
                q.push(t->right);
            }
        }

        queue<pair<TreeNode*,int>>qq;
        qq.push({target,0});
        vector<int>ans;
        unordered_set<TreeNode*>visited;
        while(!qq.empty()){
            TreeNode* t=qq.front().first;
            int d=qq.front().second;
            qq.pop();
            if(d==k){
                ans.push_back(t->val);
                continue;
            }
            if(t->left && t->left!=target && !visited.count(t->left)) {
                qq.push({t->left,d+1});
                visited.insert(t->left);
            }
            if(t->right && t->right!=target && !visited.count(t->right)){
                qq.push({t->right,d+1});
                visited.insert(t->right);
            }
            if(parent[t] && parent[t]!=target && !visited.count(parent[t])){
                qq.push({parent[t],d+1});
                visited.insert(parent[t]);
            } 
        }
        return ans;
    }
};