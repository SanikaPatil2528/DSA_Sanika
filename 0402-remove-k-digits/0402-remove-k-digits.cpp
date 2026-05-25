class Solution {
public:
    string removeKdigits(string num, int k) {
        int n=num.size();
        if(k==n) return "0";
        stack<int>st;
        int i=0;
        while(i<n){
            while(k && !st.empty() && num[i]-'0'<st.top()){
                st.pop();
                k--;
            }
            st.push(num[i]-'0');
            i++;
        }
        while(k--)
            st.pop();
        string ans="";
        while(!st.empty()){
            ans+=to_string(st.top());
            st.pop();
        }
        string digit="";
        int s=ans.size()-1;
        while(s>=0 && ans[s]=='0')
            s--;
        while(s>=0){
            digit+=ans[s];
            s--;
        }
        if(digit=="") return "0";

        return digit;
    }
};