class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        stack<int>st;
        st.push(0);
        int maxi=0;
        for(int i=1;i<n;i++){
            while(!st.empty() && heights[i]<heights[st.top()]){
                int ele=heights[st.top()];
                int nse=i;
                st.pop();
                int pse=st.empty()?-1:st.top();
                int area=ele*(nse-pse-1);
                maxi=max(maxi,area);
            }
            st.push(i);
        }
        while(!st.empty()){
            int ele=heights[st.top()];
            st.pop();
            int nse=n;
            int pse=st.empty()?-1:st.top();
            maxi=max(maxi,ele*(nse-pse-1));
        }
        return maxi;
    }
};