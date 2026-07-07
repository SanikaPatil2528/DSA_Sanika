class Solution {
public:
    bool checkValidString(string s) {
        int n=s.size();
        int mini=0,maxi=0;
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                maxi++;
                mini++;
            }
            else if(s[i]==')'){
                mini=mini-1;
                maxi=maxi-1;
                if(maxi<0) return false;
                mini=max(mini,0);
            }
            else {
                mini=max(mini-1,0);
                maxi=maxi+1;
            }
        }
        if(mini==0) return true;
        return false;
    }
};