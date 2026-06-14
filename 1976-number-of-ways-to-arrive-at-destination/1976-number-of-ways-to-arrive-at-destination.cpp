const int MOD=1e9+7;
class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>>adj(n);
        for(auto road :roads){
            adj[road[0]].push_back({road[1],road[2]});
            adj[road[1]].push_back({road[0],road[2]});
        }

        // {dis,node}
        priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<>>pq;
        vector<long long>dis(n,1e18);
        vector<long long>ways(n,0);
        dis[0]=0;
        pq.push({0,0});
        ways[0]=1;

        while(!pq.empty()){
            auto [d,node]=pq.top();
            pq.pop();
            for(auto [v,t]:adj[node]){
                if(d+t<dis[v]) {
                    ways[v]=ways[node];
                    dis[v]=d+t;
                    pq.push({dis[v],v});
                }
                else if (d+1LL*t==dis[v]) ways[v]=(ways[v]+ways[node])%MOD;
            }
        }
        return ways[n-1];
    }
};