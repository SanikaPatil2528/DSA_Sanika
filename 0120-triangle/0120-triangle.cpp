class Solution {
private:
    int helper(int r,int c,vector<vector<int>>&triangle,vector<vector<int>>&dp){
        if(r==triangle.size()-1) return triangle[r][c];
        if(c>r) return 1e9;
        if(dp[r][c]!=1e9) return dp[r][c];
        int down=helper(r+1,c,triangle,dp);
        int downRight=helper(r+1,c+1,triangle,dp);
        return dp[r][c]=triangle[r][c]+min(down,downRight);
    }
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        // int m=triangle.size();
        // vector<vector<int>>dp(m,vector<int>(m,1e9));
        // int ans=helper(0,0,triangle,dp);
        // return ans;

        // TABULATION
        int m=triangle.size();
        vector<vector<int>>dp(m,vector<int>(m,0));
        for(int i=0;i<m;i++)
            dp[m-1][i]=triangle[m-1][i];
        for(int r=m-2;r>=0;r--){
            for(int c=r;c>=0;c--){
                int down=1e9,downRight=1e9;
                if(r+1<m) down=dp[r+1][c];
                if(r+1<m && c+1<m) downRight=dp[r+1][c+1];
                dp[r][c]=triangle[r][c]+min(down,downRight);
            }
        }
        return dp[0][0];
    }
};