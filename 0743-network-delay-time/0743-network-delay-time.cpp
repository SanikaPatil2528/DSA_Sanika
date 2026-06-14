class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>>adj(n+1);
        for(auto time:times){
            adj[time[0]].push_back({time[1],time[2]});
        }
        vector<int>dis(n+1,1e9);
        dis[k]=0;
        // dis,node
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>>pq;
        pq.push({0,k});

        while(!pq.empty()){
            auto [d,node]=pq.top();
            pq.pop();
            for(auto [v,wt]:adj[node]){
                if(d+wt<dis[v]){
                    dis[v]=d+wt;
                    pq.push({dis[v],v});
                }
            }
        }

        int maxi=-1e9;
        for(int i=1;i<=n;i++){
            if(dis[i]==1e9) return -1;
            maxi=max(maxi,dis[i]);
        }
        return maxi;
    }
};