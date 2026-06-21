class Solution {
private:    
    long long timeToEat(int k,vector<int>&piles){
        long long ans=0;
        for(int pile:piles)
            ans+= (pile-1)/k + 1;
        return ans;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxi=-1e9;
        for(int pile:piles)
            maxi=max(maxi,pile);
        int low=1,high=maxi;
        int ans=maxi;
        while(low<=high){
            int mid=low+(high-low)/2;
            long long hoursNeeded=timeToEat(mid,piles);
            if(hoursNeeded<=h) {
                ans=mid;
                high=mid-1;
            }
            else low=mid+1;
        }
        return ans;
    }
};