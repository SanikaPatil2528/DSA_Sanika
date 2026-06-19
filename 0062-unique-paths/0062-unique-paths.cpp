class Solution {
private:
    int helper(int r,int c,vector<vector<int>>&dp){
        if(r==0 && c==0) return 1;
        if(r<0 || c<0) return 0;
        if(dp[r][c]!=-1) return dp[r][c];

        int up=helper(r-1,c,dp);
        int left=helper(r,c-1,dp);
        return dp[r][c]=up+left;
    }
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m,vector<int>(n,-1));
        int ans=helper(m-1,n-1,dp);
        return ans;
    }
};