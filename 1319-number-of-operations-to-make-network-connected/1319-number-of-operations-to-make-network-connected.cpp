class DisjointSet{
public:
    vector<int>size,parent;

    DisjointSet(int n){
        size.resize(n,1);
        parent.resize(n);
        for(int i=0;i<n;i++)
            parent[i]=i;
    }
    int findUParent(int node){
        if(node==parent[node]) return node;
        return parent[node]=findUParent(parent[node]);
    }
    void UnionBySize(int u,int v){
        int ult_u=findUParent(u);
        int ult_v=findUParent(v);
        if(ult_u==ult_v) return;
        if(size[ult_u]<size[ult_v]){
            parent[ult_u]=ult_v;
            size[ult_v]+=size[ult_u];
        }
        else{
            parent[ult_v]=ult_u;
            size[ult_u]+=size[ult_v];
        }
    }
};

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        // connections-->edges
        DisjointSet ds(n);
        int extraEdges=0;
        for(auto edge:connections){
            int u=edge[0];
            int v=edge[1];
            if (ds.findUParent(u)==ds.findUParent(v)) extraEdges++;
            else ds.UnionBySize(u,v);
        }

        int connected_components=0;
        for(int i=0;i<n;i++)
            if (ds.parent[i]==i) connected_components++;

        if (extraEdges>=connected_components-1) return connected_components-1;
        return -1;
    }
};