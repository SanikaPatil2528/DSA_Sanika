class Solution {
private:
    void binarySearch(int low,int high,int &mini,vector<int>&nums){
        if(low>high) return ;
        int mid=low+(high-low)/2;
        if(nums[low]<=nums[mid]){
            mini=min(mini,nums[low]);
            binarySearch(mid+1,high,mini,nums);
        }
        else{
            mini=min(mini,nums[mid]);
            binarySearch(low,mid-1,mini,nums);
        }
    }
public:
    int findMin(vector<int>& nums) {
        int n=nums.size();
        int mini=INT_MAX;
        binarySearch(0,n-1,mini,nums);
        return mini;
    }
};