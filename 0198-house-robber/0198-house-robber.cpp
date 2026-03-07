class Solution {
private:
    int helper(vector<int>&nums,int index,vector<int>&dp){
        if(index==0) return nums[index];
        if (index<0) return 0;
        if(dp[index]!=-1) return dp[index];

        int pick=nums[index]+helper(nums,index-2,dp);
        int notPick=0+helper(nums,index-1,dp);
        return dp[index]=max(pick,notPick);
    }

public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,-1);
        int ans=helper(nums,n-1,dp);
        return ans;
    }
};