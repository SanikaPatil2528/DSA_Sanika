class Solution {
// private:
//     int helper(int idx,vector<int>&nums,bool firstPicked,vector<vector<int>>&dp){
//         if(idx==nums.size()-1){
//             if(firstPicked) return 0;
//             return nums[idx];
//         }
//         if(idx>=nums.size()) return 0;
//         if(dp[idx][firstPicked]!=-1) return dp[idx][firstPicked];

//         int pick;
//         if(idx==0) pick=nums[idx]+helper(idx+2,nums,true,dp);
//         else pick=nums[idx]+helper(idx+2,nums,firstPicked,dp);
//         int notPick=helper(idx+1,nums,firstPicked,dp);

//         return dp[idx][firstPicked]=max(pick,notPick);
        // }
public:
    int rob(vector<int>& nums) {
        // vector<vector<int>>dp(nums.size(),vector<int>(2,-1));
        // int ans=helper(0,nums,false,dp);
        // return ans;

        // TABULATION
        vector<vector<int>>dp(nums.size(),vector<int>(2));
        if(nums.size()==1) return nums[0];
        dp[nums.size()-1][1]=0;
        dp[nums.size()-1][0]=nums[nums.size()-1];
        for(int idx=nums.size()-2;idx>=0;idx--){
            if(idx==0){
                dp[0][false]=dp[1][false];
                dp[0][true]=nums[0];
                if(nums.size()>2) dp[0][true]+=dp[2][true];
                break;
            }

            // for firstPicked is true
            int pick1=nums[idx],notPick1=-1e9;
            if(idx+2<nums.size()) pick1+=dp[idx+2][true];
            if(idx+1<nums.size()) notPick1=dp[idx+1][true];
            dp[idx][true]=max(pick1,notPick1);

            // for firstPicked is false
            int pick2=nums[idx],notPick2=-1e9;
            if(idx+2<nums.size()) pick2+=dp[idx+2][false];
            if(idx+1<nums.size()) notPick2=dp[idx+1][false];
            dp[idx][false]=max(pick2,notPick2);
        }
        return max(dp[0][true],dp[0][false]);
    }
};