class Solution {
int helper(int idx,int canBuy,vector<int>&prices,vector<vector<int>>&dp,int fee){
        if(idx==prices.size()) return 0;
        if(dp[idx][canBuy]!=-1) return dp[idx][canBuy];
        if(canBuy){
            // buy,not buy.... +sell -buy
            int buy=-fee-prices[idx]+helper(idx+1,!canBuy,prices,dp,fee);
            int notBuy=helper(idx+1,canBuy,prices,dp,fee);
            return dp[idx][canBuy]=max(buy,notBuy);
        }
        else{
            // sell,not sell
            int sell=prices[idx]+helper(idx+1,!canBuy,prices,dp,fee);
            int notSell=helper(idx+1,canBuy,prices,dp,fee);
            return dp[idx][canBuy]=max(sell,notSell);
        }
    }
public:
    int maxProfit(vector<int>& prices, int fee) {
        vector<vector<int>>dp(prices.size(),vector<int>(2,-1));
        int ans=helper(0,1,prices,dp,fee);
        return ans;
    }
};