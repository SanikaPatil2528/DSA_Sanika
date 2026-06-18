class Solution {
private:
    int binarySearch(int k,int low,int high,vector<int>&nums){
        if(low>high) return -1;
        int mid=low+(high-low)/2;
        if(nums[mid]==k) return mid;
        else if(nums[mid]<k) return binarySearch(k,mid+1,high,nums);
        else return binarySearch(k,low,mid-1,nums);
    }
public:
    int search(vector<int>& nums, int target) {
        int ans=binarySearch(target,0,nums.size()-1,nums);
        return ans;
    }
};