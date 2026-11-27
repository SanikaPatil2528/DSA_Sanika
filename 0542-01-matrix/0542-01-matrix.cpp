class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m=mat.size(),n=mat[0].size();
        vector<vector<int>>dis(m,vector<int>(n,-1));
        // {{i,j},d}
        queue<pair<pair<int,int>,int>>q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]==0) {
                    q.push({{i,j},0});
                    dis[i][j]=0;
                }
            }
        }

        vector<int>drow={0,-1,0,1};
        vector<int>dcol={-1,0,1,0};
        while(!q.empty()){
            auto nd=q.front();
            q.pop();
            int r=nd.first.first;
            int c=nd.first.second;
            int d=nd.second;
            for(int i=0;i<4;i++){
                int nr=r+drow[i];
                int nc=c+dcol[i];
                if(nr>=0 && nr<m && nc>=0 && nc<n && dis[nr][nc]==-1){
                    dis[nr][nc]=d+1;
                    q.push({{nr,nc},d+1});
                }
            }
        }
        return dis;
    }
};