class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int>mpp;
        for(char ch:s) mpp[ch]++;
        priority_queue<pair<int,char>>pq;
        for(auto it:mpp){
            pq.push({it.second,it.first});
        }
        string ans="";
        while(!pq.empty()){
            auto [freq,ch]=pq.top();
            pq.pop();
            for(int i=0;i<freq;i++) ans+=ch;
        }
        return ans;
    }
};