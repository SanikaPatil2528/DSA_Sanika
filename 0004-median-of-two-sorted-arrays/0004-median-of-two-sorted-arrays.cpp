class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m=nums1.size();
        int n=nums2.size();
        if(m>n) return findMedianSortedArrays(nums2,nums1);
        int total=m+n;
        int val=(m+n+1)/2;
        int low=0,high=m;

        while(low<=high){
            int cut1=low+(high-low)/2;
            int cut2=val-cut1;
            double l1=cut1==0?INT_MIN:nums1[cut1-1];
            double l2=cut2==0?INT_MIN:nums2[cut2-1];
            double r1=cut1==m?INT_MAX:nums1[cut1];
            double r2=cut2==n?INT_MAX:nums2[cut2];

            if(l1<=r2 && l2<=r1){
                if(total%2==1) return max(l1,l2);
                return (max(l1,l2)+min(r1,r2))/2;
            }
            if(l1>r2) high=cut1-1;
            else low=cut1+1;
        }
        return 0.00;
    }
};