class Solution {
private:
    bool dfs(int node,vector<vector<int>>&graph,int col,vector<int>&color){
        color[node]=col;
        for(auto neighbor:graph[node]){
            if(color[neighbor]==col) return false;
            if(color[neighbor]==-1){
                if(dfs(neighbor,graph,!col,color)==false) return false;
            }
        }
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int>color(n,-1);
        for(int i=0;i<n;i++){
            if(color[i]==-1){
                if(dfs(i,graph,0,color)==false) return false;
            }
        }
        return true;
    }
};