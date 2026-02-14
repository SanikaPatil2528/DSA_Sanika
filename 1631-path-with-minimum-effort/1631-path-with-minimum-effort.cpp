class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m=heights.size();
        int n=heights[0].size();
        vector<vector<int>>diff(m,vector<int>(n,1e9));
        diff[0][0]=0;

        // (dist, {row,col})
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>>pq;

        int drow[]={0,-1,0,1};
        int dcol[]={-1,0,1,0};
        pq.push({0, {0,0}});

        while(!pq.empty()){
            auto it=pq.top();
            pq.pop();
            int d=it.first;
            int r=it.second.first;
            int c=it.second.second;

            if (r==m-1 && c==n-1) return d;

            for(int i=0;i<4;i++){
                int newr=r+drow[i];
                int newc=c+dcol[i];
                if(newr>=0 && newr<m && newc>=0 && newc<n){
                    int effort=abs(heights[newr][newc]-heights[r][c]);
                    int newEffort=max(d,effort);
                    if (newEffort<diff[newr][newc]){
                        diff[newr][newc]=newEffort;
                        pq.push({diff[newr][newc],{newr,newc}});
                    } 
                }
            }
        }
        return diff[m-1][n-1];
    }
};