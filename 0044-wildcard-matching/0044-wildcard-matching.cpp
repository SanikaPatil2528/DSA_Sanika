class Solution {
private:
    bool helper(string &s1,string &s2,int i,int j,vector<vector<int>>&dp){
        if (i<0 && j<0) return true;
        if (j<0 && i>=0) return false;
        if(i<0){
            for(int k=0;k<=j;k++){
                if (s2[k]!='*') return false;
            }
            return true;
        }
        if (dp[i][j]!=-1) return dp[i][j];
        //match
        if(s1[i]==s2[j] || s2[j]=='?') return dp[i][j]=helper(s1,s2,i-1,j-1,dp);
        //not match
        else if (s2[j]=='*') return dp[i][j]=(helper(s1,s2,i,j-1,dp) || helper(s1,s2,i-1,j,dp));
        else return false;
    }
public:
    bool isMatch(string s, string p) {
        vector<vector<int>>dp(s.size(),vector<int>(p.size(),-1));
        bool ans=helper(s,p,s.size()-1,p.size()-1,dp);
        return ans;
    }
};