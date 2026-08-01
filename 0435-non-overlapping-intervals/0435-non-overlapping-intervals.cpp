class Solution {
private:
    static bool comp(vector<int>&a,vector<int>&b){
        return a[1]<b[1];
    }
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if(intervals.size()==1) return 0;
        sort(intervals.begin(),intervals.end(),comp);
        int cnt=0;
        int finish=intervals[0][1];
        for(int i=1;i<intervals.size();i++){
            if(intervals[i][0]<finish) cnt++;
            else finish=intervals[i][1];
        }
        return cnt;
    }
};