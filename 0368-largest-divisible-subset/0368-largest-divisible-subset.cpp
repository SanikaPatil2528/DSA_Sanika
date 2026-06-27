class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,1);
        vector<int>hash(n);
        int maxi=0;
        int ansIdx=-1;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++) hash[i]=i;
        for(int idx=0;idx<n;idx++){
            for(int prev=0;prev<idx;prev++){
                if(nums[idx]%nums[prev]==0 && 1+dp[prev]>dp[idx]){
                    dp[idx]=1+dp[prev];
                    hash[idx]=prev;
                }
            }
            if(dp[idx]>maxi){
                maxi=dp[idx];
                ansIdx=idx;
            }
        }
        vector<int>temp;
        temp.push_back(nums[ansIdx]);
        while(hash[ansIdx]!=ansIdx){
            temp.push_back(nums[hash[ansIdx]]);
            ansIdx=hash[ansIdx];
        }
        return temp;
    }
};