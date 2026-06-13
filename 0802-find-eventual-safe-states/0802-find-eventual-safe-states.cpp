class Solution {
private:
    bool dfsCheck(int node,vector<vector<int>>&graph,vector<int>&vis,vector<int>&pathVis,vector<int>&check){
        vis[node]=1;
        pathVis[node]=1;
        for(auto it:graph[node]){
            if(!vis[it]){
                if(dfsCheck(it,graph,vis,pathVis,check)==true) return true;
            }
            else if(pathVis[it]){
                return true;
            }
        }
        check[node]=1; // if there had been a cycle ,vo pehle hi upar break hoke true return kr deta
        pathVis[node]=0;
        return false;
    }
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();

        vector<int>vis(n,0);
        vector<int>pathVis(n,0);
        vector<int>ans;
        vector<int>check(n,0);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfsCheck(i,graph,vis,pathVis,check);
            }
        }
        for(int i=0;i<n;i++)
            if(check[i]==1) ans.push_back(i);

        return ans;
    }
};