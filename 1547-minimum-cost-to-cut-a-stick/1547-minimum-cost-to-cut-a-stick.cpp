class Solution {
private:
    int helper(int i,int j,vector<int>&cuts,vector<vector<int>>&dp){
        if(i>j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int mini=1e9;
        for(int idx=i;idx<=j;idx++){
            int cost=cuts[j+1]-cuts[i-1] + helper(i,idx-1,cuts,dp) + helper(idx+1,j,cuts,dp);
            mini=min(mini,cost);
        }
        return dp[i][j]=mini;
    }
public:
    int minCost(int n, vector<int>& cuts) {
        sort(cuts.begin(),cuts.end());
        int m=cuts.size();
        cuts.push_back(n);
        cuts.insert(cuts.begin(),0);
        vector<vector<int>>dp(m+1,vector<int>(m+1,-1));
        int ans=helper(1,m,cuts,dp);
        return ans;   
    }
};