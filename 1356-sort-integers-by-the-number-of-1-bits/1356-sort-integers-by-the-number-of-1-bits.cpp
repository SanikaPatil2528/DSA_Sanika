class Solution {
private:
    static int popcount(int x){
        int cnt=0;
        while(x>0){
            if(x & 1) cnt++;
            x=x>>1;
        }
        return cnt;
    }
    static bool compare(int a,int b){
        if(popcount(a)==popcount(b)) return a<b;
        return popcount(a)<popcount(b);
    }

public:
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(),arr.end(),compare);
        return arr;
    }
};