class Solution {
private:
    int dfs(int node,vector<vector<int>>&adj,vector<int>&vis,vector<bool>&hasApple){
        vis[node]=1;
        int time=0;
        for(int neigh:adj[node]){
            if(!vis[neigh]){
                int temp=dfs(neigh,adj,vis,hasApple);
                if(temp>0 || hasApple[neigh]) time+=(temp+2);
            }
        }
        return time;
    }
public:
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector<vector<int>>adj(n);
        for(auto edge:edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        vector<int>vis(n,0);
        int ans=dfs(0,adj,vis,hasApple);
        return ans;
    }
};