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
        if(!root) return " ";
        string tree=to_string(root->val)+" ";
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            TreeNode* t=q.front();
            q.pop();

            if(t->left) {
                tree=tree+to_string(t->left->val);
                q.push(t->left);
            }
            else tree+="#";
            tree+=" ";

            if(t->right) {
                tree=tree+to_string(t->right->val);
                q.push(t->right);
            }
            else tree+="#";
            tree+=" ";
        }
        return tree;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data==" ") return nullptr;

        string value;
        stringstream ss(data);
        ss>>value;
        TreeNode* root= new TreeNode(stoi(value));

        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            TreeNode* t=q.front();
            q.pop();
            
            ss>>value;
            t->left= (value=="#")? nullptr: new TreeNode(stoi(value));
            ss>>value;
            t->right= (value=="#")? nullptr: new TreeNode(stoi(value));

            if(t->left) q.push(t->left);
            if(t->right) q.push(t->right);
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));