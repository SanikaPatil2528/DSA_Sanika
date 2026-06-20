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
        // vector<vector<int>>dp(m,vector<int>(n,-1));
        // int ans=helper(m-1,n-1,grid,dp);
        // return ans;

        // TABULATION
        // vector<vector<int>>dp(m,vector<int>(n));
        // dp[0][0]=grid[0][0];
        // for(int r=0;r<m;r++){
        //     for(int c=0;c<n;c++){
        //         if(r==0 && c==0) continue;

        //         int up=1e9,left=1e9;
        //         if(r>0) up=dp[r-1][c];
        //         if(c>0) left=dp[r][c-1];
        //         dp[r][c]=grid[r][c]+min(up,left);
        //     }
        // }
        // return dp[m-1][n-1];


        // SPACE OPTIMIZATION
        vector<int>dp(n,1e9);
        for(int r=0;r<m;r++){
            vector<int>curr(n,1e9);
            for(int c=0;c<n;c++){
                if(r==0 && c==0){
                    curr[c]=grid[0][0];
                    continue;
                } 
                int up=1e9,left=1e9;
                if(r>0) up=dp[c];
                if(c>0) left=curr[c-1];
                curr[c]=grid[r][c]+min(up,left);
            }
            dp=curr;
        }
        return dp[n-1];
    }
};