class Solution {
private:
    long long getDays(int k,vector<int>&weights){
        long long ans=0;
        long long sumi=0;
        int idx=0;
        while(idx<weights.size()){
            while(idx<weights.size() && weights[idx]+sumi<=k){
                sumi+=weights[idx];
                idx++;
            }
            ans++;
            sumi=0;
        }
        return ans;
    }
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int sumi=0;
        int maxi=-1e9;
        for(int num:weights) {
            sumi+=num;
            maxi=max(maxi,num);
        }
        int low=maxi,high=sumi;
        while(low<=high){
            int mid=low+(high-low)/2;
            long long d=getDays(mid,weights);
            if(d<=days) high=mid-1;
            else low=mid+1;
        }
        return low;
    }
};