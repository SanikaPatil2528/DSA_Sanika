class Solution {
private:
    vector<int> NGE(vector<int>&nums){
        stack<int>st;
        int n=nums.size();
        vector<int>ans(n);
        ans[n-1]=n;
        st.push(n-1);
        for(int i=n-2;i>=0;i--){
            while(!st.empty() && nums[st.top()]<=nums[i])
                st.pop();
            if(st.empty()) ans[i]=n;
            else ans[i]=st.top();
            st.push(i);
        }
        return ans;
    }
    vector<int> NSE(vector<int>&nums){
        stack<int>st;
        int n=nums.size();
        vector<int>ans(n);
        ans[n-1]=n;
        st.push(n-1);
        for(int i=n-2;i>=0;i--){
            while(!st.empty() && nums[st.top()]>=nums[i])
                st.pop();
            if(st.empty()) ans[i]=n;
            else ans[i]=st.top();
            st.push(i);
        }
        return ans;
    }
    vector<int> PSE(vector<int>&nums){
        int n=nums.size();
        stack<int>st;
        vector<int>ans(n);
        ans[0]=-1;
        st.push(0);
        for(int i=1;i<n;i++){
            while(!st.empty() && nums[st.top()]>nums[i])
                st.pop();
            if(st.empty()) ans[i]=-1;
            else ans[i]=st.top();
            st.push(i);
        }
        return ans;
    }
    vector<int>PGE(vector<int>&nums){
        int n=nums.size();
        vector<int>ans(n);
        ans[0]=-1;
        stack<int>st;
        st.push(0);
        for(int i=1;i<n;i++){
            while(!st.empty() && nums[st.top()]<nums[i])
                st.pop();
            if(st.empty()) ans[i]=-1;
            else ans[i]=st.top();
            st.push(i);
        }
        return ans;
    }
    long long getMaxiSum(vector<int>&nums){
        long long tot=0;
        int n=nums.size();
        vector<int>nge=NGE(nums);
        vector<int>pge=PGE(nums);
        for(int i=0;i<n;i++){
            int left=i-pge[i];
            int right=nge[i]-i;
            long long occur=(long long)left*right;
            tot+=nums[i]*occur;
        }
        return tot;
    }
    long long getMiniSum(vector<int>&nums){
        long long tot=0;
        vector<int>nse=NSE(nums);
        vector<int>pse=PSE(nums);
        int n=nums.size();
        for(int i=0;i<n;i++){
            int left=i-pse[i];
            int right=nse[i]-i;
            long long occur=(long long)left*right;
            tot+=occur*nums[i];
        }
        return tot;
    }
public:
    long long subArrayRanges(vector<int>& nums) {
        long long larg=getMaxiSum(nums);
        long long small=getMiniSum(nums);
        return larg-small;
    }
};