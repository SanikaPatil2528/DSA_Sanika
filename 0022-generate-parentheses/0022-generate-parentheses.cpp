class Solution {
private:
    void helper(string curr,int open,int close,int n,vector<string>&ans){
        if(curr.size()==2*n) ans.push_back(curr);
        else{
            if(open<n) helper(curr+"(",open+1,close,n,ans);
            if(close<open) helper(curr+")",open,close+1,n,ans);
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        int open=0,close=0;
        string curr="";
        helper(curr,open,close,n,ans);
        return ans;
    }
};