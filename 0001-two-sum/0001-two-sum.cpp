class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int>temp=nums;
        int num1=0,num2=0;
        sort(temp.begin(),temp.end());
        int i=0,j=nums.size()-1;
        while(i<j){
            if(temp[i]+temp[j]==target){
                num1=temp[i];
                num2=temp[j];
                break;
            }
            else if(temp[i]+temp[j]>target) j--;
            else i++;
        }
        vector<int>ans;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==num1 || nums[i]==num2) ans.push_back(i);
        }
        return ans;
    }
};