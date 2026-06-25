class Solution {
public:
    string reverseWords(string s) {
        int n=s.size();
        string ans="";
        int i=n-1;
        while(i>=0){
            while(i>=0 && s[i]==' ') i--;
            int end=i;
            while(i>=0 && s[i]!=' ') i--;
            string word=s.substr(i+1,end-i);
            ans+=word;
            ans+=" ";
        }
        while(ans[ans.size()-1]==' ')
            ans.pop_back();
        return ans;
    }
};