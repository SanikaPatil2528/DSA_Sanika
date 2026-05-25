class Solution {
private:
    vector<int> helper(vector<int>&arr){
        stack<int>st;
        int n=arr.size();
        for(int i=0;i<n;i++){
            // no collision possible
            if(st.empty() || !(st.top()>0 && arr[i]<0)) st.push(arr[i]);
            // collision
            else{
                while(!st.empty() && abs(st.top())<abs(arr[i]) && st.top()>0) 
                    st.pop();
                if(st.empty() || st.top()<0) st.push(arr[i]);
                else if(st.top()==-1*arr[i]) st.pop();
            }
        }
        int s=st.size();
        vector<int>ans(s);
        for(int i=s-1;i>=0;i--){
            ans[i]=st.top();
            st.pop();
        }
        return ans;
    }
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int>ans=helper(asteroids);
        return ans;
    }
};