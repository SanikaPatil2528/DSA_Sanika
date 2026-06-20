class Solution {
private:
    int binarySearch(int low,int high,vector<int>&nums){
        if(low>high) return -1;
        int mid=low+(high-low)/2;
        if(mid==0 && nums[mid]!=nums[mid+1]) return nums[mid];
        if(mid==nums.size()-1 && nums[mid]!=nums[mid-1]) return nums[mid];
        if(nums[mid]!=nums[mid-1] && nums[mid]!=nums[mid+1]) return nums[mid];
        if(nums[mid]==nums[mid+1]){
            if(mid%2==1) return binarySearch(low,mid-1,nums);
            else return binarySearch(mid+1,high,nums);
        }
        else if(nums[mid]==nums[mid-1]){
            if(mid%2==0) return binarySearch(low,mid-1,nums);
            else return binarySearch(mid+1,high,nums);
        }
        return -1;
    }
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];
        int ans=binarySearch(0,n-1,nums);
        return ans;
    }
};