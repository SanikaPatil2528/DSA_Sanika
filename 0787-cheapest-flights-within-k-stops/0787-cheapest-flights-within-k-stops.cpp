class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>>adj(n);
        for(auto flight:flights){
            adj[flight[0]].push_back({flight[1],flight[2]});
        }
        // {stops,{node,dist}}
        queue<pair<int,pair<int,int>>>q;
        q.push({0,{src,0}});
        vector<int>dis(n,1e9);
        dis[src]=0;

        while(!q.empty()){
            auto it=q.front();
            q.pop();
            int stops=it.first;
            int node=it.second.first;
            int d=it.second.second;
            if(stops==k+1) continue;
            for(auto [v,cost]:adj[node]){
                if(d+cost<dis[v] && stops<=k){
                    dis[v]=d+cost;
                    q.push({stops+1,{v,dis[v]}});
                }
            }
        }

        int ans=dis[dst]==1e9?-1:dis[dst];
        return ans;
    }
};