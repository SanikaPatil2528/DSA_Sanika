class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size();
        int n=matrix[0].size();
        int r=m-1,c=0;
        while(r>=0 && c<n){
            if(matrix[r][c]==target) return true;
            else if(matrix[r][c]>target) r--;
            else c++;
        }
        return false;
    }
};