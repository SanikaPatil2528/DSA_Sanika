class Solution {
private:
    int findUPar(int node,vector<int>&par){
        if(par[node]==node) return node;
        return par[node]=findUPar(par[node],par);
    }
    void unionBySize(int u,int v,vector<int>&size,vector<int>&par){
        int up_u=findUPar(u,par);
        int up_v=findUPar(v,par);
        if(up_u==up_v) return ;
        if(size[up_u]<size[up_v]){
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
        int maxr=0,maxc=0;
        for(auto stone:stones){
            maxr=max(maxr,stone[0]);
            maxc=max(maxc,stone[1]);
        }
        int totNodes=maxr+1+maxc+1;
        vector<int>size(totNodes,1);
        vector<int>par(totNodes);
        for(int i=0;i<totNodes;i++)
            par[i]=i;
        
        unordered_set<int>usedStones;
        for(auto stone:stones){
            int r=stone[0];
            int c=stone[1];
            int shiftedC=c+maxr+1;
            unionBySize(r,shiftedC,size,par);
            usedStones.insert(r);
            usedStones.insert(shiftedC);
        }

        int comp=0;
        for(auto node:usedStones)
            if(findUPar(node,par)==node) comp++;
        
        return stones.size()-comp;
    }
};