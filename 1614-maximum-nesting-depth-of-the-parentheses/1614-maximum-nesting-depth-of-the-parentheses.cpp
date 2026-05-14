class Solution {
public:
    int maxDepth(string s) {
        int count=0,maxCount=-1;
        int n=s.size();
        for(int i=0;i<n;i++){
            if(s[i]=='(') count++;
            maxCount=max(maxCount,count);
            if(s[i]==')') count--;
        }
        return maxCount;
    }
};