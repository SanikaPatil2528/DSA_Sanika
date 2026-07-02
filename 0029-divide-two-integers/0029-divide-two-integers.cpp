class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend==divisor) return 1;
        int sign=1;
        if(dividend>0 && divisor<0) sign=-1;
        if(dividend<0 && divisor>0) sign=-1;
        long long d=abs(1LL*divisor);
        long long n=abs(1LL*dividend);
        long long ans=0;

        while(n>=d){
            int cnt=0;
            while(n>=(d<<cnt+1)) cnt++;
            ans+=(1LL<<cnt);
            n=n-(d<<cnt);
        }
        if(ans>=1LL<<31 && sign==1) return INT_MAX;
        if(ans>1LL<<31 && sign==-1) return INT_MIN;
        return sign*ans;
    }
};