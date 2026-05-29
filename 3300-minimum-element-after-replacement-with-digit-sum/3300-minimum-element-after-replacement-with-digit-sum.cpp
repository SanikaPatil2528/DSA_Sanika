class Solution {
public:
    int minElement(vector<int>& nums) {
        int n=nums.size();
        int mini=1e9;
        for(int i=0;i<n;i++){
            int sumi=0;
            int num=nums[i];
            while(num){
                sumi+=num%10;
                num=num/10;
            }
            nums[i]=sumi;
            mini=min(mini,sumi);
        }
        return mini;
    }
};