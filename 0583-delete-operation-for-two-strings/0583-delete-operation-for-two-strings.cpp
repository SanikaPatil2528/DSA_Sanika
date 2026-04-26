class Solution {
private:
    int lcs(string &s1,string &s2,int idx1,int idx2,vector<vector<int>>&dp){
        if(idx1<0 || idx2<0) return 0;
        if(dp[idx1][idx2]!=-1) return dp[idx1][idx2];

        // match
        if(s1[idx1]==s2[idx2])
            return dp[idx1][idx2]= 1 + lcs(s1,s2,idx1-1,idx2-1,dp);
        // not match
        return dp[idx1][idx2]= 0 + max(lcs(s1,s2,idx1-1,idx2,dp), lcs(s1,s2,idx1,idx2-1,dp));
    }
public:
    int minDistance(string word1, string word2) {
        vector<vector<int>>dp(word1.size(),vector<int>(word2.size(),-1));
        int ans=lcs(word1,word2,word1.size()-1,word2.size()-1,dp);
        int count1,count2;
        count1=word1.size()-ans;
        count2=word2.size()-ans;
        return count1+count2;
    }
};