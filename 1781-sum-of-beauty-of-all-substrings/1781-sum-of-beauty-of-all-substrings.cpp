class Solution {
public:
    int beautySum(string s) {
        int n=s.size();
        int beautySum=0;
        for(int i=0;i<n;i++){
            vector<int>freq(26,0);
            for(int j=i;j<n;j++){
                freq[s[j]-'a']++;
                int maxFreq=-1,minFreq=INT_MAX;
                for(int t=0;t<26;t++){
                    if(freq[t]!=0){
                        maxFreq=max(maxFreq,freq[t]);
                        minFreq=min(minFreq,freq[t]);
                    }
                }
                beautySum+=(maxFreq-minFreq);
            }
        }
        return beautySum;
    }
};