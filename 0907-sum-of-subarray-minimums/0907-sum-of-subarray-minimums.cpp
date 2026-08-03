class Solution {
private:
    vector<int>NSE(vector<int>&arr){
        vector<int>nse(arr.size());
        stack<int>st;
        for(int i=arr.size()-1;i>=0;i--){
            while(!st.empty() && arr[st.top()]>=arr[i]) st.pop();
            if(st.empty()) nse[i]=arr.size();
            else nse[i]=st.top();
            st.push(i);
        }
        return nse;
    }
    vector<int>PSE(vector<int>&arr){
        vector<int>pse(arr.size());
        stack<int>st;
        for(int i=0;i<arr.size();i++){
            while(!st.empty() && arr[st.top()]>arr[i]) st.pop();
            if(st.empty()) pse[i]=-1;
            else pse[i]=st.top();
            st.push(i);
        }
        return pse;
    }
public:
    const int MOD=1e9+7;

    int sumSubarrayMins(vector<int>& arr) {
        int n=arr.size();
        vector<int>nse=NSE(arr);
        vector<int>pse=PSE(arr);
        long long ans=0;
        for(int i=0;i<n;i++){
            int left=i-pse[i];
            int right=nse[i]-i;
            ans+=(1LL*left*right*arr[i]);
        }
        return ans % MOD;
    }
};