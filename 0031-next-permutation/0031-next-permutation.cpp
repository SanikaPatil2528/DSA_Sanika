class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n=nums.size();
        int i=n-2;
        while(i>=0 && nums[i]>=nums[i+1])
            i--;
        
        if(i>=0){
            for(int k=n-1;k>=0;k--){
                if(nums[k]>nums[i]){
                    swap(nums[i],nums[k]);
                    break;
                }
            }
        }

        i=i+1;
        int j=n-1;
        while(i<=j){
            swap(nums[i],nums[j]);
            i++;
            j--;
        }
    }
};