class Solution {
private:
    int helper(int idx1,int idx2,string word1,string word2,vector<vector<int>>&dp){
        if(idx1==word1.size()) return word2.size()-idx2;
        if(idx2==word2.size()) return word1.size()-idx1;
        if(dp[idx1][idx2]!=-1) return dp[idx1][idx2];

        if(word1[idx1]==word2[idx2]) return dp[idx1][idx2]=helper(idx1+1,idx2+1,word1,word2,dp);
        int deletion=1+helper(idx1+1,idx2,word1,word2,dp);
        int insertion=1+helper(idx1,idx2+1,word1,word2,dp);
        int replace=1+helper(idx1+1,idx2+1,word1,word2,dp);
        return dp[idx1][idx2]=min({deletion,insertion,replace});
    }
public:
    int minDistance(string word1, string word2) {
        // vector<vector<int>>dp(word1.size(),vector<int>(word2.size(),-1));
        // int ans=helper(0,0,word1,word2,dp);
        // return ans;

        // TABULATION
        vector<vector<int>>dp(word1.size()+1,vector<int>(word2.size()+1,0));
        for(int i=0;i<=word2.size();i++)
            dp[word1.size()][i]=word2.size()-i;
        for(int i=0;i<=word1.size();i++)
            dp[i][word2.size()]=word1.size()-i;
        for(int idx1=word1.size()-1;idx1>=0;idx1--){
            for(int idx2=word2.size()-1;idx2>=0;idx2--){
                if(word1[idx1]==word2[idx2]) dp[idx1][idx2]=dp[idx1+1][idx2+1];
                else{
                    int deletion=1+dp[idx1+1][idx2];
                    int insertion=1+dp[idx1][idx2+1];
                    int replace=1+dp[idx1+1][idx2+1];
                    dp[idx1][idx2]=min({deletion,insertion,replace});
                }
            }
        }
        return dp[0][0];
    }
};