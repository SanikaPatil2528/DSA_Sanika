class Solution {
private:
    bool check(int n,int t){
        int prod=1;
        while(n){
            int d=n%10;
            prod*=d;
            n=n/10;
        }
        if(prod%t==0) return true;
        return false;
    }
public:
    int smallestNumber(int n, int t) {
        while(true){
            bool temp=check(n,t);
            if(temp) return n;
            n++;
        }
        return -1;
    }
};