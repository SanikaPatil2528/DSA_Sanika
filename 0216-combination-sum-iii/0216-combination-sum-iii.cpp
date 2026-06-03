class Solution {
private:
    void getCombi(int idx,int k,int n,vector<int>&curr,vector<vector<int>>&ans){
        if(curr.size()==k){
            if(n==0) ans.push_back(curr);
            return;
        }
        if(idx==9) return;

        // pick
        if(idx+1<=n){
            curr.push_back(idx+1);
            getCombi(idx+1,k,n-idx-1,curr,ans);
            curr.pop_back();
        }
        // not pick
        getCombi(idx+1,k,n,curr,ans);
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>>ans;
        vector<int>curr;
        getCombi(0,k,n,curr,ans);
        return ans;
    }
};