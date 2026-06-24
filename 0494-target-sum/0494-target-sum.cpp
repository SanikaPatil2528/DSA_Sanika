class Solution {
private:
    int helper(int idx,int k,vector<int>&nums,vector<vector<int>>&dp){
        if(idx==nums.size()){
            if(k==0) return 1;
            return 0;
        }
        if(dp[idx][k]!=-1) return dp[idx][k];
        
        int pick=0;
        if(nums[idx]<=k) pick=helper(idx+1,k-nums[idx],nums,dp);
        int notPick=helper(idx+1,k,nums,dp);
        return dp[idx][k]=pick+notPick;
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        int sumi=0;
        for(int num:nums) sumi+=num;
        if((sumi+target)%2!=0) return 0;
        if(abs(target)>sumi) return 0;
        vector<vector<int>>dp(nums.size(),vector<int>((sumi+target)/2 + 1,-1));
        int ans=helper(0,(sumi+target)/2,nums,dp);
        return ans;
    }
};