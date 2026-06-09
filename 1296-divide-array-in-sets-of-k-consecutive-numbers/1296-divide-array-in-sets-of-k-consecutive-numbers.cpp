class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        int n=nums.size();
        if(n%k!=0) return false;
        // val,freq
        map<int,int>freq;
        for(int num:nums)
            freq[num]++;
        
        auto it=freq.begin();
        // loop through all keys in the map
        while(it!=freq.end()){
            // skip cards if already used up
            if(it->second==0){
                it++;
                continue;
            }
            int start=it->first;
            // no. of times we need to form this group
            int count=it->second;

            for(int i=0;i<k;i++){
                // 1,1,1,1,2,2,2,3,3,3 freq of 2 is 3 and of 1 is 4 so one 1 left and group not formed
                if(freq[start+i]<count) return false;
                freq[start+i]-=count;
            }
            it++;
        }
        return true;
    }
};