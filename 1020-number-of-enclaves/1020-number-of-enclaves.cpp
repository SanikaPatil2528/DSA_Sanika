class Solution {
private:  
    void dfs(int r,int c,vector<int>&drow,vector<int>&dcol,vector<vector<int>>&vis,vector<vector<int>>&grid){
        int m=grid.size(),n=grid[0].size();
        vis[r][c]=1;
        for(int i=0;i<4;i++){
            int nr=r+drow[i];
            int nc=c+dcol[i];
            if(nr>=0 && nr<m && nc>=0 && nc<n && grid[nr][nc] && !vis[nr][nc]) dfs(nr,nc,drow,dcol,vis,grid);
        }
    }
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        vector<vector<int>>vis(m,vector<int>(n,0));
        vector<int>drow={0,-1,0,1};
        vector<int>dcol={-1,0,1,0};
        for(int i=0;i<m;i++){
            if(grid[i][0]==1 && !vis[i][0]) dfs(i,0,drow,dcol,vis,grid);
            if(grid[i][n-1]==1 && !vis[i][n-1]) dfs(i,n-1,drow,dcol,vis,grid);
        }
        for(int j=1;j<=n-2;j++){
            if(grid[0][j]==1 && !vis[0][j]) dfs(0,j,drow,dcol,vis,grid);
            if(grid[m-1][j]==1 && !vis[m-1][j]) dfs(m-1,j,drow,dcol,vis,grid);
        }
        int ans=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] && !vis[i][j]) ans++;
            }
        }
        return ans;
    }
};