class Solution {
private:
    bool isPalindrome(string &s){
        for(int i=0;i<s.size()/2;i++){
            if(s[i]!=s[s.size()-1-i]) return false;
        }
        return true;
    }
    int helper(int idx,string &s,vector<int>&dp){
        if(idx==s.size()) return 0;
        if(dp[idx]!=-1) return dp[idx];
        string temp="";
        int mini=1e9;
        for(int j=idx;j<s.size();j++){
            temp+=s[j];
            if(isPalindrome(temp)){
                int cost=1+helper(j+1,s,dp);
                mini=min(mini,cost);
            }
        }
        return dp[idx]=mini;
    }
public:
    int minCut(string s) {
        vector<int>dp(s.size(),-1);
        int ans=helper(0,s,dp);
        return ans-1;
    }
};