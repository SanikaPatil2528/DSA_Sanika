class Solution {
public:
    string processStr(string s) {
        string res="";
        for(int i=0;i<s.size();i++){
            if(s[i]>='a' && s[i]<='z') res=res+s[i];
            else if(s[i]=='*' && res.size()!=0) res.pop_back();
            else if(s[i]=='#') res=res+res;
            else reverse(res.begin(),res.end());
        }
        return res;
    }
};