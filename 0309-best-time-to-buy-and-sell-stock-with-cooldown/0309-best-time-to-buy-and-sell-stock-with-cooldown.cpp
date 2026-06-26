class Solution {
private:
    int helper(int idx,int canBuy,vector<int>&prices,vector<vector<int>>&dp){
        if(idx>=prices.size()) return 0;
        if(dp[idx][canBuy]!=-1) return dp[idx][canBuy];
        if(canBuy){
            // buy,not buy.... +sell -buy
            int buy=-1*prices[idx]+helper(idx+1,!canBuy,prices,dp);
            int notBuy=helper(idx+1,canBuy,prices,dp);
            return dp[idx][canBuy]=max(buy,notBuy);
        }
        else{
            // sell,not sell
            int sell=prices[idx]+helper(idx+2,!canBuy,prices,dp);
            int notSell=helper(idx+1,canBuy,prices,dp);
            return dp[idx][canBuy]=max(sell,notSell);
        }
    }
public:
    int maxProfit(vector<int>& prices) {
        vector<vector<int>>dp(prices.size(),vector<int>(2,-1));
        int ans=helper(0,1,prices,dp);
        return ans;
    }
};