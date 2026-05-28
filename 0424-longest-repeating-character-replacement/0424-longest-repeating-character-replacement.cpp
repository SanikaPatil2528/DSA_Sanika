class Solution {
public:
    int characterReplacement(string s, int k) {
        int n=s.size();
        unordered_map<char,int>mpp;
        int l=0,r=0;
        int maxLen=0;
        int maxFreq=0;
        while(r<n){
            mpp[s[r]]++;
            maxFreq=max(maxFreq,mpp[s[r]]);
            int len=r-l+1;
            if(len-maxFreq<=k) maxLen=max(maxLen,len);
            else{
                mpp[s[l]]--;
                l++;
            }
            r++;
        }
        return maxLen;
    }
};