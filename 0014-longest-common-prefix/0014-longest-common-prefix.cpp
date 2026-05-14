class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(),strs.end());
        int n=strs.size();
        int i=0;
        string first=strs[0],last=strs[n-1];
        int n1=first.size(),n2=last.size();
        while(i<min(n1,n2)){
            if(first[i]!=last[i]) break;
            i++;
        }
        string ans=first.substr(0,i);
        return ans;
    }
};