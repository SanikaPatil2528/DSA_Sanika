class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>>pq;
        unordered_map<int,int>mpp;
        for(int num:nums)
            mpp[num]++;
        
        for(auto it:mpp){
            pq.push({it.second,it.first});
            if(pq.size()>k) pq.pop();
        }
        vector<int>ans;
        while(!pq.empty()){
            int num=pq.top().second;
            ans.push_back(num);
            pq.pop();
        }
        return ans;
    }
};