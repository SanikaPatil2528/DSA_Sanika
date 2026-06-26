class Solution {
public:
    bool rotateString(string s, string goal) {
        s=s+s;
        if(s.find(goal)!=string::npos) return true;
        return false;
    }
};