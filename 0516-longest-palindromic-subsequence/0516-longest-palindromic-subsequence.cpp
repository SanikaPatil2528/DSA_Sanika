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
    int longestPalindromeSubseq(string s) {
        string s1=s;
        string s2;
        for(int i=s.size()-1;i>=0;i--)
            s2+=s[i];
        int n=s.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        int ans=lcs(s1,s2,n-1,n-1,dp);
        return ans;
    }
};