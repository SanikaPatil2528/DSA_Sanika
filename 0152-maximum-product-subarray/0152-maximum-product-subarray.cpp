class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        int currMin=nums[0];
        int currMax=nums[0];
        int ans=nums[0];
        for(int i=1;i<n;i++){
            int prod1=currMin*nums[i];
            int prod2=currMax*nums[i];
            currMin=min({nums[i],prod1,prod2});
            currMax=max({nums[i],prod1,prod2});
            ans=max(ans,currMax);
        }
        return ans;
    }
};