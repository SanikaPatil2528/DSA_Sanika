class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char,int>mpp={
            {'I',1},
            {'V',5},
            {'X',10},
            {'L',50},
            {'C',100},
            {'D',500},
            {'M',1000}
        };
        int ans=0;
        for(int i=0;i<s.size()-1;i++){
            int sign=1;
            if(s[i]=='I' && (s[i+1]=='V' || s[i+1]=='X')) sign=-1;
            else if(s[i]=='X' && (s[i+1]=='L' || s[i+1]=='C')) sign=-1;
            else if(s[i]=='C' && (s[i+1]=='D' || s[i+1]=='M')) sign=-1;
            ans+= (mpp[s[i]]*sign);
        }
        ans+=mpp[s[s.size()-1]];
        return ans;
    }
};