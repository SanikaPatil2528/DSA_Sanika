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
    int removeStones(vector<vector<int>>& stones) {
        int max_row=0;
        int max_col=0;
        for(auto stone:stones){
            max_row=max(max_row,stone[0]);
            max_col=max(max_col,stone[1]);
        }

        DisjointSet ds(max_row+max_col+2);

        // to avoid using lot of unused nodes(rows/cols)
        unordered_map<int,int>stoneNodes;
        for(auto it:stones){
            int nodeRow=it[0];
            int nodeCol=it[1];
            int newNodeCol=nodeCol+max_row+1;
            ds.UnionBySize(nodeRow,newNodeCol);
            stoneNodes[nodeRow]=1;
            stoneNodes[newNodeCol]=1;
        }
    
    int cnt=0;
    for(auto it:stoneNodes){
        if(ds.findUParent(it.first)==it.first) cnt++;
    }
    return stones.size()-cnt;
    }
};