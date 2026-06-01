class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>>vis(m,vector<int>(n,0));
        // {r,c},time
        queue<pair<pair<int,int>,int>>q;
        int cnt1=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==2){
                    vis[i][j]=2;
                    q.push({{i,j},0});
                }
                else if(grid[i][j]==1) {
                    cnt1++;
                    vis[i][j]=1;
                }
            }
        }
        int drow[]={0,-1,0,1};
        int dcol[]={-1,0,1,0};
        int time=0;
        int check=0;
        while(!q.empty()){
            int r=q.front().first.first;
            int c=q.front().first.second;
            int t=q.front().second;
            q.pop();
            time=max(t,time);
            for(int i=0;i<4;i++){
                int nr=r+drow[i];
                int nc=c+dcol[i];
                if(nr>=0 && nr<m && nc>=0 && nc<n && vis[nr][nc]==1){
                    vis[nr][nc]=2;
                    check++;
                    q.push({{nr,nc},t+1});
                }
            }
        }
        if(cnt1==check) return time;
        return -1;
    }
};