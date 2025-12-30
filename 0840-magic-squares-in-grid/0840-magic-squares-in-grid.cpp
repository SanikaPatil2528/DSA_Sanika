class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        if(grid.size()<3 || grid[0].size()<3) return 0;

        int ans=0;
        for(int i=0;i<grid.size()-2;i++){
            for(int j=0;j<grid[i].size()-2;j++){
                if(isMagicGrid(grid,i,j)) ans++;
            }
        }
        return ans;
    }

    bool isMagicGrid(vector<vector<int>>& grid,int row,int col){
        // centre 5
        if(grid[row+1][col+1]!=5) return false;

        // all values between 1-9 and distinct
        bool nums[10]={false};
        for(int i=row;i<=row+2;i++){
            for(int j=col;j<=col+2;j++){
                int val=grid[i][j];
                if(grid[i][j]<1 || grid[i][j]>9 || nums[val]) return false;
                else nums[val]=true;
            }
        }

        // row and column sum
        for(int i=0;i<3;i++){
            if(grid[row+i][col]+grid[row+i][col+1]+grid[row+i][col+2]!=15) return false;
            if(grid[row][col+i]+grid[row+1][col+i]+grid[row+2][col+i]!=15) return false;
        }

        // diagonal sum
        if(grid[row][col]+grid[row+1][col+1]+grid[row+2][col+2]!=15) return false;
        if(grid[row+2][col]+grid[row+1][col+1]+grid[row][col+2]!=15) return false;

        return true;
    }
};