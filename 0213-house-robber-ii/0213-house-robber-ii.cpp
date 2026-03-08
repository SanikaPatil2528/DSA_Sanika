class Solution {
private:
    int helper(vector<int>&nums,int index,vector<int>&dp){
        if(index==0) return nums[index];
        if(index<0) return 0;
        if(dp[index]!=-1) return dp[index];
        int pick=nums[index]+helper(nums,index-2,dp);
        int notPick=0+helper(nums,index-1,dp);
        return dp[index]=max(pick,notPick);
    }
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];
        vector<int>temp(nums.begin()+1,nums.end());
        vector<int>dp1(n,-1);
        vector<int>dp2(n-1,-1);
        int ans1=helper(nums,n-2,dp1); // leave last element
        int ans2=helper(temp,n-2,dp2); // leave last element
        return max(ans1,ans2);
    }
};