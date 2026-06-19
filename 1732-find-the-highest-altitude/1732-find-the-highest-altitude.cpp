class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int last=0;
        int maxi=last;
        int n=gain.size();
        for(int i=0;i<n;i++){
            int curr=gain[i]+last;
            maxi=max(maxi,curr);
            last=curr;
        }
        return maxi;
    }
};