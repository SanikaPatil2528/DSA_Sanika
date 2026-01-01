class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int>ans=digits;
        reverse(ans.begin(),ans.end());
        int carry=1;
        for(int i=0;i<digits.size();i++){
            int sum=carry+ans[i];
            ans[i]=sum%10;
            carry=sum/10;
        }
        if(carry!=0) ans.push_back(carry);
        reverse(ans.begin(),ans.end());
        return ans;
    }
};