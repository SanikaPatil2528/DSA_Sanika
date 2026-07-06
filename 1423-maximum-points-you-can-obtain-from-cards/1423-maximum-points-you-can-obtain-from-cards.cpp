class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n=cardPoints.size();
        int lsum=0,rsum=0;
        int maxSum=0;
        for(int i=0;i<k;i++) lsum+=cardPoints[i];
        maxSum=max(maxSum,lsum+rsum);
        for(int i=0;i<k;i++){
            rsum+=cardPoints[n-1-i];
            lsum-=cardPoints[k-1-i];
            maxSum=max(maxSum,lsum+rsum);
        }
        return maxSum;
    }
};