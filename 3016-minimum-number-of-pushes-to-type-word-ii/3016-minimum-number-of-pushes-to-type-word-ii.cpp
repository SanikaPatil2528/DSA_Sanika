class Solution {
public:
    int minimumPushes(string word) {
     vector<int>freq(26,0);
        for(char ch:word) freq[ch-'a']++;
        priority_queue<pair<int,char>>pq;
        for(int i=0;i<26;i++) pq.push({freq[i],char('a'+i)});
        unordered_map<char,int>mpp;
        for(int i=0;i<8;i++){
            auto [f,ch]=pq.top();
            pq.pop();
            mpp[ch]=1;
        }
        for(int i=0;i<8;i++){
            auto [f,ch]=pq.top();
            pq.pop();
            mpp[ch]=2;
        }
        for(int i=0;i<8;i++){
            auto [f,ch]=pq.top();
            pq.pop();
            mpp[ch]=3;
        }
        for(int i=0;i<2;i++){
            auto [f,ch]=pq.top();
            pq.pop();
            mpp[ch]=4;
        }

        int ans=0;
        for(char ch:word) ans+=mpp[ch];
        return ans;
    }
};