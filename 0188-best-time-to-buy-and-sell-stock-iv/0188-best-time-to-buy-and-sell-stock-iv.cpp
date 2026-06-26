class Solution {
private:
    int helper(int idx,int canBuy,vector<int>&prices,vector<vector<vector<int>>>&dp,int k){
        if(idx==prices.size()) return 0;
        if(k==0) return 0;
        if(dp[idx][canBuy][k]!=-1) return dp[idx][canBuy][k];
        if(canBuy){
            // buy,not buy.... +sell -buy
            int buy=-1*prices[idx]+helper(idx+1,!canBuy,prices,dp,k);
            int notBuy=helper(idx+1,canBuy,prices,dp,k);
            return dp[idx][canBuy][k]=max(buy,notBuy);
        }
        else{
            // sell,not sell
            int sell=prices[idx]+helper(idx+1,!canBuy,prices,dp,k-1);
            int notSell=helper(idx+1,canBuy,prices,dp,k);
            return dp[idx][canBuy][k]=max(sell,notSell);
        }
    }
public:
    int maxProfit(int k, vector<int>& prices) {
        vector<vector<vector<int>>>dp(prices.size(),vector<vector<int>>(2,vector<int>(k+1,-1)));
        int ans=helper(0,1,prices,dp,k);
        return ans;
    }
};