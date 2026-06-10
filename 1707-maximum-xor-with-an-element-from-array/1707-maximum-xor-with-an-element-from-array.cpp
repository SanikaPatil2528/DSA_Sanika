struct Node{
    Node* links[2];

    bool containsKey(int bit){
        return links[bit]!=NULL;
    }

    void put(int bit,Node* node){
        links[bit]=node;
    }

    Node* get(int bit){
        return links[bit];
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
        Node* curr=root;
        int maxAns=0;
        for(int i=31;i>=0;i--){
            int bit=(num>>i) & 1;
            if(curr->containsKey(!bit)){
                maxAns= maxAns | (1<<i);
                curr=curr->get(!bit);
            }
            else curr=curr->get(bit);
        }
        return maxAns;
    }
};

class Solution {
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        int n=queries.size();
        vector<int>ans(n);
        vector<pair<pair<int,int>,int>>oQ;
        for(int i=0;i<n;i++){
            // {{mi,xi},i}
            oQ.push_back({{queries[i][1],queries[i][0]},i});
        }
        sort(oQ.begin(),oQ.end());
        sort(nums.begin(),nums.end());
        Trie trie;
        
        int idx=0;
        for(int i=0;i<n;i++){
            int mi=oQ[i].first.first;
            int xi=oQ[i].first.second;
            int pos=oQ[i].second;
            while(idx<nums.size() && nums[idx]<=mi){
                trie.insert(nums[idx]);
                idx++;
            }
            if (idx==0) ans[pos]=-1;
            else{
                int temp=trie.getMax(xi);
                ans[pos]=temp;
            }
        }
        return ans;
    }
};