class Solution {
public:
    string longestPalindrome(string s) {
        int paliStart=-1,paliEnd=-1;
        int maxi=0;
        int n=s.size();
        // odd lengths
        for(int i=0;i<n;i++){
            int left=i;
            int right=i;
            while(left-1>=0 && right+1<n && s[left-1]==s[right+1]){
                left--;
                right++;
            }
            int len=right-left+1;
            if(len>maxi){
                maxi=len;
                paliStart=left;
                paliEnd=right;
            }
        }
        // even lengths
        for(int i=0;i<n-1;i++){
            int left=i;
            int right=i+1;
            if(s[left]!=s[right]) continue;
            while(left-1>=0 && right+1<n && s[left-1]==s[right+1]){
                left--;
                right++;
            }
            int len=right-left+1;
            if(len>maxi){
                maxi=len;
                paliStart=left;
                paliEnd=right;
            }
        }
        if(paliStart==-1 && paliEnd==-1) return "";
        return s.substr(paliStart,paliEnd-paliStart+1);
    }
};