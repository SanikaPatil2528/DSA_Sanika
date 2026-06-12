class Solution {
private:
    void bfs(int i,int j,vector<vector<char>>&grid,vector<vector<int>>&vis){
        queue<pair<int,int>>q;
        q.push({i,j});
        vector<int>drow={-1,0,1,0};
        vector<int>dcol={0,1,0,-1};

        while(!q.empty()){
            auto [r,c]=q.front();
            q.pop();
            for(int i=0;i<4;i++){
                int nr=r+drow[i];
                int nc=c+dcol[i];
                if(nr>=0 && nr<grid.size() && nc>=0 && nc<grid[0].size() && grid[nr][nc]=='1' && !vis[nr][nc]){
                    vis[nr][nc]=1;
                    q.push({nr,nc});
                }
            }
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        vector<vector<int>>vis(grid.size(),vector<int>(grid[0].size(),0));
        int cnt=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]=='1' && !vis[i][j]){
                    cnt++;
                    vis[i][j]=1;
                    bfs(i,j,grid,vis);
                }
            }
        }
        return cnt;
    }
};