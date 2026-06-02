const int MOD=1e9+7;

class Solution {
private:
    int getPow(int x,long long n){
        long long ans=1.0;
        long long nn=n;
        if(nn<0) nn=nn*-1;
        while(nn){
            if(nn%2==0){
                x=(1LL*x*x)%MOD;
                nn=nn/2;
            }
            else{
                ans=(1LL*ans*x)%MOD;
                nn=nn-1;
            }
        }
        return (int)ans;
    }
public:
    int countGoodNumbers(long long n) {
        double nn=n;
        long long even=ceil(nn/2.0);
        long long odd=floor(nn/2.0);
        return (1LL * getPow(5,even) * getPow(4,odd))%MOD;
    }
};