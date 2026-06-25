class Solution {
private:
    int helper(int i,int j,string &s,string &t,vector<vector<int>>&dp){
        if(j==t.size()) return 1;
        if(i==s.size()) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(s[i]!=t[j]) return dp[i][j]=helper(i+1,j,s,t,dp);
        else {
            // take, not take
            int take=helper(i+1,j+1,s,t,dp);
            int notTake=helper(i+1,j,s,t,dp);
            return dp[i][j]=take+notTake;
        }
    }
public:
    int numDistinct(string s, string t) {
        vector<vector<int>>dp(s.size(),vector<int>(t.size(),-1));
        int ans=helper(0,0,s,t,dp);
        return ans;
    }
};