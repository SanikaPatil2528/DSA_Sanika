class Solution {
private:
    bool isPalindrome(string &s){
        int i=0,j=s.size()-1;
        while(i<j){
            if(s[i]!=s[j]) return false;
            i++;j--;
        }
        return true;
    }

    int helper(int i,string &s,int n,vector<int>&dp){
        if(i==n) return 0;
        if(dp[i]!=-1) return dp[i];
        string temp="";
        int mini=1e9;
        for(int j=i;j<n;j++){
            temp+=s[j];
            if(isPalindrome(temp)){
                int cost=1+helper(j+1,s,n,dp);
                mini=min(mini,cost);
            }
        }
        return dp[i]=mini;
    }
public:
    int minCut(string s) {
        int n=s.size();
        vector<int>dp(n,-1);
        int ans=helper(0,s,n,dp);
        return ans-1;
    }
};