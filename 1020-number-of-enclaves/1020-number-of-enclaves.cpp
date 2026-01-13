class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>>vis(m,vector<int>(n,0));
        int drow[]={0,-1,0,1};
        int dcol[]={-1,0,1,0};

        for(int i=0;i<m;i++){
            if(grid[i][0]==1) dfs(i,0,drow,dcol,grid,vis);
            if(grid[i][n-1]==1) dfs(i,n-1,drow,dcol,grid,vis);
        }
        for(int i=1;i<n-1;i++){
            if(grid[0][i]==1) dfs(0,i,drow,dcol,grid,vis);
            if(grid[m-1][i]==1) dfs(m-1,i,drow,dcol,grid,vis);
        }

        int g1=0,v1=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1) g1++;
                if(vis[i][j]==1) v1++;
            }
        }

        return g1-v1;
    }

    void dfs(int row,int col,int drow[],int dcol[],vector<vector<int>>& board,vector<vector<int>>& vis){
        vis[row][col]=1;
        for(int i=0;i<4;i++){
            int nrow=row+drow[i];
            int ncol=col+dcol[i];
            if(nrow>=0 && nrow<board.size() && ncol>=0 && ncol<board[0].size() && board[nrow][ncol]==1 && vis[nrow][ncol]==0) dfs(nrow,ncol,drow,dcol,board,vis);
        }
    }
};