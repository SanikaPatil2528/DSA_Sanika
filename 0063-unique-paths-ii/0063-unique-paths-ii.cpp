class Solution {
private:
    int helper(int i,int j,vector<vector<int>>&obstacleGrid,vector<vector<int>>&dp){
        if(obstacleGrid[i][j]==1) return 0;
        if(i==0 && j==0) return 1;
        if(i<0 || j<0) return 0;
        if(dp[i][j]!=-1) return dp[i][j];

        int left=0,up=0;
        if(i>0) up=helper(i-1,j,obstacleGrid,dp);
        if(j>0) left=helper(i,j-1,obstacleGrid,dp);
        return dp[i][j]=up+left;
    }
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        vector<vector<int>>dp(m,vector<int>(n,-1));
        int ans=helper(m-1,n-1,obstacleGrid,dp);
        return ans;
    }
};