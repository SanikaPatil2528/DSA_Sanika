class Solution {
private:
    int findUParent(vector<int>&parent,int node){
        if(node==parent[node]) return node;
        return parent[node]=findUParent(parent,parent[node]);
    }
    void unionBySize(int u,int v,vector<int>&parent,vector<int>&size){
        int up_u=findUParent(parent,u);
        int up_v=findUParent(parent,v);
        if(up_u==up_v) return;
        if(size[up_u]<size[up_v]){
            parent[up_u]=up_v;
            size[up_v]+=size[up_u];
        }
        else if(size[up_u]>=size[up_v]){
            parent[up_v]=up_u;
            size[up_u]+=size[up_v];
        }
    }
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        vector<int>size(n,1);
        vector<int>parent(n);
        for(int i=0;i<n;i++)
            parent[i]=i;
        
        int extraEdges=0;
        int components=0;

        for(auto connection:connections){
            int u=connection[0];
            int v=connection[1];
            if(findUParent(parent,u)==findUParent(parent,v)) extraEdges++;
            unionBySize(u,v,parent,size);
        }

        for(int i=0;i<n;i++)
            if(parent[i]==i) components++;
        
        if(extraEdges>=components-1) return components-1;
        return -1;
    }
};