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
    int largestIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<int>size(n*n,1);
        vector<int>par(n*n);
        for(int i=0;i<n*n;i++)
            par[i]=i;
        vector<int>drow={-1,0,1,0};
        vector<int>dcol={0,1,0,-1};
        
        // connecting 1's and creating islands
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0) continue;
                int cell=i*n+j;
                for(int k=0;k<4;k++){
                    int nr=i+drow[k];
                    int nc=j+dcol[k];
                    if(nr>=0 && nr<n && nc>=0 && nc<n && grid[nr][nc]==1){
                        int newCell=nr*n+nc;
                        if(findUPar(cell,par)!=findUPar(newCell,par)) unionBySize(cell,newCell,size,par);
                    }
                }
            }
        }

        // checking for all 0's
        int maxi=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0){
                    unordered_set<int>st; // to store unique neighbouring components
                    for(int k=0;k<4;k++){
                        int nr=i+drow[k];
                        int nc=j+dcol[k];
                        if(nr>=0 && nr<n && nc>=0 && nc<n && grid[nr][nc]==1){
                            st.insert(findUPar(nr*n+nc,par));
                        }
                    }
                    int cnt=1;
                    for(auto it:st)
                        cnt+=size[it];
                    maxi=max(maxi,cnt);
                }
            }
        }
        if(maxi==0){
            for(int i=0;i<n*n;i++)
                maxi=max(maxi,size[i]);
        }
        return maxi;
    }
};