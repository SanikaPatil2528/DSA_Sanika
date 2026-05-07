class Solution {
private:
    void merge(vector<int>&arr,int low,int mid,int high){
        vector<int>temp;
        int left=low;
        int right=mid+1;
        while(left<=mid && right<=high){
            if(arr[left]<=arr[right]){
                temp.push_back(arr[left]);
                left++;
            }
            else{
                temp.push_back(arr[right]);
                right++;
            }
        }
        while(left<=mid){
            temp.push_back(arr[left]);
            left++;
        }
        while(right<=high){
            temp.push_back(arr[right]);
            right++;
        }
        for(int i=low;i<=high;i++)
            arr[i]=temp[i-low];
    }

    void countPairs(vector<int>&arr,int low,int mid,int high,int &cnt){
        int left=low,right=mid+1;
        while(left<=mid && right<=high){
            if(arr[left]>(long long)2*arr[right]){
                cnt+=mid-left+1;
                right++;
            }
            else left++;
        }
    }

    void mergeSort(vector<int>&arr,int low,int high,int &cnt){
        if(low>=high) return;
        int mid=(low+high)/2;
        mergeSort(arr,low,mid,cnt);
        mergeSort(arr,mid+1,high,cnt);
        countPairs(arr,low,mid,high,cnt);
        merge(arr,low,mid,high);
    }
public:
    int reversePairs(vector<int>& nums) {
        int cnt=0;
        mergeSort(nums,0,nums.size()-1,cnt);
        return cnt;
    }
};