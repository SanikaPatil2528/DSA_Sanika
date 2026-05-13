class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size()>nums2.size()) return findMedianSortedArrays(nums2,nums1);
        int val=(nums1.size()+nums2.size()+1)/2;
        int total=nums1.size()+nums2.size();
        int low=0,high=nums1.size();
        while(low<=high){
            int cut1=low+(high-low)/2;
            int l1,l2,r1,r2;
            int cut2=val-cut1;
            l1= cut1==0? INT_MIN : nums1[cut1-1];
            l2= cut2==0? INT_MIN : nums2[cut2-1];
            r1= cut1==nums1.size()? INT_MAX : nums1[cut1];
            r2= cut2==nums2.size()? INT_MAX : nums2[cut2];
            if(l1<=r2 && l2<=r1){
                if(total%2==1) return max(l1,l2);
                return ((max(l1,l2)+min(r1,r2))/2.0);
            }
            if(l1>r2) high=cut1-1;
            else low=cut1+1;
        }
        return 0.00;
    }
};