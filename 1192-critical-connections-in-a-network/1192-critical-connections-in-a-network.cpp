class Solution{
private:
    int timer=1;
    void dfs(int node, int parent,vector<int> &vis, vector<vector<int>>&adj,vector<int> &tin, vector<int> &low, vector<vector<int>>&bridges){
        // we take parent also as argument bcoz in case where vis[it]!=0 we update curr node's low with adj it and in bridges we take low apart from parent so we need to check if parent or not
        
        vis[node]=1;
        tin[node]=timer;
        low[node]=timer;
        timer++;
        for(auto it:adj[node]){
            if(it==parent) continue;
            // not visited neighbor
            if(vis[it]==0){
                dfs(it,node,vis,adj,tin,low,bridges);
                low[node]=min(low[node],low[it]);
                // node -- it bridge?
                // backtracking from it to node
                if (low[it]>tin[node]) bridges.push_back({it,node});
            }
            else low[node]=min(low[node],low[it]);
        }
    }
public:
    vector<vector<int>> criticalConnections(int n,vector<vector<int>> & connections){
        vector<vector<int>> adj(n);
        for (auto it:connections){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<int> vis(n,0);
        vector<int> tin(n);
        vector<int> low(n);
        vector<vector<int>> bridges;
        dfs(0,-1,vis,adj,tin,low,bridges);
        return bridges;
    }
};