class Solution {
public:
    int characterReplacement(string s, int k) {
        int n=s.size();
        vector<int>freq(26,0);
        int l=0,r=0;
        int maxFreq=0,maxLen=0;
        while(r<n){
            freq[s[r]-'A']++;
            maxFreq=max(maxFreq,freq[s[r]-'A']);
            int changes=(r-l+1)-maxFreq;
            if(changes<=k) maxLen=max(maxLen,r-l+1);
            else{
                freq[s[l]-'A']--;
                l++;
            }
            r++;
        }
        return maxLen;
    }
};