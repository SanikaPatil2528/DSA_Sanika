class Solution {
private:
    int helper(string &s1,string &s2,int i,int j,vector<vector<int>>&dp){
        if(i<0) return j+1;
        if(j<0) return i+1;
        if(dp[i][j]!=-1) return dp[i][j];
        // match
        if(s1[i]==s2[j]) return dp[i][j]=0+helper(s1,s2,i-1,j-1,dp);
        //not match
        int insert=1+helper(s1,s2,i,j-1,dp);
        int deletion=1+helper(s1,s2,i-1,j,dp);
        int replace=1+helper(s1,s2,i-1,j-1,dp);
        return dp[i][j]=min(insert,min(deletion,replace));
    }
public:
    int minDistance(string word1, string word2) {
        vector<vector<int>> dp(word1.size(),vector<int>(word2.size(),-1));
        int ans=helper(word1,word2,word1.size()-1,word2.size()-1,dp);
        return ans;
    }
};