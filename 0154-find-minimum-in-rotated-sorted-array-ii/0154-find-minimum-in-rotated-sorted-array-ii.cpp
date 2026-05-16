class Solution {
private:
    int binarySearch(vector<int>&nums,int low,int high){
        int mini=INT_MAX;
        while(low<=high){
            int mid=low+(high-low)/2;
            mini=min(mini,nums[mid]);
            if(nums[low]==nums[mid] && nums[high]==nums[mid]){
                low++;
                high--;
            }
            else if(nums[low]<=nums[mid]){
                mini=min(mini,nums[low]);
                low=mid+1;
            }
            else{
                mini=min(mini,nums[mid+1]);
                high=mid-1;
            }
        }
        return mini;
    }
public:
    int findMin(vector<int>& nums) {
        int n=nums.size();
        int ans=binarySearch(nums,0,n-1);
        return ans;
    }
};