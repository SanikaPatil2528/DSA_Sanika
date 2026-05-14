class Solution {
public:
    string removeOuterParentheses(string s) {
        if (s=="") return "";
        string result="";
        int count=0;
        for(char c:s){
            if(c=='('){
                count++;
                if(count>1) result.push_back(c);
            }
            else{
                count--;
                if(count>0) result.push_back(c);
            }
        }

        return result;
    }
};