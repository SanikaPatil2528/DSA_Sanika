class Solution {
private:
    void dfs(int node,vector<vector<int>>&adj,vector<int>&vis){
        vis[node]=1;
        for(int neigh:adj[node]){
            if(!vis[neigh]) dfs(neigh,adj,vis);
        }
    }
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<vector<int>>adj(n);
        for(auto invo:invocations){
            adj[invo[0]].push_back(invo[1]);
        }
        vector<int>vis(n,0);
        dfs(k,adj,vis);
        vector<int>ans;
        for(auto invo:invocations){
            if(!vis[invo[0]] && vis[invo[1]]){
                for(int i=0;i<n;i++) ans.push_back(i);
                return ans;
            }
        }
        for(int i=0;i<n;i++){
            if(!vis[i]) ans.push_back(i);
        }
        return ans;
    }
};