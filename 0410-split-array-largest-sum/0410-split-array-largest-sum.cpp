class Solution {
private:
    bool checkPossible(vector<int>&nums,int mid,int k){
        int partitions=1;
        int sum=0,n=nums.size();
        for(int i=0;i<n;i++){
            if(sum+nums[i] > mid){
                partitions++;
                sum=nums[i];
            }
            else sum+=nums[i];
        }
        if(partitions>k) return false;
        return true;
    }
public:
    int splitArray(vector<int>& nums, int k) {
        int n=nums.size();
        int sum=0,maxEle=-1;
        for(int num:nums){
            sum+=num;
            maxEle=max(maxEle,num);
        }
        int low=maxEle;
        int high=sum;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(checkPossible(nums,mid,k)) high=mid-1;
            else low=mid+1;
        }
        return low;
    }
};