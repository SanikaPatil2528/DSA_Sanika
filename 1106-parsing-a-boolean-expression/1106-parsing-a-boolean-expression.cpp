class Solution {
public:
    bool parseBoolExpr(string expression) {
        int n=expression.size();
        stack<char>st;
        for(int i=0;i<n;i++){
            if(expression[i]!=')') st.push(expression[i]);
            else{
                bool hasTrue=false;
                bool hasFalse=false;
                while(st.top()!='('){
                    if(st.top()=='t') hasTrue=true;
                    else if(st.top()=='f') hasFalse=true;
                    st.pop();
                }
                st.pop();
                char op=st.top();
                st.pop();
                if(op=='!'){
                    if(hasTrue) st.push('f');
                    else if(hasFalse) st.push('t');
                }
                else if(op=='&'){
                    if(hasFalse) st.push('f');
                    else st.push('t');
                }
                else if(op=='|'){
                    if(hasTrue) st.push('t');
                    else st.push('f');
                }
            } 
        }
        if(st.top()=='t') return true;
        return false;
    }
};