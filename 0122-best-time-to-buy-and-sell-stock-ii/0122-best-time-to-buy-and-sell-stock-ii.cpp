class Solution {
private:
    int helper(vector<int>&prices,int idx,int buy,vector<vector<int>>&dp){
        if (idx==prices.size()) return 0;
        // allowed to buy
        // buy, not buy
        if(buy) {
            if (dp[idx][1]!=-1) return dp[idx][1];
            else return dp[idx][1]=max(-prices[idx]+helper(prices,idx+1,0,dp) , 0+helper(prices,idx+1,1,dp) );
        }
        // not allowed
        // sell, not sell
        else{
            if (dp[idx][0]!=-1) return dp[idx][0];
            else return dp[idx][0]=max(prices[idx]+helper(prices,idx+1,1,dp) , 0+helper(prices,idx+1,0,dp) );
        }
    }
public:
    int maxProfit(vector<int>& prices) {
        vector<vector<int>>dp(prices.size(),vector<int>(2,-1));
        int ans=helper(prices,0,1,dp);
        return ans;
    }
};