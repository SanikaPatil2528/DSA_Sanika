class Solution {
private:
    void getSubsets(int idx,vector<int>&curr,vector<int>&nums,vector<vector<int>>&ans){
        ans.push_back(curr);
        for(int i=idx;i<nums.size();i++){
            if(i>idx && nums[i]==nums[i-1]) continue;

            curr.push_back(nums[i]);
            getSubsets(i+1,curr,nums,ans);
            curr.pop_back();
        }
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>curr;
        sort(nums.begin(),nums.end());
        getSubsets(0,curr,nums,ans);
        return ans;
    }
};