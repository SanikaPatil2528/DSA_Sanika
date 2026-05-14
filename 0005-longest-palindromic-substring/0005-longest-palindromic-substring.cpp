class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.size();
        int maxLen=1;
        int start=0;
        // odd lengths
        for(int i=1;i<n-1;i++){
            int len=1;
            int left=i-1,right=i+1;
            while(left>=0 && right<n && s[left]==s[right]){
                len+=2;
                if(len>maxLen){
                    maxLen=len;
                    start=left;
                }
                left--;right++;
            }
        }
        // even lengths
        for(int i=0;i<n-1;i++){
            if(s[i]==s[i+1]){
                int len=2;
                int left=i-1,right=i+2;
                    while(left>=0 && right<n && s[left]==s[right]){
                        len+=2;
                        left--;right++;
                    }
                    if(len>maxLen){
                        maxLen=len;
                        start=left+1;
                    }
            }
        }

        return s.substr(start,maxLen);
    }
};