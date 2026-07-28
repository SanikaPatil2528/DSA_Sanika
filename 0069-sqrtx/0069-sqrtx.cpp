class Solution {
public:
    int mySqrt(int x) {
        int low=1,high=x;
        while(low<=high){
            int mid=low+(high-low)/2;
            long long check=(long long)mid*mid;
            if(check==x) return mid;
            else if(check>x) high=mid-1;
            else low=mid+1;
        }
        return high;
    }
};