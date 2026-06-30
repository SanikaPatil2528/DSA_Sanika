class Solution {
private:
    int helper(int idx,vector<int>&arr,int k,vector<int>&dp){
        if(idx==arr.size()) return 0;
        if(dp[idx]!=-1) return dp[idx];

        int maxi=-1e9;
        int l=0,maxEle=-1e9;
        int temp=min((int)arr.size(),idx+k);
        for(int j=idx;j<temp;j++){
            l++;
            maxEle=max(arr[j],maxEle);
            int sumi=l*maxEle + helper(j+1,arr,k,dp);
            maxi=max(maxi,sumi);
        }
        return dp[idx]=maxi;
    }
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        vector<int>dp(arr.size(),-1);
        int ans=helper(0,arr,k,dp);
        return ans;
    }
};