class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,1);
        vector<int>freq(n,1);
        int maxi=0;
        for(int idx=0;idx<n;idx++){
            for(int prev=0;prev<idx;prev++){
                if(nums[idx]>nums[prev]){
                    if(1+dp[prev]>dp[idx]){
                        dp[idx]=1+dp[prev];
                        freq[idx]=freq[prev];
                    }
                    else if(1+dp[prev]==dp[idx]) freq[idx]+=freq[prev];
                }
            }
            maxi=max(maxi,dp[idx]);
        }
        int ans=0;
        for(int i=0;i<n;i++){
            if(dp[i]==maxi) ans+=freq[i];
        }
        return ans;
    }
};