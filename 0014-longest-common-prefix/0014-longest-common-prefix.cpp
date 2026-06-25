class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        // M1-sort then take lcp of first and last word
        // M2-for each adjacent pair of words take commmon and take common of it with next word
        string common=strs[0];
        for(int i=1;i<strs.size();i++){
            string s1=strs[i];
            int idx1=0,idx2=0;
            string temp="";
            while(idx1<common.size() && idx2<s1.size() && common[idx1]==s1[idx2]){
                temp+=common[idx1];
                idx1++;
                idx2++;
            }
            common=temp;
        }
        return common;
    }
};