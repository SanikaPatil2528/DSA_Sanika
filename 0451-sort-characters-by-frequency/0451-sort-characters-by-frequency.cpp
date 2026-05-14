class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int>mpp;
        int n=s.size();
        for(int i=0;i<n;i++)
            mpp[s[i]]++;
        priority_queue<pair<int,char>>pq;
        for(auto it:mpp)
            pq.push({it.second,it.first});
        string ans="";
        while(!pq.empty()){
            auto [count,letter]=pq.top();
            pq.pop();
            for(int i=0;i<count;i++) 
                ans.push_back(letter);
        }
        return ans;
    }
};