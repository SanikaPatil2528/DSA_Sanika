class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int>st;
        int n=heights.size();
        st.push(0);
        int maxi=0;
        for(int i=1;i<n;i++){
            while(!st.empty() && heights[st.top()]>heights[i]){
                int ht=heights[st.top()];
                st.pop();
                int pse=st.empty()?-1:st.top();
                int area=ht*(i-pse-1);
                maxi=max(maxi,area);
            }
            st.push(i);
        }
        while(!st.empty()){
            int nse=n;
            int h=heights[st.top()];
            st.pop();
            int ps=st.empty()?-1:st.top();
            maxi=max(maxi,h*(nse-ps-1));
        }
        return maxi;
    }
};