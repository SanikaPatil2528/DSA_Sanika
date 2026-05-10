class Solution {
private:
    long long hoursNeeded(int k,vector<int>&piles){
        long long hours=0;
        int n=piles.size();
        for(int i=0;i<n;i++){
            hours+=ceil((double)piles[i]/k);
        }
        return hours;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n=piles.size();
        int maxEle=piles[0];
        for(int num:piles)
            maxEle=max(maxEle,num);
        int low=1,high=maxEle;
        while(low<=high){
            int mid=low+(high-low)/2;
            long long time=hoursNeeded(mid,piles);
            if(time>h) low=mid+1;
            else high=mid-1;
        }
        return low;
    }
};