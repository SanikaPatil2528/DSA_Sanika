class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int breakPoint=-1;
        int n=nums.size();
        for(int i=n-1;i>0;i--){
            if(nums[i]>nums[i-1]){
                breakPoint=i-1;
                break;
            }
        }
        if (breakPoint==-1) reverse(nums.begin(),nums.end());
        else{
            for(int i=n-1;i>breakPoint;i--){
                if(nums[i]>nums[breakPoint]){
                    swap(nums[i],nums[breakPoint]);
                    break;
                }
            }
            int start=breakPoint+1;
            int end=n-1;
            while(start<=end){
                swap(nums[start],nums[end]);
                start++;
                end--;
            }            
        }
    }
};