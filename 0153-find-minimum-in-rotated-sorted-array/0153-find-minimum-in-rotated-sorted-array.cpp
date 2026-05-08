class Solution {
public:
    int findMin(vector<int>& nums) {
        int low=0,high=nums.size()-1;
        int ans=INT_MAX;
        while(low<=high){
            int mid=low+(high-low)/2;
            ans=min(ans,nums[mid]);
            // left sorted
            if(nums[low]<=nums[mid]){
                ans=min(ans,nums[low]);
                low=mid+1;
            }
            // right sorted
            else{
                ans=min(ans,nums[mid+1]);
                high=mid-1;
            }
        }
        return ans; 
    }
};