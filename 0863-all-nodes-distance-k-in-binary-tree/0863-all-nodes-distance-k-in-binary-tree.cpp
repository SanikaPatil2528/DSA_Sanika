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
        unordered_map<TreeNode* ,TreeNode*> parent_track;
        mark_parents(root,parent_track);
        unordered_map<TreeNode* ,bool>visited;
        queue<TreeNode*>q;

        q.push(target);
        visited[target]=true;
        int distance=0;
        while(!q.empty()){
            if(distance++==k) break;

            int size=q.size();
            for(int i=0;i<size;i++){
                TreeNode* curr=q.front();
                q.pop();
                if(curr->left && visited[curr->left]==false){
                    visited[curr->left]=true;
                    q.push(curr->left);
                }
                if(curr->right && visited[curr->right]==false){
                    visited[curr->right]=true;
                    q.push(curr->right);
                }
                if(parent_track[curr] && visited[parent_track[curr]]==false){
                    q.push(parent_track[curr]);
                    visited[parent_track[curr]]=true;
                }
            }
        }
        vector<int>result;
        while(!q.empty()){
            TreeNode* curr=q.front();
            q.pop();
            result.push_back(curr->val);
        }
        return result;
    }


    void mark_parents(TreeNode* root,unordered_map<TreeNode*,TreeNode*>&parent_track){
        queue<TreeNode* >q;
        q.push(root);
        while(!q.empty()){
            TreeNode* curr=q.front();
            q.pop();
            if(curr->left){
                parent_track[curr->left]=curr;
                q.push(curr->left);
            }
            if(curr->right){
                parent_track[curr->right]=curr;
                q.push(curr->right);
            }
        }
    }
};