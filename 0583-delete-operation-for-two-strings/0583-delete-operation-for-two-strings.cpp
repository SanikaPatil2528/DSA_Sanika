class Solution {
private:
    int helper(int i,int j,string s1,string s2,vector<vector<int>>&dp){
        if(i>=s1.size() || j>=s2.size()) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(s1[i]==s2[j]) return dp[i][j]=1+helper(i+1,j+1,s1,s2,dp);
        else return dp[i][j]=max(helper(i+1,j,s1,s2,dp),helper(i,j+1,s1,s2,dp));
    }
    int lcs(string str1, string str2) {
        vector<vector<int>>dp(str1.size(),vector<int>(str2.size(),-1));
        int ans=helper(0,0,str1,str2,dp);
        return ans;
    }
public:
    int minDistance(string word1, string word2) {
        int l=lcs(word1,word2);
        int rem1=word1.size()-l;
        int rem2=word2.size()-l;
        return rem1+rem2;
    }
};