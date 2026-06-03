class Solution {
private:
    void dfs(int r,int c,vector<vector<char>>&board,vector<vector<int>>&vis,vector<int>&drow,vector<int>&dcol){
        vis[r][c]=1;
        for(int i=0;i<4;i++){
            int nr=r+drow[i];
            int nc=c+dcol[i];
            if(nr>=0 && nr<board.size() && nc>=0 && nc<board[0].size() && board[nr][nc]=='O' && !vis[nr][nc]){
                dfs(nr,nc,board,vis,drow,dcol);
            }
        }
    }
public:
    void solve(vector<vector<char>>& board) {
        int m=board.size();
        int n=board[0].size();
        vector<vector<int>>vis(m,vector<int>(n,0));
        vector<int>drow={-1,0,1,0};
        vector<int>dcol={0,1,0,-1};
        
        // dfs for boundary O's
        for(int i=0;i<m;i++){
            if(board[i][0]=='O') dfs(i,0,board,vis,drow,dcol);
            if(board[i][n-1]=='O') dfs(i,n-1,board,vis,drow,dcol);
        }
        for(int i=1;i<n-1;i++){
            if(board[0][i]=='O') dfs(0,i,board,vis,drow,dcol);
            if(board[m-1][i]=='O') dfs(m-1,i,board,vis,drow,dcol);
        }

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++)
                if(vis[i][j]==0) board[i][j]='X';
        }
    }
};