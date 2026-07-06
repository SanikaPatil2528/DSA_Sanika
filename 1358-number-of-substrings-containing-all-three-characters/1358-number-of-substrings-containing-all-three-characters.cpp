class Solution {
public:
    int numberOfSubstrings(string s) {
        int n=s.size();
        int a=-1,b=-1,c=-1;
        int i=0;
        int ans=0;
        while(i<n){
            if(s[i]=='a') a=i;
            else if(s[i]=='b') b=i;
            else c=i;
            if(a!=-1 && b!=-1 && c!=-1){
                int mini=min({a,b,c});
                ans+=(1+mini);
            }
            i++;
        }
        return ans;
    }
};