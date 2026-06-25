class Solution {
private:
    int helper(int i,int j,string &s1,string &s2,vector<vector<int>>&dp){
        if(i>=s1.size() || j>=s2.size()) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(s1[i]==s2[j]) return dp[i][j]=1+helper(i+1,j+1,s1,s2,dp);
        else return dp[i][j]=max(helper(i+1,j,s1,s2,dp),helper(i,j+1,s1,s2,dp));
    }
public:
    int longestPalindromeSubseq(string s) {
        string r=s;
        reverse(r.begin(),r.end());
        vector<vector<int>>dp(s.size(),vector<int>(s.size(),-1));
        int ans=helper(0,0,s,r,dp);
        return ans;
    }
};