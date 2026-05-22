class Solution {
const int mod=1e9+7;
private:
    vector<int>findNSE(vector<int>&arr){
        int n=arr.size();
        vector<int>nse(n);
        stack<int>st;
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && arr[i]<=arr[st.top()])
                st.pop();
            nse[i]=st.empty()?n:st.top();
            st.push(i); 
        }
        return nse;
    }
    vector<int>findPSE(vector<int>&arr){
        int n=arr.size();
        vector<int>pse(n);
        stack<int>st;
        for(int i=0;i<n;i++){
            while(!st.empty() && arr[i]<arr[st.top()])
                st.pop();
            pse[i]=st.empty()?-1:st.top();
            st.push(i);
        }
        return pse;
    }
public:
    int sumSubarrayMins(vector<int>& arr) {
        int ans=0;
        int n=arr.size();
        vector<int>nse=findNSE(arr);
        vector<int>pse=findPSE(arr);
        for(int i=0;i<n;i++){
            int left=i-pse[i];
            int right=nse[i]-i;
            long long occurences=(long long)left*right;
            ans=(ans+arr[i]*occurences)%mod;
        }
        return ans;
    }
};