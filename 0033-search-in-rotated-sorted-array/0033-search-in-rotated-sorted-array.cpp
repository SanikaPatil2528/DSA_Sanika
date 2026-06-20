class Solution {
private:
    int binarySearch(int low,int high,vector<int>&nums,int target){
        if(low>high) return -1;
        int mid=low+(high-low)/2;
        if(nums[mid]==target) return mid;
        if(nums[low]<=nums[mid]){
            if(target>=nums[low] && target<nums[mid]) return binarySearch(low,mid-1,nums,target);
            else return binarySearch(mid+1,high,nums,target);
        }
        else if(nums[mid]<nums[high]){
            if(target>nums[mid] && target<=nums[high]) return binarySearch(mid+1,high,nums,target);
            else return binarySearch(low,mid-1,nums,target);
        } 
        return -1;
    }
public:
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        int ans=binarySearch(0,n-1,nums,target);
        return ans;
    }
};