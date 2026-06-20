class Solution {
private:
    int helper(int r,int c,vector<vector<int>>&grid,vector<vector<int>>&dp){
        if(r==0 && c==0) return grid[0][0];
        if(r<0 || c<0) return 1e9;
        if(dp[r][c]!=-1) return dp[r][c];

        int up=grid[r][c]+helper(r-1,c,grid,dp);
        int left=grid[r][c]+helper(r,c-1,grid,dp);
        return dp[r][c]=min(up,left);
    }
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>>dp(m,vector<int>(n,-1));
        int ans=helper(m-1,n-1,grid,dp);
        return ans;
    }
};