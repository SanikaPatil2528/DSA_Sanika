class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n=nums.size();
        int total=0;
        for(int num:nums)
            total+=num;
        vector<int>ans(n);
        int leftSum=0;
        for(int i=0;i<n;i++){
            int rightSum=total-leftSum-nums[i];
            ans[i]=abs(leftSum-rightSum);
            leftSum+=nums[i];
        }
        return ans;
    }
};