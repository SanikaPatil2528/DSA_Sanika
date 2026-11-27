class Solution {
private:
    void dfs(int r,int c,vector<vector<int>>&vis,vector<vector<char>>&board,vector<int>&drow,vector<int>&dcol){
        vis[r][c]=1;
        int m=board.size(),n=board[0].size();
        for(int i=0;i<4;i++){
            int nr=r+drow[i];
            int nc=c+dcol[i];
            if(nr>=0 && nr<m && nc>=0 && nc<n && board[nr][nc]=='O' && !vis[nr][nc]) dfs(nr,nc,vis,board,drow,dcol);
        }
    }
public:
    void solve(vector<vector<char>>& board) {
        int m=board.size(),n=board[0].size();
        vector<vector<int>>vis(m,vector<int>(n,0));
        
        vector<int>dcol={-1,0,1,0};
        vector<int>drow={0,-1,0,1};
        for(int i=0;i<m;i++){
            if(board[i][0]=='O' && !vis[i][0]) dfs(i,0,vis,board,drow,dcol);
            if(board[i][n-1]=='O' && !vis[i][n-1]) dfs(i,n-1,vis,board,drow,dcol);
        }
        for(int j=1;j<=n-2;j++){
            if(board[0][j]=='O' && !vis[0][j]) dfs(0,j,vis,board,drow,dcol);
            if(board[m-1][j]=='O' && !vis[m-1][j]) dfs(m-1,j,vis,board,drow,dcol);
        }

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]=='O' && !vis[i][j]) board[i][j]='X';
            }
        }
    }
};