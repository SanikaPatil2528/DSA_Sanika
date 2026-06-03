class Solution {
private:
    void dfs(int r,int c,vector<vector<int>>&grid,vector<vector<int>>&vis,vector<int>&drow,vector<int>&dcol){
        vis[r][c]=1;
        for(int i=0;i<4;i++){
            int nr=r+drow[i];
            int nc=c+dcol[i];
            if(nr>=0 && nr<grid.size() && nc>=0 && nc<grid[0].size() && !vis[nr][nc] && grid[nr][nc]==1){
                dfs(nr,nc,grid,vis,drow,dcol);
            }
        }
    }
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>>vis(m,vector<int>(n,0));
        vector<int>drow={-1,0,1,0};
        vector<int>dcol={0,1,0,-1};

        for(int i=0;i<m;i++){
            if(grid[i][0]==1) dfs(i,0,grid,vis,drow,dcol);
            if(grid[i][n-1]==1) dfs(i,n-1,grid,vis,drow,dcol);
        }
        for(int i=1;i<n-1;i++){
            if(grid[0][i]==1) dfs(0,i,grid,vis,drow,dcol);
            if(grid[m-1][i]==1) dfs(m-1,i,grid,vis,drow,dcol);
        }

        int cnt=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++)
                if(grid[i][j]==1 && vis[i][j]==0) cnt++;
        }

        return cnt;
    }
};