class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans;
        if(n==1) return {nums[0]};
        int cnt1=0,cnt2=0;
        int ele1,ele2;
        for(int i=0;i<n;i++){
            if(cnt1==0 && nums[i]!=ele2)
                ele1=nums[i];
            if(cnt2==0 && nums[i]!=ele1)
                ele2=nums[i];
                
            if(nums[i]==ele1) cnt1++;
            else if(nums[i]==ele2) cnt2++;
            else{
                cnt1--;
                cnt2--;
            }
        }

        int check1=0,check2=0;
        for(int i=0;i<n;i++){
            if(nums[i]==ele1) check1++;
            else if(nums[i]==ele2) check2++;
        }
        int check=n/3;
        if(check1>check) ans.push_back(ele1);
        if(check2>check) ans.push_back(ele2);
        return ans;
    }
};