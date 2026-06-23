class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();
        int low=0,high=m-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            int maxi=-1,maxIdx=-1;
            for(int i=0;i<n;i++){
                if(mat[mid][i]>maxi){
                    maxi=mat[mid][i];
                    maxIdx=i;
                }
            }
            int top=mid>0?mat[mid-1][maxIdx]:-1;
            int bottom=mid<m-1?mat[mid+1][maxIdx]:-1;
            if(maxi>top && maxi>bottom) return {mid,maxIdx};
            else if(maxi<top) high=mid-1;
            else low=mid+1;
        }
        return {-1,-1};
    }
};