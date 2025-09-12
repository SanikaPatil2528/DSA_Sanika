class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum=INT_MIN,currSum=0;
        for(int i=0;i<nums.size();i++)
        {
            currSum+=nums[i];
            if (currSum>maxSum) maxSum=currSum;

            // start a new subarray or continue same subarray
            if (currSum<0) currSum=0;
        }
        return maxSum;
    }
};