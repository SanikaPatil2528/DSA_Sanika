class Solution {
private:
    bool dfs(int r,int c,int idx,vector<vector<char>>&board,string word){
        if(idx==word.size()) return true;
        if(r<0 || r>=board.size() || c<0 || c>=board[0].size() || board[r][c]!=word[idx]) return false;

        // mark curr cell as visited
        char temp=board[r][c];
        board[r][c]='#';

        bool found= dfs(r-1,c,idx+1,board,word) || dfs(r,c+1,idx+1,board,word) || dfs(r+1,c,idx+1,board,word) || dfs(r,c-1,idx+1,board,word);

        board[r][c]=temp;
        return found;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m=board.size();
        int n=board[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(dfs(i,j,0,board,word)) return true;
            }
        }
        return false;
    }
};