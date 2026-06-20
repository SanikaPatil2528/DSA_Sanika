class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        auto lb=lower_bound(nums.begin(),nums.end(),target);
        auto ub=upper_bound(nums.begin(),nums.end(),target);
        int first,last;
        if(lb-nums.begin()==nums.size() || nums[lb-nums.begin()]!=target){
            first=-1;
            last=-1;
        }
        else{
            first=lb-nums.begin();
            last=ub-nums.begin()-1;
        }
        return {first,last};
    }
};