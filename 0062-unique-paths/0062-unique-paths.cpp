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
        // vector<vector<int>>dp(m,vector<int>(n,-1));
        // int ans=helper(m-1,n-1,dp);
        // return ans;

        // TABULATION
        vector<vector<int>>dp(m,vector<int>(n,0));
        dp[0][0]=1;
        for(int r=0;r<m;r++){
            for(int c=0;c<n;c++){
                if(r==0 && c==0) continue;
                int up=0;
                if(r>0) up=dp[r-1][c];
                int left=0;
                if(c>0) left=dp[r][c-1];
                dp[r][c]=up+left;
            }
        }
        return dp[m-1][n-1];
        
        // SPACE OPTIMIZATION
        // vector<int>dp(n,0);
        // dp[0]=1;
        // for(int r=0;r<m;r++){
        //     vector<int>curr(n,0);
        //     for(int c=0;c<n;c++){
        //         if(r==0 && c==0) continue;
        //         int up=0;
        //         if(r>0) up=dp[r-1][c]dp);
        //         int left=0;
        //         if(c>0) left=helper(r,c-1,dp);
        //         dp[r][c]=up+left;
        //     }
        // }
        // return dp[m-1][n-1];
        
    }
};