class Solution {
private:
    long long getSum(int div,vector<int>&nums){
        long long ans=0;
        for(int num:nums){
            ans+=(num-1)/div + 1;
        }
        return ans;
    }
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n=nums.size();
        int maxi=-1e9;
        for(int num:nums) 
            maxi=max(maxi,num);
        int ans=maxi;
        int low=1,high=maxi;
        while(low<=high){
            int mid=low+(high-low)/2;
            long long sumi=getSum(mid,nums);
            if(sumi<=threshold){
                ans=mid;
                high=mid-1;
            }
            else low=mid+1;
        }
        return ans;
    }
};