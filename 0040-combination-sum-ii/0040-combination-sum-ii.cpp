class Solution {
private:
    void getCombinations(vector<int>&candidates,int target,vector<int>&curr,vector<vector<int>>&ans,int idx){
        if(target==0){
            ans.push_back(curr);
            return ;
        }

        // Loop through the elements starting from index 'idx'
        for(int i=idx;i<candidates.size();i++){
            // skip duplicates to avoid repeating combinations
            if(i>idx && candidates[i]==candidates[i-1]) continue;

            if(candidates[i]>target) break;

            // pick
            curr.push_back(candidates[i]);
            getCombinations(candidates,target-candidates[i],curr,ans,i+1);
            curr.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<int>curr;
        vector<vector<int>>ans;
        getCombinations(candidates,target,curr,ans,0);
        return ans; 
    }
};