class Solution {
public:
    int beautySum(string s) {
        int ans=0;
        int n=s.size();
        for(int start=0;start<n;start++){
            vector<int>freq(26,0);
            for(int end=start;end<n;end++){
                freq[s[end]-'a']++;
                int mini=1e9,maxi=-1e9;
                for(int num:freq){
                    if(num==0) continue;
                    mini=min(mini,num);
                    maxi=max(maxi,num);
                }
                ans+=(maxi-mini);
            }
        }
        return ans;
    }
};