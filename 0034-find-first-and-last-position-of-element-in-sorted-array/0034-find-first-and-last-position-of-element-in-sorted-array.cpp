class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        auto low=lower_bound(nums.begin(),nums.end(),target);
        int first=low-nums.begin();
        if(first==nums.size() || nums[first]!=target) return {-1,-1};
        auto high=upper_bound(nums.begin(),nums.end(),target);
        int last=high-nums.begin();
        return {first,last-1};
    }
};