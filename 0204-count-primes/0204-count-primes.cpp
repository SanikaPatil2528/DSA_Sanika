class Solution {
public:
    int countPrimes(int n) {
        if(n<2) return 0;
        vector<int>p(n+1,1);
        int cnt=n-2;
        for(int i=2;i*i<n;i++){
            if(p[i]==1){
                for(int j=i*i;j<n;j+=i) {
                    if(p[j]==1) cnt--;
                    p[j]=0;
                }
            }
        }
        return cnt;
    }
};