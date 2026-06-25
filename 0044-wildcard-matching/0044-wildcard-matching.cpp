class Solution {
private:
    bool helper(int i,int j,string &s,string &p,vector<vector<int>>&dp){
        if(i==s.size() && j==p.size()) return dp[i][j]=true;
        if(j==p.size() && i<s.size()) return dp[i][j]=false;
        if(i==s.size() && j<p.size()){
            for(int k=j;k<p.size();k++)
                if(p[k]!='*') return dp[i][j]=false;
            return dp[i][j]=true;
        }
        if(dp[i][j]!=-1) return dp[i][j];

        if(s[i]==p[j]) return dp[i][j]=helper(i+1,j+1,s,p,dp);
        if(p[j]=='?') return dp[i][j]=helper(i+1,j+1,s,p,dp);
        if(p[j]=='*') return dp[i][j]=(helper(i,j+1,s,p,dp) || helper(i+1,j,s,p,dp));
        return false;
    }
public:
    bool isMatch(string s, string p) {
        vector<vector<int>>dp(s.size()+1,vector<int>(p.size()+1,-1));
        bool ans=helper(0,0,s,p,dp);
        return ans;
    }
};