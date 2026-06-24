class Solution {
private:
    int helper(int idx,int amt,vector<int>&coins,vector<vector<int>>&dp){
        if(idx==coins.size()){
            if(amt==0) return 0;
            return 1e9;
        }
        if(dp[idx][amt]!=-1) return dp[idx][amt];

        int pick=1e9;
        if(coins[idx]<=amt) pick=1+helper(idx,amt-coins[idx],coins,dp);
        int notPick=0+helper(idx+1,amt,coins,dp);
        return dp[idx][amt]=min(pick,notPick);
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>>dp(coins.size(),vector<int>(amount+1,-1));
        int ans=helper(0,amount,coins,dp);
        if(ans==1e9) return -1;
        return ans;
    }
};