class Solution {
private:
    void dfs(int r,int c,vector<vector<int>>&vis,vector<vector<char>>&grid,vector<int>&dcol,vector<int>&drow){
        vis[r][c]=1;
        int m=grid.size();
        int n=grid[0].size();
        for(int i=0;i<4;i++){
            int nr=r+drow[i];
            int nc=c+dcol[i];
            if(nr>=0 && nr<m && nc>=0 && nc<n && grid[nr][nc]=='1' && !vis[nr][nc]) dfs(nr,nc,vis,grid,dcol,drow);
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>>vis(m,vector<int>(n,0));
        
        vector<int>dcol={-1,0,1,0};
        vector<int>drow={0,-1,0,1};
        int comp=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='1' && !vis[i][j]) {
                    comp++;
                    dfs(i,j,vis,grid,dcol,drow);
                }
            }
        }

        return comp;
    }
};