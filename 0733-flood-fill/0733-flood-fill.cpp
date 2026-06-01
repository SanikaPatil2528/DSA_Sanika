class Solution {
private:
    void dfs(int r,int c,vector<vector<int>>&copy,int newColor,vector<int>&drow,vector<int>&dcol,int iniColor,vector<vector<int>>& image){
        copy[r][c]=newColor;
        for(int i=0;i<4;i++){
            int nr=r+drow[i];
            int nc=c+dcol[i];
            if(nr>=0 && nr<copy.size() && nc>=0 && nc<copy[0].size() && image[nr][nc]==iniColor && copy[nr][nc]!=newColor){
                dfs(nr,nc,copy,newColor,drow,dcol,iniColor,image);
            }
        }
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        vector<vector<int>>copy(image.size(),vector<int>(image[0].size()));
        for(int i=0;i<image.size();i++){
            for(int j=0;j<image[0].size();j++){
                copy[i][j]=image[i][j];
            }
        }
        vector<int> drow={-1,0,1,0};
        vector<int> dcol={0,1,0,-1};
        int iniColor=image[sr][sc];
        dfs(sr,sc,copy,color,drow,dcol,iniColor,image);
        return copy;
    }
};