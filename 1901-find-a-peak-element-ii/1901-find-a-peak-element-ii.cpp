class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();
        int low=0,high=m-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            int maxEle=INT_MIN,idx=-1;
            for(int i=0;i<n;i++){
                if(mat[mid][i]>maxEle){
                    maxEle=mat[mid][i];
                    idx=i;
                }
            }
            int top= mid>0? mat[mid-1][idx]: -1;
            int bottom= mid<m-1 ?mat[mid+1][idx] :-1;
            if(mat[mid][idx]>top && mat[mid][idx]>bottom) return {mid,idx};
            if(mat[mid][idx]>top) low=mid+1;
            else high=mid-1;
        }
        return {-1,-1};
    }
};