class Solution {
public:
    string smallestPalindrome(string s) {
        vector<int>freq(26,0);
        for(char ch:s) freq[ch-'a']++;
        string ansFront="",ansBack="";
        string check="";
        for(int i=0;i<26;i++){
            if(freq[i]==0) continue;
            for(int t=0;t<freq[i]/2;t++){
                char temp='a'+i;
                ansFront+=temp;
                ansBack+=temp;
            }
            char temp='a'+i;
            if(freq[i]%2==1) check+=temp;
        }
        reverse(ansBack.begin(),ansBack.end());
        return ansFront+check+ansBack;
    }
};