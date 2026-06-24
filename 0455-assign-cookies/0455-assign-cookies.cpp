class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int g1=0,s1=0;
        while(g1<g.size() && s1<s.size()){
            if(s[s1]>=g[g1]){
                g1++;
                s1++;
            }
            else s1++;
        }
        return g1;
    }
};