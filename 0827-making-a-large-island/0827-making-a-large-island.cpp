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
private:
    bool isValid(int row,int col,int n){
        if (row>=0 && row<n && col>=0 && col<n) return true;
        return false;
    }
public:
    int largestIsland(vector<vector<int>>& grid) {
        int no_of_1=0;
        int n=grid.size();
        int drow[]={-1,0,1,0};
        int dcol[]={0,1,0,-1};
        DisjointSet ds(n*n);

        // creating components
        for(int row=0;row<n;row++){
            for(int col=0;col<n;col++){
                if (grid[row][col]==0) continue;
                no_of_1++;
                for(int ind=0;ind<4;ind++){
                    int newr=row+drow[ind];
                    int newc=col+dcol[ind];
                    if(isValid(newr,newc,n) && grid[newr][newc]==1){
                        int nodeNo=row*n + col;
                        int adjNodeNo=newr*n + newc;
                        ds.UnionBySize(nodeNo,adjNodeNo);
                    }
                }
            }
        }
        if (no_of_1==n*n) return n*n;

        // converting each 0 to 1 and checking total size of island
        int max_size=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                unordered_set<int>s;
                if(grid[i][j]==0){
                    int size_check=0;
                    for(int ind=0;ind<4;ind++){
                        int newr=i+drow[ind];
                        int newc=j+dcol[ind];
                        if(isValid(newr,newc,n) && grid[newr][newc]==1) s.insert(ds.findUParent(newr*n + newc));
                    }
                    for(auto it: s)
                        size_check+=ds.size[it];
                    size_check++; // place of 0 replaced by 1 so incremented the size of component by 1
                    max_size=max(max_size,size_check);
                }
            }
        }

        return max_size;
    }
};