class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int left=0;
        int right=nums.size()-1;
        while(left<=right){
            if(nums[left]==val){
                while(right>=0 && nums[right]==val) 
                    right--;
                if(right<left) break;
                swap(nums[left],nums[right]);
                right--;
            }
            left++;
        }
        return left;
    }
};