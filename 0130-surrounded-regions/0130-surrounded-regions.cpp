class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m=board.size();
        int n=board[0].size();
        vector<vector<int>>vis(m,vector<int>(n,0));
        int drow[]={0,-1,0,1};
        int dcol[]={-1,0,1,0};

        for(int i=0;i<m;i++){
            if(board[i][0]=='O') dfs(i,0,drow,dcol,board,vis);
            if(board[i][n-1]=='O') dfs(i,n-1,drow,dcol,board,vis);
        }
        for(int i=1;i<n-1;i++){
            if(board[0][i]=='O') dfs(0,i,drow,dcol,board,vis);
            if(board[m-1][i]=='O') dfs(m-1,i,drow,dcol,board,vis);
        }

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++)
                if(board[i][j]=='O' && vis[i][j]==0) board[i][j]='X';
        }
    }

    void dfs(int row,int col,int drow[],int dcol[],vector<vector<char>>& board,vector<vector<int>>& vis){
        vis[row][col]=1;
        for(int i=0;i<4;i++){
            int nrow=row+drow[i];
            int ncol=col+dcol[i];
            if(nrow>=0 && nrow<board.size() && ncol>=0 && ncol<board[0].size() && board[nrow][ncol]=='O' && vis[nrow][ncol]==0) dfs(nrow,ncol,drow,dcol,board,vis);
        }
    }
};