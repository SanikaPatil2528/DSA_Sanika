class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m=image.size();
        int n=image[0].size();
        int iniColor=image[sr][sc];
        // copy of given data
        vector<vector<int>> ans=image;

        int drow[]={0,-1,0,1};
        int dcol[]={-1,0,1,0};
        dfs(sr,sc,ans,iniColor,image,color,drow,dcol,m,n);
        return ans;
    }

    void dfs(int r,int c,vector<vector<int>>&ans,int iniColor,vector<vector<int>>&image,int newColor,int drow[],int dcol[],int m,int n){
        ans[r][c]=newColor;
        for(int i=0;i<4;i++){
            int nrow=r+drow[i];
            int ncol=c+dcol[i];
            if(nrow>=0 && nrow<m && ncol>=0 && ncol<n && image[nrow][ncol]==iniColor && ans[nrow][ncol]!=newColor){
                dfs(nrow,ncol,ans,iniColor,image,newColor,drow,dcol,m,n);
            }
        }
    }
};