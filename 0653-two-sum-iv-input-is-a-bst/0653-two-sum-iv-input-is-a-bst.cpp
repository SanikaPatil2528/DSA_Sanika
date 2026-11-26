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
    void pushNodes(TreeNode* node){
        if(!node) return ;
        TreeNode*curr=node;
        while(curr){
            st.push(curr);
            if(!isReverse) curr=curr->left;
            else curr=curr->right;
        }
    }
public:
    BSTIterator(TreeNode* root,bool isRev) {
        isReverse=isRev;
        pushNodes(root);
    }
    
    int next() {
        TreeNode* node=st.top();
        st.pop();
        if(!isReverse) pushNodes(node->right);
        else pushNodes(node->left);
        return node->val;
    }
    
    bool hasNext() {
        return st.size();
    }
};
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if(!root) return false;
        BSTIterator *left=new BSTIterator(root,false);
        BSTIterator *right=new BSTIterator(root,true);
        int l=left->next();
        int r=right->next();
        
        while(l<r){
            int sumi=l+r;
            if(sumi==k) return true;
            if(sumi<k){
                if(left->hasNext()) l=left->next();
                else return false;
            }
            else{
                if(right->hasNext()) r=right->next();
                else return false;
            }
        }

        return false;
    }
};