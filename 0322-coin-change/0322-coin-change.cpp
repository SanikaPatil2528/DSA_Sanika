class Solution {
private:
    int helper(vector<int>&coins,int idx,int target,vector<vector<int>>&dp){
        if (idx==0){
            if(target%coins[idx]==0) return target/coins[idx];
            return 1e9;
        }
        if(dp[idx][target]!=-1) return dp[idx][target];

        int notTake=0+helper(coins,idx-1,target,dp);
        int take=INT_MAX;
        if(target>=coins[idx]) take=1+helper(coins,idx,target-coins[idx],dp);
        return dp[idx][target]=min(take,notTake);
    }

public:
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>>dp(coins.size(),vector<int>(amount+1,-1));
        int ans=helper(coins,coins.size()-1,amount,dp);
        if(ans>=1e9) return -1;
        return ans;
    }
};