class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {

        // conversion to adj list just for ease
        int n=isConnected.size();
        vector<vector<int>> adj(n);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(isConnected[i][j]==1 && i!=j){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        int count=0;
        vector<int>vis(adj.size(),0);
        for(int i=0;i<adj.size();i++){
            if(vis[i]==0){
                dfs(i,adj,vis);
                count++;
            }
        }

        return count;
    }


    void dfs(int node,vector<vector<int>>&adj, vector<int>&vis)
    {
        vis[node]=1;
        for(auto it:adj[node]){
            if(vis[it]!=1) dfs(it,adj,vis);
        }
    }
};