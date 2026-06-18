class Solution {
private:
    int helper(int idx,vector<int>&nums,bool firstPicked,vector<vector<int>>&dp){
        if(idx==nums.size()-1){
            if(firstPicked) return 0;
            return nums[idx];
        }
        if(idx>=nums.size()) return 0;
        if(dp[idx][firstPicked]!=-1) return dp[idx][firstPicked];

        int pick;
        if(idx==0) pick=nums[idx]+helper(idx+2,nums,true,dp);
        else pick=nums[idx]+helper(idx+2,nums,firstPicked,dp);
        int notPick=helper(idx+1,nums,firstPicked,dp);

        return dp[idx][firstPicked]=max(pick,notPick);
    }
public:
    int rob(vector<int>& nums) {
        vector<vector<int>>dp(nums.size(),vector<int>(2,-1));
        int ans=helper(0,nums,false,dp);
        return ans;
    }
};