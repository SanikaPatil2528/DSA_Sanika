class Solution {
private:
    void getSubsets(int idx,vector<int>&curr,vector<int>&nums,set<vector<int>>&s){
        if(idx==nums.size()){
            s.insert(curr);
            return;
        }
        curr.push_back(nums[idx]);
        getSubsets(idx+1,curr,nums,s);
        curr.pop_back();
        getSubsets(idx+1,curr,nums,s);
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>>ans;
        set<vector<int>>s;
        sort(nums.begin(),nums.end());
        vector<int>curr;
        getSubsets(0,curr,nums,s);
        for(auto c:s){
            ans.push_back(c);
        }
        return ans;
    }
};