class Solution {
private:
    int helper(int r,int c,vector<vector<int>>&dp,vector<vector<int>>& obstacleGrid){
        if(r<0 || c<0) return 0;
        if(obstacleGrid[r][c]==1) return 0;
        if(r==0 && c==0) return 1;
        if(dp[r][c]!=-1) return dp[r][c];

        int up=helper(r-1,c,dp,obstacleGrid);
        int left=helper(r,c-1,dp,obstacleGrid);
        return dp[r][c]=up+left;
    }
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        vector<vector<int>>dp(obstacleGrid.size(),vector<int>(obstacleGrid[0].size(),-1));
        int ans=helper(obstacleGrid.size()-1,obstacleGrid[0].size()-1,dp,obstacleGrid);
        return ans;
    }
};