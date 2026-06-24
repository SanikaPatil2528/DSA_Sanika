class Solution {
private:
    int helper(int idx,int amt,vector<int>&coins,vector<vector<int>>&dp){
        if(idx==coins.size()){
            if(amt==0) return 1;
            return 0;
        }
        if(dp[idx][amt]!=-1) return dp[idx][amt];
        int pick=0;
        if(coins[idx]<=amt) pick=helper(idx,amt-coins[idx],coins,dp);
        int notPick=helper(idx+1,amt,coins,dp);
        return dp[idx][amt]=pick+notPick;
    }
public:
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        int ans=helper(0,amount,coins,dp);
        return ans;
    }
};