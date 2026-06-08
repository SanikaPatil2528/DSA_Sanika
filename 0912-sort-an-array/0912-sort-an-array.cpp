class Solution {
private:
    void heapify(vector<int>&nums,int idx,int size){
        int largest=idx;
        int left=2*idx+1;
        int right=2*idx+2;

        if(left<size && nums[left]>nums[largest]) largest=left;
        if(right<size && nums[right]>nums[largest]) largest=right;

        if(largest!=idx){
            swap(nums[largest],nums[idx]);
            heapify(nums,largest,size);
        }
    }
    void deletion(vector<int>&nums,int size){
        swap(nums[0],nums[size-1]);
    }
public:
    vector<int> sortArray(vector<int>& nums) {
        // heap sort

        int n=nums.size();
        for(int i=n/2-1;i>=0;i--)
            heapify(nums,i,n);
        int size=nums.size();
        while(size){
            deletion(nums,size);
            size--;
            heapify(nums,0,size);
        }
        return nums;
    }
};