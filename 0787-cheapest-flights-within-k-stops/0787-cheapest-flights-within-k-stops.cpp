class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> adj(n);
        // node-> (to_node,cost)
        for (auto it:flights){
            adj[it[0]].push_back({it[1],it[2]});
        }

        vector<int>distance(n,1e9);
        // distance,(node,stops)
        queue<pair<int,pair<int,int>>> q;

        q.push({0,{src,0}});
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            int d=it.first;
            int node=it.second.first;
            int stops=it.second.second;
            if (stops > k) continue;

            for(auto neigh: adj[node]){
                if (distance[neigh.first]>d+neigh.second){
                    distance[neigh.first]=d+neigh.second;
                    q.push({distance[neigh.first],{neigh.first,stops+1}});
                }
            }
        }
        if (distance[dst]!=1e9) return distance[dst];
        return -1;
    }
};