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
class BSTIterator {
private:
    stack<TreeNode*>st;
    bool isReverse;
    void pushNodes(TreeNode*&node){
        if(!node) return;
        TreeNode*curr=node;
        if(!isReverse){
            while(curr){
                st.push(curr);
                curr=curr->left;
            }
        }
        else{
            while(curr){
                st.push(curr);
                curr=curr->right;
            }
        }
    }
public:
    BSTIterator(TreeNode* root,bool Rev) {
        isReverse=Rev;
        pushNodes(root);
    }
    
    int next() {
        TreeNode* node=st.top();
        st.pop();
        if(isReverse) pushNodes(node->left);
        else pushNodes(node->right);
        return node->val;
    }
    
    bool hasNext() {
        return st.size()!=0; 
    }
};

class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        BSTIterator* left=new BSTIterator(root,false);
        BSTIterator* right=new BSTIterator(root,true);
        int i=left->next();
        int j=right->next();
        while(i<j){
            int sum=i+j;
            if(sum==k) return true;
            else if(sum<k){
                if(left->hasNext()) i=left->next();
                else return false;
            }
            else{
                if(right->hasNext()) j=right->next();
                else return false;
            }
        }
        return false;
    }
};