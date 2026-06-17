class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mini=prices[0];
        int maxProfit=0;
        int n=prices.size();
        int profit;
        for(int i=1;i<n;i++){
            if(prices[i]>mini){
                profit=prices[i]-mini;
                maxProfit=max(maxProfit,profit);
            }else{
                mini=min(mini,prices[i]);
            }
        }
        return maxProfit;
    }
};