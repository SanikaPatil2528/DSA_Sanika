class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int ans=0;
        int l=0,r=0;
        int n=nums.size();
        unordered_map<int,int>mpp;
        while(r<n){
            mpp[nums[r]]++;
            if(mpp[nums[r]]<=k){
                int leni=r-l+1;
                ans=max(ans,leni);
            }
            else{
                while(mpp[nums[r]]>k){
                    mpp[nums[l]]--;
                    l++;
                }
            }
            r++;
        }
        return ans;
    }
};