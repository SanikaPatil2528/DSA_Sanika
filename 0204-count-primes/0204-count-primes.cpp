class Solution {
public:
    int countPrimes(int n) {
        if(n<2) return 0;
        vector<int>primes(n,1);
        int count=n-1;
        count--; // 1 is not prime

        for(int i=2;i*i<n;i++){
            if(primes[i]==1){
                for(int j=i*i;j<n;j+=i){
                    if(primes[j]==1) count--;
                    primes[j]=0;
                }
            }
        }
        
        return count;
    }
};