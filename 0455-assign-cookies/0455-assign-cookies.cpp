class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int l=0,r=0;
        int n=g.size(),m=s.size();
        while(l<n && r<m){
            if(s[r]<g[l]) r++;
            else{
                l++;
                r++;
            }
        }
        return l;
    }
};