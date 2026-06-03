class Solution {
private:
    void getCombinations(vector<int>&candidates,int target,vector<int>&curr,vector<vector<int>>&ans,int idx){
        if(idx==candidates.size()){
            if(target==0) ans.push_back(curr);
            return;
        }
        // pick
        if(candidates[idx]<=target){
            curr.push_back(candidates[idx]);
            getCombinations(candidates,target-candidates[idx],curr,ans,idx);
            curr.pop_back();
        }
        // not pick
        getCombinations(candidates,target,curr,ans,idx+1);
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int>curr;
        vector<vector<int>>ans;
        getCombinations(candidates,target,curr,ans,0);
        return ans; 
    }
};