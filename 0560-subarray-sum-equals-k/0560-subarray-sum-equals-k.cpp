class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        // {sum,freq}
        unordered_map<int,int>mpp;
        int count=0;
        int n=nums.size();
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            if(sum==k) count++;
            int rem=sum-k;
            if(mpp.find(rem)!=mpp.end()) count+=mpp[rem];
            mpp[sum]++;
        }
        return count;
    }
};