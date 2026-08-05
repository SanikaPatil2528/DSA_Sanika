class Solution {
private:
    int rectangleInHistogram(vector<int>&heights){
        int maxi=0;
        int n=heights.size();
        stack<int>st;
        st.push(0);
        for(int i=1;i<n;i++){
            while(!st.empty() && heights[st.top()]>heights[i]){
                int ele=heights[st.top()];
                st.pop();
                int nse=i;
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
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        vector<int>heights(n,0);
        int ans=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]=='1') heights[j]++;
                else heights[j]=0;
            }
            int area=rectangleInHistogram(heights);
            ans=max(ans,area);
        }
        return ans;
    }
};