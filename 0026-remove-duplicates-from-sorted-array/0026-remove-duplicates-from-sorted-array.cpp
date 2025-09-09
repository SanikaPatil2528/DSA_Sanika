class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int k=1;
        int j=1,check=nums[0];
        for (int i=0;i<nums.size();i++)
        {
            if (nums[i]==check) continue;
            k++;
            check=nums[i];
            nums[j]=nums[i];
            j++;
        }
        return k;
    }
};