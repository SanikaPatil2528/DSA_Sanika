class Solution {
private:
    int getDays(int wt,vector<int>&weights){
        int days=0,w=0;
        int n=weights.size();
        int idx=0;
        while(idx<n){
            while(idx<n && w+weights[idx]<=wt){
                w+=weights[idx];
                idx++;
            }
            days++;
            w=0;
        }
        return days;
    }
public:
    int shipWithinDays(vector<int>& weights, int days) {
        long long sum=0;
        int maxEle=-1;
        for(int weight:weights){
            sum+=weight;
            maxEle=max(maxEle,weight);
        }
        int low=maxEle,high=sum;
        while(low<=high){
            int mid=low+(high-low)/2;
            int daysNeeded=getDays(mid,weights);
            if(daysNeeded>days) low=mid+1;
            else high=mid-1;
        }
        return low;
    }
};