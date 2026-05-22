class Solution {
public:
    int trap(vector<int>& height) {
        int leftMax=height[0];
        int n=height.size();
        vector<int>suffixMax(n);
        suffixMax[n-1]=height[n-1];
        for(int i=n-2;i>=0;i--)
            suffixMax[i]=max(suffixMax[i+1],height[i]);
        int water=0;
        for(int i=0;i<n;i++){
            leftMax=max(leftMax,height[i]);
            if(height[i]<leftMax && height[i]<suffixMax[i]){
                water+=min(leftMax,suffixMax[i])-height[i];
            }
        }
        return water;
    }
};