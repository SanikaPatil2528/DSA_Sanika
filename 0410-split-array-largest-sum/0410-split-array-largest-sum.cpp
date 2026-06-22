class Solution {
private:
    int countStudents(int p,vector<int>&nums){
        int s=1;
        int sumi=0;
        int idx=0;
        while(idx<nums.size()){
            if(sumi+nums[idx]>p){
                s++;
                sumi=nums[idx];
            }
            else sumi+=nums[idx];
            idx++;
        }
        return s;
    }
public:
    int splitArray(vector<int>& nums, int k) {
        int maxi=-1e9,sumi=0;
        for(int num:nums){
            maxi=max(maxi,num);
            sumi+=num;
        }
        int low=maxi,high=sumi;
        while(low<=high){
            int mid=low+(high-low)/2;
            int s=countStudents(mid,nums);
            if(s>k) low=mid+1;
            else high=mid-1;
        }
        return low;
    }
};