class Solution {
private:
    vector<int>helper(vector<int>&arr){
        stack<int>st;
        int n=arr.size();
        for(int i=0;i<n;i++){
            if(st.empty() || !(st.top()>0 && arr[i]<0)) st.push(arr[i]);
            else{
                while(!st.empty() && st.top()>0 && abs(st.top())<abs(arr[i])) st.pop();
                if(st.empty() || st.top()<0) st.push(arr[i]);
                else if(st.top()==-1*arr[i]) st.pop();
            }
        }
        vector<int>ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int>ans=helper(asteroids);
        return ans;
    }
};