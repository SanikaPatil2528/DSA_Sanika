class Solution {
public:
    int myAtoi(string s) {
        int n=s.size();
        int i=0;
        while(i<n && s[i]==' ')
            i++;
        long long ans=0;
        int sign=1;
        if(i<n && (s[i]=='+' || s[i]=='-')){
            if(s[i]=='-') sign=-1;
            i++;
        }
        while(i<n && s[i]-'0'>=0 && s[i]-'0'<=9){
            long long temp=(long long)ans*10;
            long long num=temp+s[i]-'0';
            if(num*sign<INT_MIN) {
                ans=INT_MIN;
                return ans;
            }
            else if(sign*num>INT_MAX){
                ans=INT_MAX;
                return ans;
            }
            else{
                ans=ans*10;
                ans+=s[i]-'0';
                i++;
            }
        }
        return sign*ans;
    }
};