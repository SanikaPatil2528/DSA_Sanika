class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int m=grid.size();
        int n=grid[0].size();
        int count=0;
        vector<vector<int>>sums(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int s1=0,s2=0,s3=0;
                if(i-1>=0) s1=sums[i-1][j];
                if(j-1>=0) s2=sums[i][j-1];
                if(i-1>=0 && j-1>=0) s3=sums[i-1][j-1];
                sums[i][j]=grid[i][j]+s1+s2-s3;
                if(sums[i][j]<=k) count++;
            }
        }
        return count;
    }
};