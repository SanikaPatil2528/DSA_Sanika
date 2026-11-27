class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        int time=0;
        queue<pair<int,int>>q;
        
        int fresh=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==2) q.push({i,j});
                if(grid[i][j]==1) fresh++;
            }
        }

        int freshConverted=0;
        vector<int>drow={0,-1,0,1};
        vector<int>dcol={-1,0,1,0};
        while(!q.empty()){
            int s=q.size();
            bool converted=false;
            while(s--){
                auto node=q.front();
                int r=node.first,c=node.second;
                q.pop();
                for(int i=0;i<4;i++){
                    int nr=r+drow[i];
                    int nc=c+dcol[i];
                    if(nr>=0 && nr<m && nc>=0 && nc<n && grid[nr][nc]==1){
                        freshConverted++;
                        converted=true;
                        grid[nr][nc]=2;
                        q.push({nr,nc});
                    }
                }
            }
            if(converted) time++;
        }

        if(freshConverted<fresh) return -1;
        return time;
    }
};