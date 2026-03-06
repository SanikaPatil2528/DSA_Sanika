class Solution {
private:
    int count(int n,vector<int>&steps){
        if(n==0) return 1;
        if(n==1) return 1;
        if(steps[n]!=-1) return steps[n];
        int left=count(n-1,steps);
        int right=count(n-2,steps);
        return steps[n]=left+right;
    }
public:
    int climbStairs(int n) {
        vector<int>steps(n+1,-1);
        return count(n,steps);
    }
};