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

class BSTIterator{
    stack<TreeNode*>myStack;
    // reverse -> true -> before
    // reverse -> false -> next
    bool reverse=true;

public:
    BSTIterator(TreeNode* root,bool isReverse){
        reverse=isReverse;
        pushAll(root);
    }

    bool hasNext(){
        return !myStack.empty();
    }

    int next(){
        TreeNode* temp=myStack.top();
        myStack.pop();
        if(reverse==false) pushAll(temp->right);
        else pushAll(temp->left);
        return temp->val;
    }

private:
    void pushAll(TreeNode* node){
        while(node){
            myStack.push(node);
            if(reverse==true) node=node->right;
            else node=node->left;
        }
    }
};

class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if(root==NULL) return false;

        // next -> smallest
        BSTIterator l(root,false);
        // before -> largest
        BSTIterator r(root,true);

        int i=l.next();
        int j=r.next();
        while(i<j){
            if(i+j==k) return true;
            else if(i+j<k) i=l.next();
            else j=r.next();
        }
        return false;
    }
};