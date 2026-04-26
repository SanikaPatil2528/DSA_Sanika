class Solution {
private:
    bool dfs(int i,int j,int pi,int pj, vector<vector<char>>&grid,vector<vector<int>>&vis){
        vis[i][j]=1;
        int dirs[4][2]={
            {-1,0},
            {0,1},
            {1,0},
            {0,-1}
        };
        int m=grid.size();
        int n=grid[0].size();
        for(auto &d:dirs){
            int ni=i+d[0];
            int nj=j+d[1];
            if(ni>=0 && ni<m && nj>=0 && nj<n && grid[ni][nj]==grid[i][j]){
                if(!vis[ni][nj]){
                    if (dfs(ni,nj,i,j,grid,vis)) return true;
                }
                else if (ni!=pi || nj!=pj) return true;
            }
        }
        return false;
    }
public:
    bool containsCycle(vector<vector<char>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>>vis(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!vis[i][j]){
                    if (dfs(i,j,-1,-1,grid,vis)) return true;
                }
            }
        }
        return false;
    }
};