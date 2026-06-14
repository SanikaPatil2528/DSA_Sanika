class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m=heights.size();
        int n=heights[0].size();
        
        // {diff,{r,c}}
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        vector<vector<int>>dis(m,vector<int>(n,1e9));
        dis[0][0]=0;
        pq.push({0,{0,0}});
        vector<int>drow={-1,0,1,0};
        vector<int>dcol={0,1,0,-1};

        while(!pq.empty()){
            auto it=pq.top();
            pq.pop();
            int diff=it.first;
            int r=it.second.first;
            int c=it.second.second;
            if(r==m-1 && c==n-1) return diff;
            for(int i=0;i<4;i++){
                int nr=r+drow[i];
                int nc=c+dcol[i];
                if(nr>=0 && nr<m && nc>=0 && nc<n){
                    int newEffort=max(abs(heights[r][c]-heights[nr][nc]),diff);
                    if(newEffort<dis[nr][nc]){
                        dis[nr][nc]=newEffort;
                        pq.push({newEffort,{nr,nc}});
                    }
                }
            }
        }
        return -1;
    }
};