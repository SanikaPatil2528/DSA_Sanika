class Solution {
private:
    void dfs(int node,int parent,int &curr_time,vector<vector<int>>&adj,vector<int>&vis,vector<int>&st,vector<int>&dt,vector<vector<int>>&bridges){
        vis[node]=1;
        st[node]=curr_time;
        dt[node]=curr_time;
        curr_time++;
        for(auto it:adj[node]){
            if(!vis[it]) dfs(it,node,curr_time,adj,vis,st,dt,bridges);
            if(it!=parent) dt[node]=min(dt[node],dt[it]);
            if(st[node]<dt[it]) bridges.push_back({node,it});
        }
    }
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>>adj(n);
        for(auto connection:connections){
            adj[connection[0]].push_back(connection[1]);
            adj[connection[1]].push_back(connection[0]);
        }
        vector<int>vis(n,0);
        vector<int>st(n); // start time
        vector<int>dt(n); // discovery time
        
        vector<vector<int>>bridges;
        int curr_time=1;
        for(int i=0;i<n;i++)
            if(!vis[i]) dfs(i,-1,curr_time,adj,vis,st,dt,bridges);
        return bridges;
    }
};