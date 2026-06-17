class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        // sum,freq
        unordered_map<int,int>mpp;
        int cnt=0;
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            if(sum==k) cnt++;
            int rem=sum-k;
            if(!mpp.empty() && mpp.find(rem)!=mpp.end()) cnt+=mpp[rem];
            mpp[sum]++;
        }
        return cnt;
    }
};