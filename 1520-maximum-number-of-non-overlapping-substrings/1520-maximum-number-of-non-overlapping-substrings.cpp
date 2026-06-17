class Solution {
private:
    static bool comp(vector<int>&a,vector<int>&b){
        return a[1]<b[1];
    }
public:
    vector<string> maxNumOfSubstrings(string s) {
        int n=s.size();
        vector<int>start(26,n);
        vector<int>end(26,-1);

        for(int i=0;i<n;i++){
            start[s[i]-'a']=min(start[s[i]-'a'],i);
            end[s[i]-'a']=max(end[s[i]-'a'],i);
        }

        vector<vector<int>>intervals;
        for(int i=0;i<26;i++){
            int l=start[i],r=end[i]; // curr interval
            if(r==-1) continue;
            int starting=l;
            for(int j=l;j<=r;j++){
                if(start[s[j]-'a']<l) {
                    starting=-1;
                    break; // curr interval discarded
                }
                if(end[s[j]-'a']>r) r=max(r,end[s[j]-'a']);
            }
            if(starting==-1) continue;
            intervals.push_back({starting,r});
        }

        sort(intervals.begin(),intervals.end(),comp);
        vector<string>ans;
        int prevEnd=-1;
        for(auto it:intervals){
            if(it[0]>prevEnd){
                ans.push_back(s.substr(it[0],it[1]-it[0]+1));
                prevEnd=it[1];
            }
        }

        return ans;
    }
};