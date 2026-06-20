class Solution {
private:    
    int binarySearch(int low,int high,vector<int>&nums){
        if(nums[0]>nums[1]) return 0;
        if(nums[nums.size()-1]>nums[nums.size()-2]) return nums.size()-1;
        low=1;
        high=high-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(nums[mid]>nums[mid-1] && nums[mid]>nums[mid+1]) return mid;
            else if(nums[mid]>nums[mid-1]) low=mid+1;
            else high=mid-1;
        }
        return -1;
    }
public:
    int findPeakElement(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return 0;
        int ans=binarySearch(0,n-1,nums);
        return ans;
    }
};