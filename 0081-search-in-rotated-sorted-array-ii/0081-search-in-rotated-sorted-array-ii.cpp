class Solution {
private:
    bool binarySearch(int low,int high,vector<int>&nums,int target){
        if(low>high) return false;
        int mid=low+(high-low)/2;
        if(nums[mid]==target) return true;
        if(nums[mid]==nums[low] && nums[mid]==nums[high]) return binarySearch(low+1,high-1,nums,target);
        else if(nums[low]<=nums[mid]){
            if(target>=nums[low] && nums[mid]>target) return binarySearch(low,mid-1,nums,target);
            else return binarySearch(mid+1,high,nums,target);
        }
        else{
            if(target>nums[mid] && nums[high]>=target) return binarySearch(mid+1,high,nums,target);
            else return binarySearch(low,mid-1,nums,target);
        }
        return false ;
    }
public:
    bool search(vector<int>& nums, int target) {
        int n=nums.size();
        bool ans=binarySearch(0,n-1,nums,target);
        return ans;
    }
};