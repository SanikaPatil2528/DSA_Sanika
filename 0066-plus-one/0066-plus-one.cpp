class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int>v;
        int sum=digits[digits.size()-1]+1;
        int carry=sum/10;
        sum=sum%10;
        v.push_back(sum);
        for(int i=digits.size()-2;i>=0;i--)
        {
            sum=digits[i]+carry;
            carry=sum/10;
            sum=sum%10;
            v.push_back(sum);
        }
        if(carry) v.push_back(carry);
        digits.clear();
        for(int i=v.size()-1;i>=0;i--)
            digits.push_back(v[i]);
        return digits;
    }
};