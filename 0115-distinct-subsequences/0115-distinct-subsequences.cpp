class Solution {
private:
    int helper(string &s1,string &s2,int i,int j,vector<vector<int>>&dp){
        if(j<0) return 1;
        if(i<0) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        // match
        if(s1[i]==s2[j]) return dp[i][j]=helper(s1,s2,i-1,j-1,dp)+helper(s1,s2,i-1,j,dp);
        // not match
        return dp[i][j]=helper(s1,s2,i-1,j,dp);
    }
public:
    int numDistinct(string s, string t) {
        vector<vector<int>>dp(s.size(),vector<int>(t.size(),-1));
        int ans=helper(s,t,s.size()-1,t.size()-1,dp);
        return ans;
    }
};