class Solution {
public:
    double myPow(double x, int n) {
        long long nn=abs(1LL*n);
        double ans=1.00;
        while(nn){
            if(nn%2==0){
                x=x*x;
                nn=nn/2;
            }
            else{
                ans=x*ans;
                nn=nn-1;
            }
        }
        if(n<0) ans=1.0/ans;
        return ans;
    }
};