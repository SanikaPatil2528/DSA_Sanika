struct Node{
    Node *links[2];

    bool containsKey(int bit){
        return links[bit]!=NULL;
    }

    Node* get(int bit){
        return links[bit];
    }

    Node* put(int bit,Node* node){
        return links[bit]=node;
    }
};

class Trie{
private:
    Node* root;
public:
    Trie(){
        root=new Node();
    }

    void insert(int num){
        Node* curr=root;
        for(int i=31;i>=0;i--){
            int bit=(num>>i) & 1;
            if(!(curr->containsKey(bit))){
                curr->put(bit,new Node());
            }
            curr=curr->get(bit);
        }
    }

    int getMax(int num){
        Node *curr=root;
        int maxAns=0;
        for(int i=31;i>=0;i--){
            int bit=(num>>i)&1;
            if(curr->containsKey(!bit)){
                maxAns= maxAns | (1<<i);
                curr=curr->get(!bit);
            }
            else{
                curr=curr->get(bit);
            }
        }
        return maxAns;
    }
};

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int n=nums.size();
        Trie trie;
        for(int i=0;i<n;i++){
            trie.insert(nums[i]);
        }
        int maxi=0;
        for(int i=0;i<n;i++){
            int temp=trie.getMax(nums[i]);
            maxi=max(maxi,temp);
        }
        return maxi;
    }
};