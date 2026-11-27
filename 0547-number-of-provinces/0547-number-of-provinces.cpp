class Solution {
private:
    void dfs(int node,vector<int>&vis,vector<vector<int>>&adj){
        vis[node]=1;
        int n=adj.size();
        for(int i=0;i<n;i++){
            if(i!=node && adj[node][i] && !vis[i]) dfs(i,vis,adj);
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<int>vis(n,0);
        int comp=0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                comp++;
                dfs(i,vis,isConnected);
            }
        }
        return comp;
    }
};