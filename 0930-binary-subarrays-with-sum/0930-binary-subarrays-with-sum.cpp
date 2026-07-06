class Solution {
private:
    int helper(vector<int>&nums,int goal){
        if(goal<0) return 0;
        int n=nums.size();
        int l=0,r=0;
        int ans=0;
        int sumi=0;
        while(r<n){
            sumi+=nums[r];
            while(sumi>goal){
                sumi-=nums[l];
                l++;
            }
            ans+=(r-l+1);
            r++;
        }
        return ans;
    }
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int ans=helper(nums,goal)-helper(nums,goal-1);
        return ans;
    }
};