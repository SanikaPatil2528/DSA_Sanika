class Solution {
private:
    int helper(int i,int j,vector<vector<int>> &dp){
        if(i==0 && j==0) return 1;
        if(i<0 || j<0) return 0;
        if(dp[i][j]!=-1) return dp[i][j];

        int up=0,left=0;
        if(i>0) up=helper(i-1,j,dp);
        if(j>0) left=helper(i,j-1,dp);
        return dp[i][j]=up+left;
    }
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m,vector<int>(n,-1));
        int ans=helper(m-1,n-1,dp);
        return ans;
    }
};