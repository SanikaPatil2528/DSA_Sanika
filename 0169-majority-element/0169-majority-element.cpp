class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int>mpp;
        int check=nums.size()/2;
        for(int i=0;i<nums.size();i++)
            mpp[nums[i]]++;
        for(auto it=mpp.begin();it!=mpp.end();it++)
            if(it->second>check) return it->first;

        return 0;
    }
};