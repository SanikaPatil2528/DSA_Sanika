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
        int m=triangle.size();
        vector<vector<int>>dp(m,vector<int>(m,1e9));
        int ans=helper(0,0,triangle,dp);
        return ans;
    }
};