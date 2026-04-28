class Solution {
public:
    static bool comp(string &s1,string &s2){
        return s1.size()<s2.size();
    }

    bool compareWords(string s1,string &s2){
        if(s1.size()+1 != s2.size()) return false;
        int idx1=0,idx2=0;
        int count=0;
        while(idx1<s1.size() && idx2<s2.size()){
            if(s1[idx1]==s2[idx2]){
                idx1++;
                idx2++;
            }
            else{
                idx2++;
                count++;
                if (count>1) return false;
            }
        }
        if(idx1==s1.size()) return true;
        return false;
    }

    int longestStrChain(vector<string>& words) {
        sort(words.begin(),words.end(),comp);
        vector<int>dp(words.size(),1);

        int maxi=1;
        for(int i=1;i<words.size();i++){
            for(int j=0;j<i;j++){
                if(compareWords(words[j],words[i]) && dp[i]<dp[j]+1){
                    dp[i]=dp[j]+1;
                }
            }
            maxi=max(maxi,dp[i]);
        }
        return maxi;
    }
};