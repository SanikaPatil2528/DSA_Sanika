class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int currMax=nums[0];
        int currMin=nums[0];
        int ans=nums[0];
        int n=nums.size();
        for(int i=1;i<n;i++){
            int tempMax=max({nums[i],currMax*nums[i],currMin*nums[i]});
            int tempMin=min({nums[i],currMax*nums[i],currMin*nums[i]});
            currMax=tempMax;
            currMin=tempMin;
            ans=max(ans,currMax);
        }
        return ans;
    }
};