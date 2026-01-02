class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        if(nums.size()==0) return 0;
        unordered_map<int,int>mpp;
        for(int i=0;i<nums.size();i++){
            if(mpp[nums[i]]==0) mpp[nums[i]]=1;
            else return nums[i];
        }
        return 0;
    }
};