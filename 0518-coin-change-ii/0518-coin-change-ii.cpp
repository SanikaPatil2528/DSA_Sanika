class Solution {
private:
    int helper(int target,vector<int>&coins,int idx,vector<vector<int>>&dp){
        if(dp[idx][target]!=-1) return dp[idx][target];
        if(target==0) return 1;
        if(idx==0){
            if(target%coins[idx]==0) return 1;
            return 0;
        }
        int notTake=helper(target,coins,idx-1,dp);
        int take=0;
        if(coins[idx]<=target) take=helper(target-coins[idx],coins,idx,dp);

        return dp[idx][target]=take+notTake;
    }
public:
    int change(int amount, vector<int>& coins) {
        vector<vector<int>>dp(coins.size(),vector<int>(amount+1,-1));
        int ans=helper(amount,coins,coins.size()-1,dp);

        return ans;
    }
};