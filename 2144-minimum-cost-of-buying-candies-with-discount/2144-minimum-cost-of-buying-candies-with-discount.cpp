class Solution {
public:
    int minimumCost(vector<int>& cost) {
        sort(cost.begin(),cost.end());
        reverse(cost.begin(),cost.end());
        int n=cost.size();
        int sumi=0;
        int cnt=0;
        for(int i=0;i<n;i++){
            cnt++;
            if(cnt==3){
                cnt=0;
                continue;
            }
            sumi+=cost[i];
        }
        return sumi;
    }
};