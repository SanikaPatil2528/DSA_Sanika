class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();
        vector<vector<int>>ans=mat;
        bfs(ans,mat,m,n);
        return ans;
    }

    void bfs(vector<vector<int>>&ans,vector<vector<int>>&mat,int m,int n){
        int drow[]={0,-1,0,1};
        int dcol[]={-1,0,1,0};
        queue<pair<pair<int,int>,int>>q;
        vector<vector<int>>vis(m,vector<int>(n,0));

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(ans[i][j]==0)
                {
                    q.push({{i,j},0});
                    vis[i][j]=1;
                } 
            }
        }

        while(!q.empty()){
            int row=q.front().first.first;
            int col=q.front().first.second;
            int distance=q.front().second;
            q.pop();
            ans[row][col]=distance;
            for(int a=0;a<4;a++){
                int nrow=row+drow[a];
                int ncol=col+dcol[a];
                if(nrow>=0 && nrow<m && ncol>=0 && ncol<n && vis[nrow][ncol]!=1){
                    q.push({{nrow,ncol},distance+1});
                    vis[nrow][ncol]=1;
                }
            }
        }
    }
};