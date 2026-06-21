class Solution {
private:    
    int getBouquets(int day,vector<int>&bloomDay,int k){
        int b=0;
        int idx=0;
        int cnt=0;
        while(idx<bloomDay.size()){
            while(idx<bloomDay.size() && bloomDay[idx]<=day){
                cnt++;
                if(cnt==k) {
                    b++;
                    break;
                }
                idx++;
            }
            cnt=0;
            idx++;
        }
        return b;
    }
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n=bloomDay.size();
        if(n/k < m) return -1;
        int maxi=-1e9;
        for(int bloom:bloomDay)
            maxi=max(maxi,bloom);
        
        int ans=maxi;
        int low=1,high=maxi;
        while(low<=high){
            int mid=low+(high-low)/2;
            int b=getBouquets(mid,bloomDay,k);
            if(b>=m){
                ans=mid;
                high=mid-1;
            }
            else low=mid+1;
        }
        return ans;
    }
};