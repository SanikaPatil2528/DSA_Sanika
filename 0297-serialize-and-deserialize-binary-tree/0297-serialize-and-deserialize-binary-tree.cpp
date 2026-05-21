/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root==NULL) return "";
        string s="";
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int size=q.size();
            while(size--){
                TreeNode*curr=q.front();
                q.pop();
                if(curr==NULL) s+="#";
                else s+=to_string(curr->val);
                s+=",";
                if(curr!=NULL){
                    q.push(curr->left);
                    q.push(curr->right);
                }
            }
        }
        cout<<s;
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data=="") return NULL;
        stringstream s(data);
        string str;
        getline(s,str,',');
        TreeNode*root=new TreeNode(stoi(str));
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            TreeNode *curr=q.front();
            q.pop();
            getline(s,str,',');
            curr->left=str=="#"?NULL:new TreeNode(stoi(str));
            if(curr->left) q.push(curr->left);
            getline(s,str,',');
            curr->right=str=="#"?NULL:new TreeNode(stoi(str));
            if(curr->right) q.push(curr->right);
        }

        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));