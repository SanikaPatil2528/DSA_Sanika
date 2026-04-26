class Solution {
private: 
    string lcs(string &s1,string &s2){
        vector<vector<int>>dp(s1.size()+1,vector<int>(s2.size()+1,0));
        for(int i=1;i<=s1.size();i++){
            for(int j=1;j<=s2.size();j++){
                //match
                if(s1[i-1]==s2[j-1]) dp[i][j]=1+dp[i-1][j-1];
                // not match
                else dp[i][j]=0+ max(dp[i-1][j],dp[i][j-1]);
            }
        }
        string s;
        int i=s1.size(), j=s2.size();
        while(i>0 && j>0){
            if (s1[i-1]==s2[j-1]){
                s+=s1[i-1];
                i--;j--;
            }
            else if(dp[i-1][j]>dp[i][j-1]){
                s+=s1[i-1];
                i--;
            } 
            else{
                s+=s2[j-1];
                j--;
            } 
        }
        while(j>0){
            s+=s2[j-1];
            j--;
        }
        while(i>0){
            s+=s1[i-1];
            i--;
        }
        reverse(s.begin(),s.end());
        return s;
    }
public:
    string shortestCommonSupersequence(string str1, string str2) {
        string s=str1+str2;
        string ans=lcs(str1,str2);
        return ans;
    }
};