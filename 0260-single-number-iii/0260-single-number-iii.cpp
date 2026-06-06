class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int xr=0;
        for(int num:nums)
            xr=xr^num;
        long long number=1LL*xr & ~(1LL*xr-1);
        int xor0=0,xor1=0;
        for(int num:nums){
            if(number & num) xor1=xor1^num;
            else xor0=xor0^num;
        }
        return {xor0,xor1};
    }
};