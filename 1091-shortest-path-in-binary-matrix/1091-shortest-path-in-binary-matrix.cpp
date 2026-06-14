class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        if(grid[0][0]==1 || grid[n-1][n-1]==1) return -1;
        // dis, {r,c}
        queue<pair<int,pair<int,int>>>q;
        q.push({1,{0,0}});
        vector<int>drow={-1,-1,0,1,1,1,0,-1};
        vector<int>dcol={0,1,1,1,0,-1,-1,-1};

        vector<vector<int>>dis(n,vector<int>(n,1e9));
        dis[0][0]=1;

        while(!q.empty()){
            int d=q.front().first;
            int r=q.front().second.first;
            int c=q.front().second.second;
            q.pop();
            if(r==n-1 && c==n-1) return d;

            for(int i=0;i<8;i++){
                int nr=r+drow[i];
                int nc=c+dcol[i];
                if(nr>=0 && nr<n && nc>=0 && nc<n && grid[nr][nc]==0 && d+1<dis[nr][nc]){
                    dis[nr][nc]=d+1;
                    q.push({d+1,{nr,nc}});
                }
            }
        }

        if(dis[n-1][n-1]==1e9) return -1;
        return dis[n-1][n-1];
    }
};