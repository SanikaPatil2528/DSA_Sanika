class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(nums.size()==0) return -1;

        int index=binarySearch(0,nums.size()-1,nums,target);
        return index;
    }

    int binarySearch(int low,int high,vector<int>& nums,int target){
        while(low<=high){
            int mid=low+(high-low)/2;
            if(nums[mid]==target) return mid;

            if(nums[mid]>target) high=mid-1;
            else low=mid+1;
        }
        return -1;
    }
};