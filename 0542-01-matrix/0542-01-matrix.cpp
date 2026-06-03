class Solution {
private:
    void bfs(vector<vector<int>>&ans,vector<vector<int>>&mat){
        int m=mat.size();
        int n=mat[0].size();
        vector<vector<int>>vis(m,vector<int>(n,0));
        // {{r,c},dis};
        queue<pair<pair<int,int>,int>>q;
        vector<int>drow={-1,0,1,0};
        vector<int>dcol={0,1,0,-1};

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]==0){
                    vis[i][j]=1;
                    q.push({{i,j},0});
                }
            }
        }

        while(!q.empty()){
            int r=q.front().first.first;
            int c=q.front().first.second;
            int d=q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int nr=r+drow[i];
                int nc=c+dcol[i];
                if(nr>=0 && nr<m && nc>=0 && nc<n && !vis[nr][nc] && mat[nr][nc]==1){
                    vis[nr][nc]=1;
                    ans[nr][nc]=d+1;
                    q.push({{nr,nc},d+1});
                }
            }
        }
    }
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        vector<vector<int>>ans=mat;
        bfs(ans,mat);
        return ans;
    }
};