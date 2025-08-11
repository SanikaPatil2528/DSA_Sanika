class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        unordered_map<int,int> mpp;
        vector<int>expected_nums;
        int j=0;
        for (int i=0;i<nums.size();i++)
        {
            mpp[nums[i]]+=1;
           if (mpp[nums[i]]==1)
           {
            expected_nums.push_back(nums[i]);
            nums[j]=nums[i];
            j++;
           }
        }
        int k=expected_nums.size();
        return k;
    }
};