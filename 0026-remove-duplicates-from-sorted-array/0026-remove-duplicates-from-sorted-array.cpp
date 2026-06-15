class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n=nums.size();
        int recent=nums[0];
        int idx=1;
        int k=1;
        for(int i=1;i<n;i++){
            if(nums[i]!=recent){
                nums[idx]=nums[i];
                idx++;
                recent=nums[i];
                k++;
            }
        }
        return k;
    }
};