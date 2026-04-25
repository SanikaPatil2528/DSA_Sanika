class Solution {
private:
    int helper(int idx,vector<int>& nums,int target,vector<vector<int>>&dp){
        if(idx==0){
            if(nums[idx]==0 && target==0) return 2;
            if(target==0) return 1;
            if(target==nums[idx]) return 1;
            return 0;
        }
        int notTake=helper(idx-1,nums,target,dp);
        int take=0;
        if(nums[idx]<=target) take=helper(idx-1,nums,target-nums[idx],dp);
        
        return dp[idx][target]=take+notTake;
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int totSum=0;
        for(int num:nums) totSum+=num;
        int S=(totSum-target)/2;
        if ((totSum-target)%2!=0 || (totSum-target)<0) return 0;

        vector<vector<int>> dp(nums.size(),vector<int>(S+1,-1));
        int ans=helper(nums.size()-1,nums,S,dp);
        return ans;
    }
};