class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        int drow[]={0,-1,-1,-1,0,1,1,1};
        int dcol[]={-1,-1,0,1,1,1,0,-1};

        if(grid[0][0]==1) return -1;
        if(grid[n-1][n-1]==1) return -1;

        vector<vector<int>>distance(n,vector<int>(n,1e9));
        distance[0][0]=1;
        
        // (dist,{row,col})
        queue<pair<int,pair<int,int>>> q;
        q.push({1,{0,0}});

        while(!q.empty()){
            auto it=q.front();
            q.pop();
            int dist=it.first;
            int row=it.second.first;
            int col=it.second.second;

            for(int i=0;i<8;i++){
                int newr=row+drow[i];
                int newc=col+dcol[i];
                if(newr>=0 && newr<n && newc>=0 && newc<n && grid[newr][newc]==0 && dist+1 < distance[newr][newc]){
                    distance[newr][newc]=dist+1;
                    q.push({distance[newr][newc],{newr,newc}});
                }
            }
        }

        if (distance[n-1][n-1]<1e9) return distance[n-1][n-1];
        return -1;
    }
};