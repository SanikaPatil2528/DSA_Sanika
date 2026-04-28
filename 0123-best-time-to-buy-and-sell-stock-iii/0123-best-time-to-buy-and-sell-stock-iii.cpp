class Solution {
private:
    int helper(vector<int>&prices,int idx,int buy,int cap,vector<vector<vector<int>>>&dp){
        if (cap==0) return 0;
        if (idx==prices.size()) return 0;
        // allowed to buy
        // buy, not buy
        if(buy) {
            if (dp[idx][1][cap]!=-1) return dp[idx][1][cap];
            else return dp[idx][1][cap]=max(-prices[idx]+helper(prices,idx+1,0,cap,dp) , 0+helper(prices,idx+1,1,cap,dp) );
        }
        // not allowed
        // sell, not sell
        else{
            if (dp[idx][0][cap]!=-1) return dp[idx][0][cap];
            else return dp[idx][0][cap]=max(prices[idx]+helper(prices,idx+1,1,cap-1,dp) , 0+helper(prices,idx+1,0,cap,dp) );
        }
    }
public:
    int maxProfit(vector<int>& prices) {
        vector<vector<vector<int>>>dp(prices.size(),vector<vector<int>>(2,vector<int>(3,-1)));
        int ans=helper(prices,0,1,2,dp);
        return ans;
    }
};