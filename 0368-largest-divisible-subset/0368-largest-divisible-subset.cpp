class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int>dp(nums.size(),1);
        vector<int>hash(nums.size());
        hash[0]=0;
        int maxi=1;
        int ind=0;

        for(int i=1;i<nums.size();i++){
            hash[i]=i;
            for(int j=0;j<i;j++){
                if(nums[i]%nums[j]==0 && dp[i]<dp[j]+1){
                    dp[i]=dp[j]+1;
                    hash[i]=j;
                }
            }
            if(maxi<dp[i]){
                maxi=dp[i];
                ind=i;
            }
        }

        vector<int>ans;
        while(ind!=hash[ind]){
            ans.push_back(nums[ind]);
            ind=hash[ind];
        }
        ans.push_back(nums[ind]);
        reverse(ans.begin(),ans.end());
        return ans;
    }
};