class Solution {
private:
    int findUPar(int node,vector<int>&parent){
        if(parent[node]==node) return node;
        return parent[node]=findUPar(parent[node],parent);
    }
    void unionBySize(int u,int v,vector<int>&size,vector<int>&par){
        if(findUPar(u,par)==findUPar(v,par)) return ;
        int up_u=findUPar(u,par);
        int up_v=findUPar(v,par);
        if(size[up_u]<up_v){
            par[up_u]=up_v;
            size[up_v]+=size[up_u];
        }
        else{
            par[up_v]=up_u;
            size[up_u]+=size[up_v];
        }
    }
public:
    int removeStones(vector<vector<int>>& stones) {
        vector<vector<int>>edges;
        for(int i=0;i<stones.size();i++){
            for(int j=0;j<stones.size();j++){
                if(i==j) continue;
                if(stones[i][0]==stones[j][0] || stones[i][1]==stones[j][1]) edges.push_back({i,j});
            }
        }
        vector<int>size(stones.size(),1);
        vector<int>par(stones.size());
        for(int i=0;i<stones.size();i++)
            par[i]=i;
        
        for(auto edge:edges){
            if(findUPar(edge[0],par)!= findUPar(edge[1],par)) unionBySize(edge[0],edge[1],size,par);
        }
        int comp=0;
        for(int i=0;i<stones.size();i++)
            if(par[i]==i) comp++;
        return stones.size()-comp;
    }
};