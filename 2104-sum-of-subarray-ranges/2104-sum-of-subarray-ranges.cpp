class Solution {
private:
    vector<int>NGE(vector<int>&nums){
        vector<int>nge(nums.size());
        stack<int>st;
        for(int i=nums.size()-1;i>=0;i--){
            while(!st.empty() && nums[st.top()]<=nums[i]) st.pop();
            if(st.empty()) nge[i]=nums.size();
            else nge[i]=st.top();
            st.push(i);
        }
        return nge;
    }
    vector<int>NSE(vector<int>&nums){
        vector<int>nse(nums.size());
        stack<int>st;
        for(int i=nums.size()-1;i>=0;i--){
            while(!st.empty() && nums[st.top()]>=nums[i]) st.pop();
            if(st.empty()) nse[i]=nums.size();
            else nse[i]=st.top();
            st.push(i);
        }
        return nse;
    }
    vector<int>PSE(vector<int>&nums){
        vector<int>pse(nums.size());
        stack<int>st;
        for(int i=0;i<nums.size();i++){
            while(!st.empty() && nums[st.top()]>nums[i]) st.pop();
            if(st.empty()) pse[i]=-1;
            else pse[i]=st.top();
            st.push(i);
        }
        return pse;
    }
    vector<int>PGE(vector<int>&nums){
        vector<int>pge(nums.size());
        stack<int>st;
        for(int i=0;i<nums.size();i++){
            while(!st.empty() && nums[st.top()]<nums[i]) st.pop();
            if(st.empty()) pge[i]=-1;
            else pge[i]=st.top();
            st.push(i);
        }
        return pge;
    }
    long long subArrMaxi(vector<int>&nums){
        vector<int>nge=NGE(nums);
        vector<int>pge=PGE(nums);
        long long maxi=0;
        for(int i=0;i<nums.size();i++){
            int left=i-pge[i];
            int right=nge[i]-i;
            maxi+=(1LL*left*right*nums[i]);
        }
        return maxi;
    }
    long long subArrMini(vector<int>&nums){
        vector<int>nse=NSE(nums);
        vector<int>pse=PSE(nums);
        long long mini=0;
        for(int i=0;i<nums.size();i++){
            int left=i-pse[i];
            int right=nse[i]-i;
            mini+=(1LL*left*right*nums[i]);
        }
        return mini;
    }
public:
    long long subArrayRanges(vector<int>& nums) {
        long long maxiSum=subArrMaxi(nums);
        long long miniSum=subArrMini(nums);
        return maxiSum-miniSum;
    }
};