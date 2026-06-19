class Solution {
private:
    void merge(int low,int mid,int high,vector<int>&nums,int &cnt){
        vector<int>temp;
        int left=low,right=mid+1;

        while(left<=mid && right<=high){
            if(nums[left]<=1LL*2*nums[right]) left++;
            else{
                cnt+=(mid-left+1);
                right++;
            }
        }
        left=low;
        right=mid+1;

        // MERGE
        while(left<=mid && right<=high){
            if(nums[left]<=nums[right]){
                temp.push_back(nums[left]);
                left++;
            }
            else{
                temp.push_back(nums[right]);
                right++;
            }
        }
        while(left<=mid){
            temp.push_back(nums[left]);
            left++;
        }
        while(right<=high){
            temp.push_back(nums[right]);
            right++;
        }
        for(int i=low;i<=high;i++)
            nums[i]=temp[i-low];
    }
    void mergeSort(int low,int high,vector<int>&nums,int &cnt){
        if(low>=high) return ;
        int mid=low+(high-low)/2;
        mergeSort(low,mid,nums,cnt);
        mergeSort(mid+1,high,nums,cnt);
        merge(low,mid,high,nums,cnt);
    }
public:
    int reversePairs(vector<int>& nums) {
        int n=nums.size();
        int cnt=0;
        mergeSort(0,n-1,nums,cnt);
        return cnt;
    }
};